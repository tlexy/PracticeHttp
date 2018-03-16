#ifndef SAPPER_H
#define SAPPER_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include "base/date_time.h"

namespace Elixir{

class TimerEventLoop;
class Sapper;

typedef boost::shared_ptr<TimerEventLoop> TimerEventLoopPtr;
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
	Sapper(int sockfd, TimerEventLoopPtr);
	int focusEvents() { return _in_events | _out_events; }
	int revents() { return _revents; }
	void focusRead();
	void focusWrite();
	void setREvent(int events);
	void setReadHandler(const CallBackHandler& cb) { _readCallback = cb; }
	void setWriteHandler(const CallBackHandler& cb) { _writeCallback = cb; }
	int handleEvent(const TimeEpoch&);
	int fd() { return _fd; }
	TimerEventLoopPtr loopPtr() { return _loop; }
private:
	int _in_events;
	int _out_events;
	int _revents;
	int _fd;
	TimerEventLoopPtr _loop;
	CallBackHandler _readCallback;
	CallBackHandler _writeCallback;
	static const int _read_event;
	static const int _write_event;
	static const int _none_event;
private:
	void update();
};

}

#endif
