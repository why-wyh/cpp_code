#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define N 4
#define SeqListData int

typedef struct SeqList
{
    SeqListData* a;
    size_t size;
    size_t capacity;
} SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);

void SLpushback(SL* ps, SeqListData x);
void SLpopback(SL* ps);

void SLpushFront(SL* ps, SeqListData x);
void SLpopFront(SL* ps);

void SLposeinset(SL* ps, SeqListData x, size_t pos); /* 在 pos 插入 (pos 可为 0..size) */
void SLposdele(SL* ps, size_t pos);                  /* 删除 pos 位置元素 (pos 必须 < size) */

void SLprint(const SL* ps);