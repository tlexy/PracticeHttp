#ifndef TIMER_EVENT_LOOP_H
#define TIMER_EVENT_LOOP_H
/**
	A event loop with timer functionality.
	author: Lin, mar,14,2018
*/
#include <vector>
#include <boost/enable_shared_from_this.hpp>
#include <vector>
#include "base/mutex.hpp"
#include "epoller.h"
#include <boost/noncopyable.hpp>
#include <boost/bind.hpp>
#include "../common.h"
#include "base/timer_mgr.h"
#include "socket.h"

namespace Elixir{

class TimerEventLoop : public boost::noncopyable, public boost::enable_shared_from_this<TimerEventLoop>
{
public:
	TimerEventLoop(const Socket& serverSocket);
	virtual int handle_accept();
	virtual int handle_receive(SapperPtr handle);
	virtual int handle_write(SapperPtr handle);
	
	void wakeUp();
	void updateSapper(SapperPtr);
	void removeSapper(SapperPtr);
	void runAfterWake(const Functor&);
	void breakAndRun(const Functor&);
	void loop();
	void runAfter(const TimerFunctor&, uint64_t millisecond);
	void runAt(const TimerFunctor&, uint64_t millisecond);

protected:
	void init();//Add event fd for wake up.
protected:
	Socket _socket;
	SapperList _activeSapper;
	bool _quit;
	bool _looping;
	int _timeout;
	PollerPtr _poller;
	std::vector<Functor> _pendingFuncs;
	Mutex _mutex;
private:
	int _wakeup_fd;
	uint64_t _wakeup_read;
	bool _is_init;
};

}
#endif
