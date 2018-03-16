#include "timer_event_loop.h"
#include <sys/eventfd.h>
#include "sapper.h"
//#include "epoller.h"
#include "common.hpp"
#include "socket_util.h"
#include <sys/types.h>
//#include <boost/bind.hpp>
#include "socket_util.h"
#include <string>
#include <string.h>
#include <iostream>

#define TIMER_DEFAULT_INTERNAL 20
#define TIMER_INFINITE_INTERNAL -1

namespace Elixir{

TimerEventLoop::TimerEventLoop(const Socket& socket)
	:_wakeup_fd(eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK)),
	_quit(true),
	_looping(false),
	_poller(Creator<EPoller>::Create()),
	_is_init(false),
	_timeout(TIMER_INFINITE_INTERNAL),
	_socket(socket)
{
	//_socket = socket;
	//init();
}

int TimerEventLoop::handle_accept()
{
	IpAddress ipaddr;
	bzero(&ipaddr,sizeof(ipaddr));
	int connfd = _socket.accept(ipaddr);
	SapperPtr sapper = Creator<Sapper>::Create(connfd, shared_from_this());
	sapper->focusRead();
	sapper->focusWrite();
	Sapper::CallBackHandler cbr = boost::bind(&TimerEventLoop::handle_receive, this, sapper);
	Sapper::CallBackHandler cbw = boost::bind(&TimerEventLoop::handle_write, this, sapper);
	sapper->setReadHandler(cbr);
	sapper->setWriteHandler(cbw);
	return 0;
}

int TimerEventLoop::handle_receive(SapperPtr sapper)
{
	std::cout << "data arrive, fd is " << sapper->fd() << std::endl;
	char buff[1024];
	bzero(&buff, sizeof(buff));
	SocketUtil::Read(sapper->fd(), (void*)&buff, 1023);
	std::string str((char*)&buff);
	std::cout << "data is : " << str << std::endl;
	return 0;
}

int TimerEventLoop::handle_write(SapperPtr sapper)
{
	std::cout << "data send, fd is " << sapper->fd() << std::endl;
	return 0;
}

void TimerEventLoop::init()
{
	SapperPtr sapper = Creator<Sapper>::Create(_wakeup_fd, shared_from_this());
	sapper->focusRead();
	sapper->setReadHandler(boost::bind(&SocketUtil::Read, _wakeup_fd, &_wakeup_read, sizeof(_wakeup_read)));

	SapperPtr sapptor = Creator<Sapper>::Create(_socket.fd(), shared_from_this());
	sapptor->focusRead();
	sapptor->setReadHandler(boost::bind(&TimerEventLoop::handle_accept,this));


}

void TimerEventLoop::loop()
{
	if (!_is_init)
	{
		init();
		_is_init = true;
	}
	_quit = false;
	_looping = true;
	TimeEpoch time;
	while (!_quit && _poller)
	{
		_activeSapper.clear();
		time = _poller->poll(_timeout, _activeSapper);
		
		for (int i = 0; i < _activeSapper.size(); ++i)
		{
			int res = _activeSapper[i]->handleEvent(time);
			if (res == SAPPER::OVER)
			{
				removeSapper(_activeSapper[i]);
				SocketUtil::Close(_activeSapper[i]->fd());
			}
		}
		//
		std::vector<Functor> functors;
		{
			MutexGuard lock(_mutex);
			functors.swap(_pendingFuncs);
		}
		for (int i = 0; i < functors.size(); ++i)
		{
			functors[i]();
		}

		//timer relevent
		uint64_t now = time.toInt();
		timer_mgr.exec_timer(now);
		uint64_t to = timer_mgr.get_next_tick_time();
		if (to != 0)
		{
			if (to > now && to - now >= 10)
			{
				_timeout = to - now;
			}
			else
			{
				_timeout = TIMER_DEFAULT_INTERNAL;
			}
		}
		else
		{
			_timeout = TIMER_INFINITE_INTERNAL;
		}
		
	}
}

void TimerEventLoop::runAfter(const TimerFunctor& timer, uint64_t ms)
{
	TimeEpoch te = TimeEpoch::now();
	uint64_t nms = te.toInt();
	runAt(timer, nms + ms);
}

void TimerEventLoop::runAt(const TimerFunctor& timer, uint64_t ms)
{
	timer_mgr.run_at(timer, ms);
}

void TimerEventLoop::wakeUp()
{
	uint64_t a = 1;
	SocketUtil::Write(_wakeup_fd, &a, sizeof(a));
}

void TimerEventLoop::updateSapper(SapperPtr sapper)
{
	_poller->updateSapper(sapper);
}

void TimerEventLoop::removeSapper(SapperPtr sapper)
{
	_poller->removeSapper(sapper);
}

void TimerEventLoop::runAfterWake(const Functor& func)
{
	MutexGuard lock(_mutex);
	_pendingFuncs.push_back(func);
}

void TimerEventLoop::breakAndRun(const Functor& func)
{
	MutexGuard lock(_mutex);
	_pendingFuncs.push_back(func);
	wakeUp();
}

}
