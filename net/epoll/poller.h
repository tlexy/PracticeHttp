#ifndef POLLER_H
#define POLLER_H

#include <boost/noncopyable.hpp>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "base/date_time.h"

namespace Elixir{

class Sapper;
class Poller;

typedef boost::shared_ptr<Sapper> SapperPtr;
typedef std::vector<SapperPtr> SapperList;
typedef boost::shared_ptr<Poller> PollerPtr;

class Poller
{
public:
	Poller() {}
	virtual TimeEpoch poll(int timeout, SapperList& activeSapper) = 0;
	virtual void updateSapper(SapperPtr){}
	virtual void removeSapper(SapperPtr){}
	virtual ~Poller(){}
};

}

#endif
