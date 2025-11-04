#define _CRT_SECURE_NO_WARNINGS 
#include<list>
using namespace std;
#include<iostream>
#include<cassert>
#include"list.h"
void list_test1()
{
	
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_front(0);
	for (auto e : lt)
	{

		cout << e << " ";
	}
	cout << endl;
	list<int> ::iterator it = lt.begin();
	while (it != lt.end())
	{
		*it *= 2;
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void list_test2()
{

	list<int>lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_front(0);
	list<int>lt2 = lt1;
	list<int>lt3(lt2);
	list<int> ::iterator it = lt2.begin();
	while (it != lt2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto e : lt3)
	{

		cout << e << " ";
	}
	cout << endl;
	list <int>::reverse_iterator it2 = lt3.rbegin();
	while (it2 != lt3.rend())
	{
		cout << *it2 << " ";
		it2++;
	}
	cout << endl;
}
void list_test3()
{

	list<int>lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_front(0);
	lt1.insert(lt1.begin(), -1);
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
	list <int>::iterator it = lt1.begin();
	while (it != lt1.end())
	{
		if (*it % 2 == 0)
		{
			cout << "  ";
			it = lt1.erase(it);
		}
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
int main()
{
	why::test2();
	/*list_test1();
	list_test2();
	list_test3();*/
}