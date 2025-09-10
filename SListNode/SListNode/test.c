#define _CRT_SECURE_NO_WARNINGS 
#include"SListNode.h"
void SLNodetest1()
{
	SLNode* p1 = SLNode_buy_Node(1);
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


}
int main()
{
	SLNodetest1();
}