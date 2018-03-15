#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include "base.h"
#include <map>
#include <unordered_map>
#include <boost/enable_shared_from_this.hpp>
#include "fair_memory_pool.h"
#include <iostream>

#define timer_mgr (*timic::TimerMgr::get_instance())

namespace timic
{
	typedef boost::function<void()> TimerFunctor;

	class TimerIdentity;
	SHAREDPTR(TimerIdentity, TimerIdentityPtr);

	SHAREDPTR(FairMemoryPool, FairMemoryPoolPtr);

	class TimerMgr;
	SHAREDPTR(TimerMgr, TimerMgrPtr);

	//定时器管理器类
	class TimerMgr : public boost::noncopyable
	{
	private:
		typedef struct _timer_list
		{
		public:
			_timer_list() : next(nullptr){}
			TYPE::uint64 id;//唯一标识符
			TYPE::uint64 tick_time;//触发时间
			TimerFunctor functor;
			struct _timer_list* next;
		}TimerList;
#define TIMER_SIZE sizeof(TimerList)
	public:
		static TimerMgr* get_instance();

		TimerIdentityPtr add_timer(TimerFunctor, TYPE::uint64);//添加定时器动作。参数为要执行的函数及动作
		void del_timer(TimerIdentityPtr);
		void exec_timer(TYPE::uint64 now);

		TYPE::uint64 get_next_tick_time();//获得下一次触发时间，最小为10ms，为0时说明定时器列表为空
		TYPE::uint64 get_identity();//分配定时器唯一标识符

		~TimerMgr();

	private:
		static TYPE::uint64 _id;
		std::map<TYPE::uint64, TimerList*> _timers;
		FairMemoryPool* _mem_pool_ptr;

	private:
		TimerMgr();
		void add_to_list(TimerList* header, TimerList* unit);
		void do_functor_list(TimerList* header);
		
	};

	class TimerIdentity : public boost::enable_shared_from_this<TimerIdentity>
	{
	public:
		TimerIdentity(TimerMgr* mgr, TYPE::uint64 id, TYPE::uint64 tick_time);
		void del_timer();
		TYPE::uint64 get_id();
		TYPE::uint64 get_tick_time();
		void set(TYPE::uint64 id, TYPE::uint64 tick_time);
		~TimerIdentity();
	private:
		TimerMgr* _ptr;
		TYPE::uint64 _id;//定时器的唯一标识符
		TYPE::uint64 _tick_time;//定时器的触发时间
	};

}

