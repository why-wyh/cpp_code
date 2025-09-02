#define _CRT_SECURE_NO_WARNINGS 
# include "SeqList.h"
SeqListInit()//初始化
{
	SeqList;
}
void CheckCapcity(SeqList* ps);//检查大小
void SeqListpushback(SeqList* ps, SeqListData x);//头插
void SeqListpopback(SeqList* ps, SeqListData x);//头删
void SeqListpushFront(SeqList* ps, SeqListData x);//尾插
void SeqListpopFront(SeqList* ps, SeqListData x);//尾删