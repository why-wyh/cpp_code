#define _CRT_SECURE_NO_WARNINGS 
#include<cstring>
namespace why
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
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
		size_t size()
		{
			return _finish - _start;
		}
		size_t capacity()
		{
			return _endofstorage-_start;
		}
		void reserve(size_t cap)
		{
			size_t sz = size();
				T* n = new T[cap];
				for (size_t i = 0; i < sz; ++i)
					n[i] = _start[i];
				delete[] _start;
				_start = n;
				_finish = n + sz;
				_endofstorage = n + cap;
		
		}
		iterator insert(iterator pos,T& val)
		{
			if (capacity == size)
			{
				size_t  newcapcity = 0 ? 2 : capacity * 2;
				reserve(newcapcity);
				for (int i = capacity; i >= pos; i--)
				{
					iterator begin()[i + 1] = iterator begin()[i];
				}
				iterator begin()[pos] = val;
				iterator end()++;
			 }
		}
		
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;
	};
	void test()
	{
		vector<int> v;
		int a = 2;
		v.insert(v.begin(),a);
	}
}