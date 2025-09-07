#define _CRT_SECURE_NO_WARNINGS 
#include "SeqList.h"
void ContactInit(Contact* ps)
{
	SLInit(ps);
}

void addContact(Contact* ps)
{
	PeoInfo temp;
	printf("请输入姓名；\n");
	scanf("%s",temp.name );
	printf("请输入性别\n");
	scanf("%s", temp.gender);
	printf("请输入年龄；\n");
	scanf("%d", &temp.age);
	printf("请输入电话；\n");
	scanf("%d", temp.tel);
	printf("请输入地址；\n");
	scanf("%s",temp.adress);
	SLpushback(ps,temp);
}

void delContact(Contact* ps);

void showContact(Contact* ps)
{
	printf("姓名\t性别\t年龄\t电话\t地址\t\n");
	for(int i=0;i<ps->size;i++)
	{
		printf("%s\t%s\t%d\t%s\t%s\n", ps->a[i].name, ps->a[i].gender, ps->a[i].age,ps->a[i].tel, ps->a[i].adress);
	}
}
////
//void FindContact(Contact* ps);