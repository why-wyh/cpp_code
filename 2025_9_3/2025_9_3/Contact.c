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
	scanf("%s", temp.tel);
	printf("请输入地址；\n");
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
	printf("请输入要删除的姓名：\n");
	scanf("%s", name);
	int i = find_by_name(ps, name);
	if (i < 0)
	{
		printf("要删除的数据不存在\n");
	}
	else
	{
		SLposdele(ps, i);
	}
}

void showContact(Contact* ps)
{
	printf("姓名\t性别\t年龄\t电话\t地址\t\n");
	for(int i=0;i<ps->size;i++)
	{
		printf("%s\t%s\t%d\t%s\t%s\n", ps->a[i].name, ps->a[i].gender, ps->a[i].age,ps->a[i].tel, ps->a[i].adress);
	}
}

void FindContact(Contact* ps)
{
	char name[NAME_MAX];
	printf("请输入要查找的姓名：\n");
	scanf("%s", name);
	int i = find_by_name(ps,name);
	if (i == -1)
	{
		printf("要查找的数据不存在\n");
	}
	else {
		printf("找到了,信息是：\n");
		printf("姓名\t性别\t年龄\t电话\t地址\t\n");
		printf("%s\t%s\t%d\t%s\t%s\n", ps->a[i].name, ps->a[i].gender, ps->a[i].age, ps->a[i].tel, ps->a[i].adress);
	}
}
void ModifyContact(Contact* ps)
{
	char name[NAME_MAX];
	printf("请输入要更改信息姓名：\n");
	scanf("%s", name);
	int i = find_by_name(ps, name);
	if (i == -1)
	{
		printf("要修改的用户不存在\n");
	}
	else
	{
		printf("请输入姓名；\n");
		scanf("%s",ps->a[i].name);
		printf("请输入性别\n");
		scanf("%s", ps->a[i].gender);
		printf("请输入年龄；\n");
		scanf("%d", &ps->a[i].age);
		printf("请输入电话；\n");
		scanf("%s", ps->a[i].tel);
		printf("请输入地址；\n");
		scanf("%s", ps->a[i].adress);
		printf("修改成功\n");
	}
}