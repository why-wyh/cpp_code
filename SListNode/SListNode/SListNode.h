#define _CRT_SECURE_NO_WARNINGS 
#include "stdlib.h"
#include "stdio.h"
#include <assert.h>
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


void SLNodepopback(SLNode** pphead);
void SLNodepopFront(SLNode** phead);

SLNode* SLNodeFind(SLNode* phead, SLDATA x);

void SLInsert (SLNode** pphead, SLNode* pos, SLDATA x);

void SLErase(SLNode** pphead, SLNode* pos);

void SLInsertAfter(SLNode* pos, SLDATA x);

void SLEraseAfter(SLNode* pos);
//Ïú»ÙÁ´±í

void SListDesTroy(SLNode** pphead);

