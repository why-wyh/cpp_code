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
			cout << "构造，引用计数: " << *p_count << endl;
		}
		Share_ptr(const Share_ptr& other)
			: _ptr(other._ptr)
			, p_count(other.p_count)
		{
			++(*p_count);
			cout << "拷贝构造，引用计数: " << *p_count << endl;
		}
		~Share_ptr()
		{
			cout << "析构:" << *p_count << endl;
			cout << _ptr << endl;
			if (--(*p_count) == 0 && _ptr != nullptr)
			{
				delete _ptr;
				_ptr = nullptr;
				delete p_count;
				p_count = nullptr;
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
			if (this != &ptr)
			{
				if (--(*p_count) == 0)
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
	private:
		T* _ptr;
		int* p_count;
	};
}