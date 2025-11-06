#define _CRT_SECURE_NO_WARNINGS 
#pragma once
using namespace std;
#include<iostream>
#include<vector>
#include<list>
#include<deque>

namespace why
{
	template<class T, class Container=deque<T>>
	class stack
	{
	public:
		void push(const T& val )
		{
			_con.push_back(val);
		}
		void pop()
		{
			_con.pop_back();
		}
		size_t size()
		{
			return _con.size();
		}
		T& top()
		{
			return _con.back();
		}
		const T& top()const
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
	void test_stack1()
	{
		stack<int, vector<int> > st;
		st.push(1);
		st.push(2);
		st.push(3);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
	void test_stack2()
	{
		stack<int, list<int> > st;
		st.push(1);
		st.push(2);
		st.push(3);
		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}
}