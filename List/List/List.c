#include"List.h"
LTNode* buynewnode(LTDATA x)
{
	LTNode* new = (LTNode*)malloc(sizeof(LTNode));
	if (new == NULL)
	{
		perror("malloc faill!");
		exit(1);
	}
	new->x = x;
	new->next = new->prev=new;
	return new;
}
void ListInit(LTNode** phead)
{
	*phead = buynewnode(-1);
}
void LTPushback(LTNode* phead,LTDATA x)
{
	LTNode* new = buynewnode(x);
	new->prev = phead->prev;
	new->next = phead;

	phead->prev->next = new;
	phead->prev = new;
}
void LTpushFront(LTNode* phead, LTDATA* x)
{
	LTNode* new = buynewnode(x);
	new->prev = phead;
	new->next = phead->next;
	phead->next->prev = new;
	phead->next = new;
}
void LTprint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->", pcur->x);
		pcur = pcur->next;
	}
	printf("\n");
}
void LTPopback(LTNode* phead)
{
	LTNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}
void LTPopFront(LTNode* phead)
{
	LTNode* del = phead->next;
	del->next->prev = phead;
	del->prev->next = del->next;
}
