#define _CRT_SECURE_NO_WARNINGS 
#include "SeqList.h"
void ContactInit(Contact* ps)
{
	SLInit(ps);
}

void addContact(Contact* ps)
{
	PeoInfo temp;
	printf("������������\n");
	scanf("%s",temp.name );
	printf("�������Ա�\n");
	scanf("%s", temp.gender);
	printf("���������䣻\n");
	scanf("%d", &temp.age);
	printf("������绰��\n");
	scanf("%d", temp.tel);
	printf("�������ַ��\n");
	scanf("%s",temp.adress);
	SLpushback(ps,temp);
}

void delContact(Contact* ps);

void showContact(Contact* ps)
{
	printf("����\t�Ա�\t����\t�绰\t��ַ\t\n");
	for(int i=0;i<ps->size;i++)
	{
		printf("%s\t%s\t%d\t%s\t%s\n", ps->a[i].name, ps->a[i].gender, ps->a[i].age,ps->a[i].tel, ps->a[i].adress);
	}
}
////
//void FindContact(Contact* ps);