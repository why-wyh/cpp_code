#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
using namespace std;
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b)
	{
		swap(a, b);
	}
	int r = a % b;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	cout << b << endl;
	return 0;
}