#include "fair_memory_pool.h"
#include <stdlib.h>

namespace timic
{

	FailMemoryPoolBlock::FailMemoryPoolBlock(uint64_t pool_size, uint32_t alloc_unit)
		:_pool_size(pool_size),
		_alloc_unit(alloc_unit)
	{
		start = (uint64_t)malloc(_pool_size);
		memset((void*)start, 0x0, _pool_size);
		ptr = start;
		end = start + _pool_size;
	}

	void* FailMemoryPoolBlock::alloc()
	{
		void* addr;
		if (_empty_list.size() > 0)
		{
			addr = _empty_list.back();
			_empty_list.pop_back();
			return addr;
		}
		else
		{
			//从池中进行分配
			if (is_enough())
			{
				addr = (void*)ptr;
				ptr = ptr + _alloc_unit;
				_in_use_list.push_back(addr);
				return addr;
			}
			else
			{
				return nullptr;
			}
		}
	}

	bool FailMemoryPoolBlock::is_full()
	{
		return _in_use_list.size() * _alloc_unit + _alloc_unit > _pool_size;
	}

	bool FailMemoryPoolBlock::is_enough()
	{
		if (end > ptr && end - ptr >= _alloc_unit)
		{
			return true;
		}
		return false;
	}

	void FailMemoryPoolBlock::recycle(void* ptr)
	{
		std::cout << "recycle" << std::endl;
		_empty_list.push_back(ptr);
	}

	bool FailMemoryPoolBlock::is_belong(void* ptr)
	{
		uint64_t iptr = (uint64_t)ptr;
		return iptr >= start && iptr < end;
	}

	FailMemoryPoolBlock::~FailMemoryPoolBlock()
	{
	}

	/////------------------------------------------/////

	FairMemoryPool::FairMemoryPool(TYPE::uint64 pool_size, TYPE::uint32 alloc_unit)
		:_pool_size(pool_size),
		_alloc_unit(alloc_unit)
	{
		FailMemoryPoolBlockPtr block = FailMemoryPoolBlockPtr(new FailMemoryPoolBlock(_pool_size, _alloc_unit));
		_blocks.push_back(block);
	}

	void* FairMemoryPool::alloc()
	{
		std::list<FailMemoryPoolBlockPtr>::iterator it = _blocks.begin();
		for (; it != _blocks.end(); ++it)
		{
			if (!(*it)->is_full())
			{
				return (*it)->alloc();
			}
			else
			{
				FailMemoryPoolBlockPtr nblock = FailMemoryPoolBlockPtr(new FailMemoryPoolBlock(_pool_size, _alloc_unit));
				_blocks.push_front(nblock);
				return nblock->alloc();
			}
		}
	}

	void FairMemoryPool::recycle(void* ptr)
	{
		std::list<FailMemoryPoolBlockPtr>::iterator it = _blocks.begin();
		for (; it != _blocks.end(); ++it)
		{
			if ((*it)->is_belong(ptr))
			{
				(*it)->recycle(ptr);
				break;
			}
		}
	}
}
