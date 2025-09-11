#define _CRT_SECURE_NO_WARNINGS 
#include"SListNode.h"
void SLNodeprint(SLNode* phead)
{
	SLNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->a);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
SLNode* SLNode_buy_Node(SLDATA x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->a = x;
	newnode->next = NULL;
	return newnode;
}
void SLNodepushback(SLNode** pphead, SLDATA x)
{
	assert(pphead);
	SLNode* newnode = SLNode_buy_Node(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
	}
}
void SLNodepopback(SLNode** pphead)
{
	assert(pphead && *pphead);
	SLNode* ptail = *pphead;
	SLNode* pcur = *pphead;
	while (ptail->next)
	{
		pcur = ptail;
		ptail = ptail->next;
	}
	pcur->next = NULL;
	free(ptail);
	ptail = NULL;
}
void SLNodepushFront(SLNode** pphead, SLDATA x)
{
	assert(pphead);
	SLNode* newnode = SLNode_buy_Node(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
}
void SLNodepopFront(SLNode** pphead)
{
	assert(pphead&&*pphead);
	if ((*pphead)->next==NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* del = *pphead;
		*pphead = (*pphead)->next;
		free(del);
		del = NULL;
	}
}
SLNode* SLNodeFind(SLNode* phead, SLDATA x)
{
	assert(phead);
	SLNode* pcur = phead;
	while (pcur)
	{
		if (pcur->a == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void SLInsert(SLNode** pphead, SLNode* pos, SLDATA x)
{
	assert(pphead && pos && *pphead);
	SLNode* newnode = SLNode_buy_Node(x);
	SLNode* prev = *pphead;
	if (pos == *pphead)
	{
		SLNodepushFront(pphead, x);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = newnode;
		newnode->next = pos;
	}
}
void SLErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead && pos && *pphead);
	SLNode* prev = *pphead;
	if (pos == *pphead)
	{
		SLNodepopFront(pphead);
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SLInsertAfter(SLNode* pos, SLDATA x)
{
	SLNode* newnode = SLNode_buy_Node(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLEraseAfter(SLNode* pos)
{
	assert(pos&&pos->next);
	SLNode* pcur = pos->next;
	pos->next = pcur->next;
	free(pcur);
	pcur = NULL;
}
void SListDesTroy(SLNode** pphead)
{
	SLNode* pcur = *pphead;
	while (pcur)
	{
		SLNode* next = pcur->next;
		free(pcur);
		pcur = NULL;
		pcur = next;
	}
	*pphead = NULL;
}



