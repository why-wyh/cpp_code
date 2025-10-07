#define _CRT_SECURE_NO_WARNINGS 
#include"Date.h"
void test()
{
	Date d1;
	d1.Print();
	Date d2(d1);
	d2.Print();
	Date d3 = d2;
	d3.Print();
	Date d4(2025, 10, 7);
	if (d4 != d3)
	{
		cout << "d3!=d4" << endl;
	}
	if (d3 > d4)
	{
		cout << "d3>d4" << endl;
	}
	Date d5=d4 + 5;
	d5.Print();
	d4 += 5;
	d4.Print();
	d1 -= 5;
	d1.Print();
	++d1;
	d1.Print();
	--d1;
	d1.Print();
	d1--;
	d1.Print();
}
int main()
{
	test();
	return 0;
}