#pragma once

#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <list>
#include <vector>
#include "../../common.h"
#include <iostream>

namespace Elixir{

	class FailMemoryPoolBlock;
	SHAREDPTR(FailMemoryPoolBlock, FailMemoryPoolBlockPtr);

	//内存块
	class FailMemoryPoolBlock : public boost::noncopyable
	{
	public:
		FailMemoryPoolBlock(uint64_t pool_size, uint32_t alloc_unit);

		void* alloc();
		void recycle(void* ptr);
		bool is_belong(void* ptr);
		bool is_full();//是否还有空闲的空间可分配

		~FailMemoryPoolBlock();

	private:
		uint64_t _pool_size;
		uint32_t _alloc_unit;
		std::list<void*> _in_use_list;
		std::list<void*> _empty_list;
		//
		uint64_t start;
		uint64_t end;
		uint64_t ptr;//当前指向的位置

	private:
		bool is_enough();//是否还有新的空间可分配

	};

	//内存池
	class FairMemoryPool : public boost::noncopyable
	{
	public:
		FairMemoryPool(uint64_t pool_size, uint32_t alloc_unit);
		void* alloc();
		void recycle(void* ptr);
	private:
		std::list<FailMemoryPoolBlockPtr> _blocks;
		uint64_t _pool_size;
		uint32_t _alloc_unit;
	};

}

