#ifndef SAPPER_H
#define SAPPER_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include "base/date_time.h"

class EventLoop;
class Sapper;

typedef boost::shared_ptr<EventLoop> EventLoopPtr;
//typedef boost::shared_ptr<Sapper> SapperPtr;

namespace SAPPER
{
	enum res_code
	{
		OK = 0,
		OVER = 1,
	};
}

class Sapper 
	: public boost::enable_shared_from_this<Sapper>
{
public:
	typedef boost::function<int()> CallBackHandler;
	Sapper(int sockfd, EventLoopPtr);
	int focusEvents() { return _in_events; }
	int revents() { return _out_events; }
	void focusRead();
	void focusWrite();
	void setREvent(int events);
	void setReadHandler(const CallBackHandler& cb) { _readCallback = cb; }
	void setWriteHandler(const CallBackHandler& cb) { _writeCallback = cb; }
	int handleEvent(const TimeEpoch&);
	int fd() { return _fd; }
	EventLoopPtr loopPtr() { return _loop; }
private:
	int _in_events;
	int _out_events;
	int _fd;
	EventLoopPtr _loop;
	CallBackHandler _readCallback;
	CallBackHandler _writeCallback;
	static const int _read_event;
	static const int _write_event;
	static const int _none_event;
private:
	void update();
};



#endif
