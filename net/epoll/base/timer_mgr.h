﻿#pragma once

#include <boost/noncopyable.hpp>
#include <boost/bind.hpp>
#include "../../common.h"
#include <map>
#include <unordered_map>
#include <boost/enable_shared_from_this.hpp>
#include "fair_memory_pool.h"
#include <iostream>

#define timer_mgr (*Elixir::TimerMgr::get_instance())

namespace Elixir
{

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
			int64_t id;//唯一标识符
			uint64_t tick_time;//触发时间
			TimerFunctor functor;
			struct _timer_list* next;
		}TimerList;
#define TIMER_SIZE sizeof(TimerList)
	public:
		static TimerMgr* get_instance();

		TimerIdentityPtr add_timer(const TimerFunctor&, uint64_t tick_time);//添加定时器动作。参数为要执行的函数及动作
		//same as add_timer, but with no return value.
		void run_at(const TimerFunctor&, uint64_t tick_time);
		void del_timer(TimerIdentityPtr);
		void exec_timer(uint64_t now);

		uint64_t get_next_tick_time();//获得下一次触发时间，最小为10ms，为0时说明定时器列表为空
		int64_t get_identity();//分配定时器唯一标识符

		~TimerMgr();

	private:
		static int64_t _id;
		std::map<uint64_t, TimerList*> _timers;
		FairMemoryPool* _mem_pool_ptr;

	private:
		TimerMgr();
		void add_to_list(TimerList* header, TimerList* unit);
		void do_functor_list(TimerList* header);
		void impl_add_timer(TimerList*&, const TimerFunctor&, uint64_t tick);
		
	};

	class TimerIdentity : public boost::enable_shared_from_this<TimerIdentity>
	{
	public:
		TimerIdentity(TimerMgr* mgr, int64_t id, uint64_t tick_time);
		void del_timer();
		int64_t get_id();
		uint64_t get_tick_time();
		void set(int64_t id, uint64_t tick_time);
		~TimerIdentity();
	private:
		TimerMgr* _ptr;
		int64_t _id;//定时器的唯一标识符
		uint64_t _tick_time;//定时器的触发时间
	};

}

