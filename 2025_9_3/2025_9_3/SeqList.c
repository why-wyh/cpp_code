#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"
void SLInit(SL* ps)
{
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
	/*assert(ps->a);
	checkcapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;*/
	SLposinsert(ps, x, ps->size);
}
void SLpopback(SL* ps)
{
	//ps->size--;
	SLposdele(ps, ps->size);
}
void SLpushFront(SL* ps, SeqListData x)
{
	assert(ps);
	/*checkcapacity(ps);
	int end = 0;
	for (end = ps->size-1;end >=0 ;end--)
	{
		ps->a[end+1] = ps->a[end];
	}
	ps->size++;
	ps->a[0] = x;*/
	SLposinsert(ps, x, 0);

}
void SLpopFront(SL* ps)
{
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
    assert(pos <= ps->size);
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
	for (size_t start =pos; start<ps->size-1 ;start++)
	{
		ps->a[start] = ps->a[start + 1];
	}
	ps->size--;
 }
void SLprint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
 }

