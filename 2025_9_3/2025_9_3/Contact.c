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
	scanf("%s", temp.tel);
	printf("�������ַ��\n");
	scanf("%s",temp.adress);
	SLpushback(ps,temp);
}

int find_by_name(Contact* ps,char*name)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->a[i].name, name))
		{
			return i;
		}
	}
		return -1;
}

void delContact(Contact* ps)
{
	char name[NAME_MAX];
	printf("������Ҫɾ����������\n");
	scanf("%s", name);
	int i = find_by_name(ps, name);
	if (i < 0)
	{
		printf("Ҫɾ�������ݲ�����\n");
	}
	else
	{
		SLposdele(ps, i);
	}
}

void showContact(Contact* ps)
{
	printf("����\t�Ա�\t����\t�绰\t��ַ\t\n");
	for(int i=0;i<ps->size;i++)
	{
		printf("%s\t%s\t%d\t%s\t%s\n", ps->a[i].name, ps->a[i].gender, ps->a[i].age,ps->a[i].tel, ps->a[i].adress);
	}
}

void FindContact(Contact* ps)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ�������\n");
	scanf("%s", name);
	int i = find_by_name(ps,name);
	if (i == -1)
	{
		printf("Ҫ���ҵ����ݲ�����\n");
	}
	else {
		printf("�ҵ���,��Ϣ�ǣ�\n");
		printf("����\t�Ա�\t����\t�绰\t��ַ\t\n");
		printf("%s\t%s\t%d\t%s\t%s\n", ps->a[i].name, ps->a[i].gender, ps->a[i].age, ps->a[i].tel, ps->a[i].adress);
	}
}
void ModifyContact(Contact* ps)
{
	char name[NAME_MAX];
	printf("������Ҫ������Ϣ������\n");
	scanf("%s", name);
	int i = find_by_name(ps, name);
	if (i == -1)
	{
		printf("Ҫ�޸ĵ��û�������\n");
	}
	else
	{
		printf("������������\n");
		scanf("%s",ps->a[i].name);
		printf("�������Ա�\n");
		scanf("%s", ps->a[i].gender);
		printf("���������䣻\n");
		scanf("%d", &ps->a[i].age);
		printf("������绰��\n");
		scanf("%s", ps->a[i].tel);
		printf("�������ַ��\n");
		scanf("%s", ps->a[i].adress);
		printf("�޸ĳɹ�\n");
	}
}