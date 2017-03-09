#ifndef EVENT_LOOP_H
#define EVENT_LOOP_H

//#include "sapper.h"
//#include "epoller.h"
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <vector>
#include "base/mutex.hpp"
#include "epoller.h"
//class Sapper;
//class Poller;

class EventLoop : public boost::enable_shared_from_this<EventLoop>
{
public:
	typedef boost::function<void()> Functor;
	EventLoop();
	void updateSapper(SapperPtr);
	void removeSapper(SapperPtr);
	void init();
	void loop();
	void runAfterWake(const Functor&);
	void breakAndRun(const Functor&);
private:
	int _wakeup_fd;
	uint64_t _wake_read;
	SapperList _activeSapper;
	bool _quit;
	bool _looping;
	static int _timeout;
	PollerPtr _poller;
	std::vector<Functor> _pendingFunc;
	Mutex _mutex;
private:
	void wakeUp();
};

#endif
