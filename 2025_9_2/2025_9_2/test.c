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
	SLprint(&s);

}
int main()
{
	test1();
	return 0;
}