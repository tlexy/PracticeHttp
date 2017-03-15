#ifndef CONCURRENCYQUEUE_H
#define CONCURRENCYQUEUE_H

#include <deque>
#include "mutex.hpp"
#include "condition.hpp"
#include <boost/noncopyable.hpp>

template <typename T>
class ConcurrencyQueue : boost::noncopyable
{
public:
	ConcurrencyQueue()
		:_mutex(),
		_cond(_mutex),
		_queue()
	{}

	T front()
	{
		MutexGuard lock(_mutex);
		while (_queue.empty())
		{
			_cond.wait();
		}
		T ele(_queue.front());
		return ele;
	}

	T take()
	{
		MutexGuard lock(_mutex);
		while (_queue.empty())
		{
			_cond.wait();
		}
		T ele(_queue.front());
		_queue.pop_front();
		return ele;
	}

	void push(const T& ele)
	{
		MutexGuard lock(_mutex);
		_queue.push_back(ele);
		_cond.signal();
	}

	void pop()
	{
		MutexGuard lock(_mutex);
		if (!_queue.empty())
		{
			_queue.pop_front();
		}
	}

	size_t size()
	{
		MutexGuard lock(_mutex);
		return _queue.size();
	}
private:
	Mutex _mutex;
	Condition _cond;
	std::deque<T> _queue;
};

#endif
