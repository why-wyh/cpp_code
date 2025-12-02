#pragma once
#include<iostream>
using namespace std;
namespace why
{
	template<class T>
	class Share_ptr
	{
	public:
		Share_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			, p_count(new int(1))
		{
		}
		~Share_ptr()
		{
			if (--(*p_count) == 0 && _ptr != nullptr)
			{
				delete _ptr;
				_ptr = nullptr;
				delete p_count;
				p_count = nullptr;
				cout << _ptr ;
			}
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator*()
		{
			if(_ptr!=nullptr)
			return *(_ptr);
		}
		Share_ptr<T>& operator=(Share_ptr ptr)
		{
			if (this != ptr)
			{
				if (--(*p_count) == 1)
				{
					delete p_count;
					delete _ptr;
				}
				_ptr = ptr._ptr;
				p_count = ptr.p_count;
				++(*p_count);
		    }
			return *this;
		}
		shared_ptr<T>& operator()( shared_ptr<T>& ptr)
		{
			_ptr = ptr._ptr;
			*(ptr.p_count)++;
			p_count = ptr.p_count;
		}
	private:
		T* _ptr;
		int* p_count;
	};

}