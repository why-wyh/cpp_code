#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace why {
	template<class T>
	struct less {
		bool operator ()(const T& a, const T& b)
		{
			return a < b;
		}
	};
	template<class T>
	struct greater {
		bool operator ()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template<class T,class Container=vector<T>,class compare= less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
	{
			compare com;
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (com(_con[parent], _con[child]))
			{
				swap(_con[child], _con[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else {
				break;
			}
		}
	}
		  void AdjustDown()
		  {
			  compare com;
			  int parent = 0;
			  int child = parent * 2 + 1;
			  while (child < _con.size())
			  {
				  if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				  {
					  ++child;
				  }
				  if (com(_con[parent], _con[child]))
				  {
					  swap(_con[child], _con[parent]);
					  parent = child;
					  child = parent * 2 + 1;
				  }
				  else
				  {
					  break;
				  }
			  }
		  }
		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(static_cast<int>(_con.size()) - 1);
		}

		void pop()
		{
			if (_con.empty()) return;
			swap(_con[0], _con.back());
			_con.pop_back();
			if (!_con.empty())
			{
				AdjustDown();
			}
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	void test_priority_queue()
	{
		priority_queue<int, vector<int>> pq;
		pq.push(1);
		pq.push(8);
		pq.push(2);
		pq.push(3);
		pq.push(7);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
	void test2_priority_queue()
	{
		priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(1);
		pq.push(8);
		pq.push(2);
		pq.push(3);
		pq.push(7);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}
} 
