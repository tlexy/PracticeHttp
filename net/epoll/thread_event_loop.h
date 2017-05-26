#ifndef THREAD_EVENT_LOOP_H
#define THREAD_EVENT_LOOP_H

/*
* use thread pool to handle the business.
* 2017-5-26 by Lin Xing
*/

#include "../base/thread_pool.h"

class ThreadEventLoop
{
public:
	ThreadEventLoop(int thread_num);

private:
	ThreadPool _pool;
};

#endif
