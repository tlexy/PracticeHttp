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

namespace Elixir{

class TimerEventLoop : public noncopyable
{
public:
	TimerEventLoop(const Socket& serverSocket);
	virtual void handle_accept();
	virtual void handle_receive(SapperPtr handle);
	virtual void handle_write(SapperPtr handle);
	
	void wakeUp();
	void updateSapper(SapperPtr);
	void removeSapper(SapperPtr);
	void runAfterWake(const Functor&);
	void breakAndRun(const Functor&);
	void loop();

protected:
	void init();//Add event fd for wake up.
protected:
	Socket _svr_socket;
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
	SapperList _activeSapper;
};

}
#endif
