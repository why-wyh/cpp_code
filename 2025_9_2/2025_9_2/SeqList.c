#define _CRT_SECURE_NO_WARNINGS 
#include "SeqList.h"
#include <string.h> /* memmove */

static void checkcapacity(SL* ps);

void SLInit(SL* ps)
{
    assert(ps);
    ps->a = (SeqListData*)malloc(sizeof(SeqListData) * N);
    if (ps->a == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    ps->capacity = N;
    ps->size = 0;
}

void SLDestroy(SL* ps)
{
    if (ps == NULL) return;
    free(ps->a);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

void SLpushback(SL* ps, SeqListData x)
{
    assert(ps);
    checkcapacity(ps);
    ps->a[ps->size] = x;
    ps->size++;
}

void SLpopback(SL* ps)
{
    assert(ps && ps->size > 0);
    ps->size--;
}

void SLpushFront(SL* ps, SeqListData x)
{
    assert(ps);
    checkcapacity(ps);
    /* 向右移动所有元素 1 位 */
    memmove(&ps->a[1], &ps->a[0], ps->size * sizeof(SeqListData));
    ps->a[0] = x;
    ps->size++;
}

void SLpopFront(SL* ps)
{
    assert(ps && ps->size > 0);
    /* 向左移动覆盖第一个元素 */
    memmove(&ps->a[0], &ps->a[1], (ps->size - 1) * sizeof(SeqListData));
    ps->size--;
}

void SLposeinset(SL* ps, SeqListData x, size_t pos)
{
    assert(ps);
    /* 允许 pos == ps->size 作为尾部插入 */
    assert(pos <= ps->size);
    if (pos == ps->size)
    {
        SLpushback(ps, x);
        return;
    }
    checkcapacity(ps);
    /* 从 pos 开始右移 (size - pos) 个元素 */
    memmove(&ps->a[pos + 1], &ps->a[pos], (ps->size - pos) * sizeof(SeqListData));
    ps->a[pos] = x;
    ps->size++;
}

void SLposdele(SL* ps, size_t pos)
{
    assert(ps && ps->size > 0);
    assert(pos < ps->size);
    /* 将 pos+1..end 左移覆盖 pos */
    memmove(&ps->a[pos], &ps->a[pos + 1], (ps->size - pos - 1) * sizeof(SeqListData));
    ps->size--;
}

void SLprint(const SL* ps)
{
    if (ps == NULL) return;
    for (size_t i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    puts("");
}

static void checkcapacity(SL* ps)
{
    assert(ps);
    if (ps->size >= ps->capacity)
    {
        size_t newcap = (ps->capacity == 0) ? N : (ps->capacity * 2); /* 修复 == 而非 = */
        SeqListData* temp = (SeqListData*)realloc(ps->a, newcap * sizeof(SeqListData));
        if (temp == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        ps->a = temp;
        ps->capacity = newcap;
    }
}