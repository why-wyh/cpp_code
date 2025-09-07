#define _CRT_SECURE_NO_WARNINGS 
#pragma once
#include <stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "Contact.h"
#define N 4
typedef struct PersonInfo SeqListData;
typedef struct SeqList
{
	SeqListData* a;
	size_t size;
	size_t capacity;
}SL;
void SLInit(SL* ps);

void SLpushback(SL* ps, SeqListData x);
void SLpopback(SL* ps);

void SLpushFront(SL* ps, SeqListData x);
void SLpopFront(SL* ps);

void SLposinsert(SL* ps, SeqListData x,size_t pos);
void SLposdele(SL* ps, size_t pos);

void SLprint(SL* ps);


