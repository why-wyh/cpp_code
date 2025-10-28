#define _CRT_SECURE_NO_WARNINGS 
#include<vector>
#include<iostream>
using namespace std;
void test_vector1()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.pop_back();
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	cout << v1[1] << endl;
	for (size_t i=0;i<v1.size();i++)
	{
		cout << v1[i]<<" ";
	}
	cout << endl;
	vector <int>v2( v1);
	for (size_t i = 0; i < v1.size(); i++)
	{
		
		
		cout << v2[i] << " ";
	}
	cout << endl;
	vector <int>s3;
	vector<int> v4(4, 100);
	cout << v4.size() << ' ' << v4.capacity() << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{

		cout << v4[i] << " ";
	}
	cout << endl;
}
void test_vector2()
{
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.pop_back();
	//ÈýÖÖ±éÀú
	auto it = v1.begin();
	while (it != v1.end())
	{
	
		cout << *it <<" ";
		it++;
	}
	cout << endl;
	vector<int>::reverse_iterator i = v1.rbegin();
	while (i != v1.rend())
	{
		*i *= 2;
		cout << *i << " ";
		i++;
	}
	cout << endl;
	v1.insert(v1.begin(), 0);
	v1.insert(v1.end(), 10);
	v1.erase(v1.begin() + 1);
	vector<int>::iterator f = find(v1.begin(), v1.end(), 8);
	v1.erase(f);
	for (auto e : v1)
	{
		cout << e<<" ";
	}
	cout << endl;
	auto v2 = v1;
	
}

int main()
{
	//test_vector1();
	test_vector2();

	return 0;
}