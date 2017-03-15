#include "thread.h"
#include "current_thread.h"
#include <unistd.h>

namespace CurrentThread
{
	__thread int _cacheTid = 0;

	void doCacheTid()
	{
		if (_cacheTid == 0)
		{
			_cacheTid = static_cast<pid_t>(::syscall(SYS_gettid));
		}
	}

	void sleep(int second)
	{
		::sleep(second);
	}
}

//int Thread::_numOfThread = 0;

Thread::Thread(const ThreadFunc& func)
	: _func(func)
	//_ttid(_numOfThread)
{	
	//++_numOfThread;
}

void* Thread::run(void* arg)
{
	Thread* thread = static_cast<Thread*>(arg);
	thread->run_do();
	return NULL;
}

void Thread::run_do()
{
	_tid = CurrentThread::tid();
	_func();
}

void Thread::join()
{
	pthread_join(_pid, NULL);
}

void Thread::start()
{
	pthread_create(&_pid, NULL, run, this);
}
