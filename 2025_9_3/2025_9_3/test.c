#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"
void test1()
{
	SL s;
	SLInit(&s);
	SLpushback(&s, 1);
	SLpushback(&s, 2);
	SLpushback(&s, 3);
	SLpushback(&s, 4);
	SLpushback(&s, 5);
	SLpushback(&s, 6);
	SLprint(&s);
	SLpopback(&s);
	SLpopback(&s);
	SLprint(&s);
	SLpopFront(&s);
	SLpopFront(&s);
	SLpopFront(&s);
	SLprint(&s);
	SLpushFront(&s,3);
	SLpushFront(&s, 2);
	SLpushFront(&s, 1);
	SLprint(&s);
}
int main()
{
	test1();
	return 0;
}