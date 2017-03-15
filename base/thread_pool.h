#ifndef BASE_THREAD_POOL_H
#define BASE_THREAD_POOL_H

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <vector>
#include <boost/shared_ptr.hpp>
#include "mutex.hpp"
#include "condition.hpp"
#include <deque>

class Thread;

class ThreadPool : boost::noncopyable
{
public:
	typedef boost::function<void()> Task;
	typedef boost::shared_ptr<Thread> ThreadPtr;
	ThreadPool(int maxParallel = 1000000);
	void start(int numThreads);
	void stop();
	void addTask(const Task&);

private:
	std::deque<Task> _tasks;
	int _max_parallel;
	std::vector<ThreadPtr> _threads;
	Mutex _mutex;
	Condition _full;
	Condition _notEmpty;
	bool _stop;
private:
	void run();
};

#endif
