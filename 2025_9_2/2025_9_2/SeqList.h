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
void SeqListInit(SeqList* ps);//��ʼ��
void CheckCapcity(SeqList* ps);//����С
void SeqListpushback(SeqList* ps, SeqListData x);//ͷ��
void SeqListpopback(SeqList* ps, SeqListData x);//ͷɾ
void SeqListpushFront(SeqList* ps, SeqListData x);//β��
void SeqListpopFront(SeqList* ps, SeqListData x);//βɾ

