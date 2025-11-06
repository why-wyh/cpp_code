#define _CRT_SECURE_NO_WARNINGS 
#include"stack.h"
#include<stack>
#include<queue>
void test_stack()
{
	stack<int>st;
	st.push(0);
	st.push(1);
	st.push(2);
	st.push(3);
	cout << st.size() << endl;
	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	cout << st.size() << endl;
}
void test_queue()
{
	queue<int> qu;
	qu.push(0);
	qu.push(1);
	qu.push(2);
	qu.push(3);
	cout << qu.size() << endl;
	while (!qu.empty())
	{
		cout << qu.front() << " ";
		qu.pop();
	}
	cout << endl;
	cout << qu.size() << endl;
}
int main()
{
	//test_stack();
	//test_queue();
	why::test_stack2();
}