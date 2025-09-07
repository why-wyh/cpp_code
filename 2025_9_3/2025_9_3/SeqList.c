#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"
void SLInit(SL* ps)
{
	assert(ps);
	ps->a = (SeqListData*) malloc (sizeof(SeqListData) * N);
	if (ps->a == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	ps->capacity = N;
	ps->size = 0;
}
void checkcapacity(SL* ps)
{
	assert(ps);
	assert(ps->a);
	if (ps->size >= ps->capacity)
	{
		size_t newcap = (ps->capacity == 0) ? N : (ps->capacity * 2);
		SeqListData* temp = (SeqListData*)realloc(ps->a, newcap * sizeof(SeqListData));
		if (temp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcap;
	}
}
void SLpushback(SL* ps, SeqListData x)
{
	assert(ps);
	assert(ps->a);
	checkcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SLpopback(SL* ps)
{
	assert(ps);
	//ps->size--;
	SLposdele(ps, ps->size);
}
void SLpushFront(SL* ps, SeqListData x)
{
	assert(ps);
	checkcapacity(ps);
	int end = 0;
	for (end = ps->size-1;end >=0 ;end--)
	{
		ps->a[end+1] = ps->a[end];
	}
	ps->size++;
	ps->a[0] = x;
}
void SLpopFront(SL* ps)
{
	assert(ps);
	/*int start = 0;
	for (start = 0; start < ps->size - 1; start++)
	{
		ps->a[start] = ps->a[start + 1];
	}
	ps->size--;*/
	SLposdele(ps, 0);
 }
void SLposinsert(SL* ps, SeqListData x, size_t pos)
{
	assert(ps);
    assert(pos>=0&&pos <= ps->size);
    checkcapacity(ps);
    for (size_t end = ps->size; end > pos; --end)
    {
        ps->a[end] = ps->a[end - 1];
    }
    ps->a[pos] = x;
    ps->size++;
 }
void SLposdele(SL* ps, size_t pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (size_t start =pos; start<ps->size-1 ;start++)
	{
		ps->a[start] = ps->a[start + 1];
	}
	ps->size--;
 }
void SLprint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
 }
//void SLfind(SL* ps,int x)
//{
//	int flag = 0;
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->a[i] == x)
//		{
//			flag = 1;
//			printf("找到了,下标是：%d\n", i);
//		}
//	}
//	if (flag = 0)
//		printf("没找到\n");
//}
//
