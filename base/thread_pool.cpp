#include "thread_pool.h"
#include <exception>
#include "thread.h"
#include "common.hpp"
#include <boost/bind.hpp>
#include <iostream>

ThreadPool::ThreadPool(int max)
	:_max_parallel(max),
	_full(_mutex),
	_notEmpty(_mutex),
	_stop(false)
{
}

void ThreadPool::start(int num)
{
	while(num--)
	{
		ThreadPtr thread = Creator<Thread>::Create(boost::bind(&ThreadPool::run, this));
		_threads.push_back(thread);
		thread->start();
	}
}

void ThreadPool::stop()
{
	_stop = true;
}

void ThreadPool::addTask(const Task& task)
{
	if (_threads.size() == 0)
	{
		task();
		return;
	}
	MutexGuard lock(_mutex);
	if (_tasks.size() <= _max_parallel)
	{
		_tasks.push_back(task);
	}
	else
	{
		_full.wait();
		_tasks.push_back(task);
	}
	_notEmpty.signal();
}

void ThreadPool::run()
{
	try
	{
		while(!_stop)
		{
			Task task;
			{
				MutexGuard lock(_mutex);
				while (_tasks.empty())
				{
					//std::cout << "wait..." << std::endl;
					_notEmpty.wait();
				}
				task = _tasks.front();
				_tasks.pop_front();
				_full.signal();
			}
			if (task)
			{
				task();
			}
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << "catch error while ThreadPool::run : " << ex.what() << std::endl;
	}
}
