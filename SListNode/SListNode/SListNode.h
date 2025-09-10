#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h"
#include "stdio.h"
#define  SLDATA int
typedef struct SListNode
{
	SLDATA a;
	struct SListNode* next;
}SLNode;
void SLNodeprint(SLNode* phead);
SLNode* SLNode_buy_Node(SLDATA x);
void SLNodepushback(SLNode** pphead, SLDATA x);
void SLNodepushFront(SLNode** pphead, SLDATA x);
void SLNodepopFront(SLNode** phead);
void SLNodepopback(SLNode** pphead);

