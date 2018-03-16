#include "sapper.h"
#include "timer_event_loop.h"
#include <sys/poll.h>

namespace Elixir{

const int Sapper::_none_event = 0;
const int Sapper::_read_event = POLLIN | POLLPRI;
const int Sapper::_write_event = POLLOUT;

Sapper::Sapper(int sockfd, TimerEventLoopPtr loop)
	:_fd(sockfd),
	_in_events(0),
	_out_events(0),
	_loop(loop)
{
}

void Sapper::setREvent(int events)
{
	_out_events = events;
}

void Sapper::focusRead()
{
	_in_events |= _read_event;
	update();
}

void Sapper::focusWrite()
{
	_in_events |= _write_event;
	update();
}

int Sapper::handleEvent(const TimeEpoch& time)
{
	if ((_out_events & _read_event) && _readCallback)
	{
		return _readCallback();
	}
	if ((_in_events & _write_event) && _writeCallback)
	{
		return _writeCallback();
	}
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
