#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void func(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{

	int a = 0;
	int b = 1;
	cout << a << "\n" << b << endl;
	func(a, b);
	cout << a << "\n" << b << endl;
	return 0;
}
int& func()
{
	static int n = 0;
	n++;
	return n;
}
int main()
{
	int& ret = func();
	ret = 100;
	func();
	cout << ret << endl;
	return 0;
}
int main()
{

	int a = 0;
	int b = 1;
	const int& c = a;
	int* p =&a;
	int*& pp = p;
	cout << p <<"\n" << pp << endl;
	return 0;
}
int main()
{
	int i = 1;
	double& b = i;
	const double& c = i;
	cout << i << endl;
	return 0;
}
int main()
{
	int a[10];
	int i = 0;
	for (auto e : a)
	{
		a[i] = i;
		i++;
	}
	i = 0;
	for (auto e : a)
	{
		cout << a[i] << " " ;
		i++;
	}
	cout << endl;

	return 0;
}
typedef class st
{
	
public:
   st(int _ag= 0, int _h = 0)
	{
		cout << 'a' << endl;
		_age = _ag;
		_high = _h;
	}
	void print()
	{
		cout << "aut" << endl;
	}
	void show()
	{
		cout << this->_age << endl;
		cout << this->_high<< endl;
	}
	void push( int a, int h)
	{
		this->_age = a;
		this->_high = h;
	}
private:
	int _age;
	int _high;
}; 
class _void
{
private:
};
int main()
{
	st st1;
	
	st1.push( 20, 188);
	st1.show();
	st1.print();
	st st2(10,20);
	st2.show();
	cout << sizeof(st) << endl;
	cout << sizeof(_void) << endl;
	return 0;
}