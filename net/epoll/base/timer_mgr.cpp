#include "timer_mgr.h"

namespace timic
{
#define IDENTITY_SIZE sizeof(TimerIdentity)

	TYPE::uint64 TimerMgr::_id = 0;

	TimerMgr::TimerMgr()
		: _mem_pool_ptr(new FairMemoryPool(TIMER_SIZE * 100, TIMER_SIZE))
	{
	}

	TimerMgr* TimerMgr::get_instance()
	{
		static TimerMgr* ins = nullptr;
		if (ins == nullptr)
		{
			ins = new TimerMgr();
		}
		return ins;
	}

	TimerIdentityPtr TimerMgr::add_timer(TimerFunctor func, TYPE::uint64 tick)
	{
		void* ptr = _mem_pool_ptr->alloc();
		if (!ptr)
		{
			assert(1 == 2);
		}
		TimerList* timer = (TimerList*)ptr;
		timer->id = get_identity();
		timer->tick_time = tick;
		timer->functor = func;

		int i = 0;

		if (_timers.find(tick) == _timers.end())
		{
			_timers[tick] = timer;
		}
		else
		{
			add_to_list(_timers[tick], timer);
		}
		return TimerIdentityPtr(new TimerIdentity(this, timer->id, timer->tick_time));
	}

	TYPE::uint64 TimerMgr::get_next_tick_time()
	{
		std::map<TYPE::uint64, TimerList*>::iterator it = _timers.begin();
		if (it != _timers.end() && it->second != nullptr)
		{
			return it->second->tick_time;
		}
		return 0;
	}

	void TimerMgr::del_timer(TimerIdentityPtr idptr)
	{
		std::map<TYPE::uint64, TimerList*>::iterator it = _timers.find(idptr->get_tick_time());
		if (it == _timers.end())
		{
			return;
		}
		//
		TimerList* header = it->second;
		TimerList* list = header;
		//下面的算法有待优化
		while (list->id != idptr->get_id())
		{
			if (list->next != nullptr)
			{
				header = list;
				list = list->next;
			}
			else
			{
				return;
			}
		}
		header->next = list->next;
		_mem_pool_ptr->recycle((void*)list);
	}

	void TimerMgr::exec_timer(TYPE::uint64 now)
	{
		std::cout << "exec in " << now << std::endl;
		std::map<TYPE::uint64, TimerList*>::iterator it = _timers.begin();
		for (; it != _timers.end();)
		{
			if (it->first > now)
			{
				return;
			}
			do_functor_list(it->second);
			it = _timers.erase(it);
		}
	}

	void TimerMgr::do_functor_list(TimerList* header)
	{
		TimerList* list = header;
		while (list != nullptr)
		{
			list->functor();
			header = list;
			list = list->next;
			_mem_pool_ptr->recycle(header);
		}
	}

	void TimerMgr::add_to_list(TimerList* header, TimerList* unit)
	{
		while (header->next != nullptr)
		{
			header = header->next;
		}
		header->next = unit;
	}

	TYPE::uint64 TimerMgr::get_identity()
	{
		return ++_id;
	}

	TimerMgr::~TimerMgr()
	{
	}


	///
	///
	TimerIdentity::TimerIdentity(TimerMgr* mgr, TYPE::uint64 id, TYPE::uint64 tick_time)
		: _ptr(mgr),
		_id(id),
		_tick_time(tick_time)
	{
	}

	void TimerIdentity::del_timer()
	{
		if (!_ptr)
		{
			return;
		}
		_ptr->del_timer(shared_from_this());
		//_ptr->del_timer(_id, _tick_time);
	}

	void TimerIdentity::set(TYPE::uint64 id, TYPE::uint64 tick_time)
	{
		_id = id;
		_tick_time = tick_time;
	}

	TYPE::uint64 TimerIdentity::get_id()
	{
		return _id;
	}

	TYPE::uint64 TimerIdentity::get_tick_time()
	{
		return _tick_time;
	}

	TimerIdentity::~TimerIdentity()
	{

		//_pool_unit_ptr->recycle();
	}

}
