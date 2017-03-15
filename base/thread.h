#ifndef WINDS_THREAD_H
#define WINDS_THREAD_H

#include <boost/function.hpp>
#include <pthread.h>
#include <sys/syscall.h>

#define MAIN_THREAD_TTID 0

class Thread
{
public:
	typedef boost::function<void()> ThreadFunc;

	Thread(const ThreadFunc& func);
	void join();	
	void start();
	//only valid after thread start.
	pid_t tid() { return _tid; }
	//bool isMainThread() {return _ttid == MAIN_THREAD_TTID;}
private:
	static void* run(void* arg);
	void run_do();
private:
	pthread_t _pid;
	pid_t _tid;
	ThreadFunc _func;
	//int _ttid;
	//static int _numOfThread;
};

#endif
