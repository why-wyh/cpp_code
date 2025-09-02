#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include  <stddef.h>
typedef int SeqListData;
# define  N  4
typedef struct SeqList
{

	SeqListData* a;
	size_t size;
	size_t capcity;
}SeqList;
void SeqListInit(SeqList* ps);//初始化
void CheckCapcity(SeqList* ps);//检查大小
void SeqListpushback(SeqList* ps, SeqListData x);//头插
void SeqListpopback(SeqList* ps, SeqListData x);//头删
void SeqListpushFront(SeqList* ps, SeqListData x);//尾插
void SeqListpopFront(SeqList* ps, SeqListData x);//尾删

