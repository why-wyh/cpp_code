#define _CRT_SECURE_NO_WARNINGS 
#include"SListNode.h"
void SLNodetest1()
{
	SLNode* p1 = NULL;
	SLNodepushback(&p1, 2);
	SLNodepushback(&p1, 3);
	SLNodepushback(&p1, 4);
	SLNodepushback(&p1, 5);
	SLNodeprint(p1);
	SLNodepopback(&p1);
	SLNodepopback(&p1);
	SLNodepopback(&p1);
	SLNodeprint(p1);
	SLNodepushFront(&p1, 7);
	SLNodepushFront(&p1, 8);
	SLNodepushFront(&p1, 9);
	SLNodepushFront(&p1, 10);
	SLNodeprint(p1);
	SLNodepopFront(&p1);
	SLNodepopFront(&p1);
	SLNodepopFront(&p1);
	SLNodeprint(p1);
	SLNode* find=SLNodeFind(p1, 7);
	/*if (find)
	{
		printf("找到了！\n");
	}
	else
	{
		printf("没找到！\n");
	}*/
	SLInsert(&p1, find, 1);
	SLNodeprint(p1);
	SLErase(&p1, find);
	SLNodeprint(p1);
	SLInsertAfter(find, 8);
	SLNodeprint(p1);
	SListDesTroy(&p1);
	SLNodeprint(p1);
}
int main()
{
	SLNodetest1();
}