#ifndef SINGLETON_H
#define SINGLETON_H

#include <pthread.h>
#include <boost/noncopyable.hpp>

template<typename T>
class Singleton : boost::noncopyable
{
public:
	static T* getInstance()
	{
		pthread_once(&_once, &Singleton::init);
		return _instance;
	}

private:
	static pthread_once_t _once;
	static T* _instance;

private:
	Singleton();
	~Singleton();

	static void init()
	{
		_instance = new T();
	}
};

template<typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::_instance = NULL;


#endif
