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
	if (*pphead == NULL)
	{
		printf("Á´±íÎª¿ÕÉ¾³ýÊ§°Ü¡£\n");
	}
	else
	{
		*pphead = (*pphead)->next;
	}
}

