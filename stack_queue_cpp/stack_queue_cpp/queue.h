#pragma once
using namespace std;
#include<iostream>
#include<list>
#include<deque>

namespace why
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_front();
		}
		size_t size()
		{
			return _con.size();
		}
		T& back()
		{
			return _con.back();
		}
		const T& back()const
		{
			return _con.back();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
	
	void test_queue()
	{
		stack<int, list<int> > st;
		st.push(1);
		st.push(2);
		st.push(3);
		while (!st.empty())
		{
			cout << st.back() << " ";
			st.pop();
		}
		cout << endl;
	}
}
