#pragma once
#include<new>
#include<cstddef>
#include<cstdlib>
#include<climits>
#include<iostream>

namespace LL
{
	template<class T>
	inline T * _allocate(ptrdiff_t size, T *)
	{
		set_new_handler(0);
		T * tmp = (T *)(::operator new(size_t(size * sizeof(T))));
		if (tmp == 0)
		{
			cerr << "out of memory" << endl;
			exit(1);
		}
		return tmp;

	}
	template<class T>
	inline void _deallocate(T * buffer)
	{
		::operator delete(buffer);
	}
	template<class T1, class T2>
	inline void _construct(T1 *p, const T2 & value)
	{
		new (p) T1(value);
	}
	template <class T>
	inline void _destroy(T* ptr)
	{
		ptr->~T();
	}
	template <class T>
	class allocator
	{
	public:
		typedef T value_type;
		typedef T * pointer;
		typedef const t* const_pointer;
		typedef T & reference;
		typedef const T & const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		template <class U>
		struct rebind
		{
			typedef allocator<U> other;
		};
		pointer allocate(size_type n, const void * hint = 0)
		{
			return _allocate((difference_type)n, (pointer)0);
		}
		void deallocate(pointer p, size_type n)
		{
			_deallocate(p);
		}
	};
}
