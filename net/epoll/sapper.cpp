#include "sapper.h"
#include "timer_event_loop.h"
#include <sys/poll.h>
#include <iostream>

namespace Elixir{

const int Sapper::_none_event = 0;
const int Sapper::_read_event = POLLIN | POLLPRI;
const int Sapper::_write_event = POLLOUT;

Sapper::Sapper(int sockfd, TimerEventLoopPtr loop)
	:_fd(sockfd),
	_events(0),
	_revents(0),
	_loop(loop)
{
}

void Sapper::setREvent(int events)
{
	_revents = events;
	//update();
}

void Sapper::focusRead()
{
	_events |= _read_event;
	update();
}

void Sapper::focusWrite()
{
	_events |= _write_event;
	update();
}

int Sapper::handleEvent(const TimeEpoch& time)
{
	//std::cout << "events :" << _revents << std::endl;
	//std::cout << "revent :" << _read_event << std::endl;
	//std::cout << "wevent :" << _write_event << std::endl;
	if ((_revents & _read_event) && _readCallback)
	{
		return _readCallback();
	}
	if ((_revents & _write_event) && _writeCallback)
	{
		return _writeCallback();
	}
	//_revents = 0;
	return 0;
}

void Sapper::update()
{
	if (_loop)
	{
		_loop->updateSapper(shared_from_this());
	}
}

}
