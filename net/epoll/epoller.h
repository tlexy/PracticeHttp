#ifndef EPOLLER_H
#define EPOLLER_H

#include "poller.h"
#include <sys/epoll.h>

namespace Elixir{

class EPoller : public Poller
{	
typedef std::map<int, SapperPtr> SapperPtrMap;
typedef std::vector<struct epoll_event> EventList;

public:
	EPoller();	
	virtual TimeEpoch poll(int timeout, SapperList& activeSapper);
	virtual void updateSapper(SapperPtr);
	virtual void removeSapper(SapperPtr);

private:
	int _epoll_fd;
	SapperPtrMap _sappers;
	EventList _events;
	static int _eventSize;
}
;

}

#endif
