#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
#include<iostream>
#include<assert.h>
using namespace std;
namespace why
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
				push_back(e);
		}
		~vector()
		{
			delete[] _start;
			_start = nullptr;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		size_t capacity()
		{
			return _endofstorage - _start;
		}
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()const 
		{
			return _endofstorage-_start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* cap = new T[n];
				if (_start)
				{
					memcpy(cap, _start, sizeof(T)*sz);
					delete[]_start;
					_start = nullptr;
				}
				_start = cap;
				_finish = _start+sz;
				_endofstorage = _start + n;
			}
		
		}
		void push_back(const T& val)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*(_finish) = val;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		void insert(iterator pos, const T& val)
		{
			assert(pos < _finish);
			size_t len = pos - _start;
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = len + _start;
			}
			iterator end = _finish - 1;
			for (; end >=pos; end--)
			{
				*(end + 1) = *end;
			}
			*pos = val;
			++_finish;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
					reserve(n);
					iterator end = _finish;
					_finish = _start + n;
					while (end < _finish)
					{
						*end= val;
						end++;
					}
			}
		}

	private:
		iterator  _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void test()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.pop_back();
		v.insert(v.begin(), 0);
		v.resize(6);
		vector<int>  v2( v);
		for (auto e : v2)
		{
			cout << e <<" ";
		}
		cout << endl;
	}
}