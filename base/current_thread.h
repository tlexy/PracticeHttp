#ifndef CURRENT_THREAD_H
#define CURRENT_THREAD_H

namespace CurrentThread
{
	extern __thread int _cacheTid;
	
	void doCacheTid();

	inline int tid()
	{
		if (_cacheTid == 0)
		{
			doCacheTid();
		}
		return _cacheTid;
	}
}

#endif
