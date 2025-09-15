#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDATA;
typedef struct ListNode
{
	LTDATA x;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;


void ListInit(LTNode** phead);

LTNode* buynewnode(LTDATA x);
//Í·²åÎ²²å

void LTPushback(LTNode* phead,LTDATA x);



void LTprint(LTNode* phead);

void LTpushFront(LTNode* phead, LTDATA* x);

void LTPopback(LTNode* phead);

void LTPopFront(LTNode* phead);

