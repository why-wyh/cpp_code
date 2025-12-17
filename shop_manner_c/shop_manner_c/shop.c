#define _CRT_SECURE_NO_WARNINGS 
#include"shop.h"
void menu()
{
	system("cls");
	printf("|----------------------------------|\n");
	printf("|          请输入选项编号0-5       |\n");
	printf("|----------------------------------|\n");
	printf("|          1：创建商品档案。       |\n");
	printf("|          2：编辑商品信息。       |\n");
	printf("|          3：统计销售情况。       |\n");
	printf("|          4：查询商品信息。       |\n");
	printf("|          5：显示商品信息。       |\n");
	printf("|          0：退出系统。           |\n");
	printf("|----------------------------------|\n");
}
void menu1()
{
	system("cls");
	printf("|**********************************|\n");
	printf("|          请输入选项编号0-4       |\n");
	printf("|**********************************|\n");
	printf("|          1：添加新商品信息       |\n");
	printf("|          2：删除商品。           |\n");
	printf("|          3：修改原有商品信息。   |\n");
	printf("|          4：返回                 |\n");
	printf("|          0：退出系统             |\n");
	printf("|**********************************|\n");
}
void menu2()
{
	system("cls");
	printf("|**********************************|\n");
	printf("|          请输入选项编号0-3       |\n");
	printf("|**********************************|\n");
	printf("|          1：按品名查询           |\n");
	printf("|          2：按剩余数查询         |\n");
	printf("|          3：返回                 |\n");
	printf("|          0：退出系统             |\n");
	printf("|**********************************|\n");
}
void Display_product(Product* product[100], int* count)
{
	system("cls");
	if (*count == 0) {
		printf("当前没有商品信息！\n");
		printf("\n按回车键继续...");
		getchar();
		getchar();
		return;
	}
	printf("|===========================================================|\n");
	printf("|                    所有商品信息                           |\n");
	printf("|===========================================================|\n");
	for (int i = 0; i < *count; i++)
	{
		printf("\n\n");
		printf("商品编号:%d\n",product[i]->ID);
		printf("商品名称:%s\n", product[i]->name);
		printf("商品进价:%.2f\n", product[i]->cost_price);
		printf("商品售价:%.2f\n", product[i]->sell_price);
		printf("商品销售量:%d\n", product[i]->sales_volume);
		printf("商品库存量:%d\n", product[i]->stock);
		printf("销售额：%.2f\n", product[i]->sales_revenue);
		printf("毛利：%.2f\n", product[i]->profit);
		printf("\n\n");
	}
	Sleep(10000);
}

void Add_new_product(Product* product[100], int* count)
{
	if (*count >= 100)
	{
		printf("商品已达最大数量\n");
		return;
	}

	product[*count] = (Product*)malloc(sizeof(Product));
	if (product[*count] == NULL) {
		printf("内存分配失败\n");
		return;
	}

	Product* p = product[*count]; 

	printf("请输入商品编号：");
	scanf("%d", &p->ID);
	
	printf("请输入商品名称：");
	scanf("%s", p->name);

	printf("请输入商品进价：");
	scanf("%f", &p->cost_price);

	printf("请输入商品售价：");
	scanf("%f", &p->sell_price);

	printf("请输入商品销售量：");
	scanf("%d", &p->sales_volume);

	printf("请输入商品库存量：");
	scanf("%d", &p->stock);
	p->sales_revenue = p->sell_price * p->sales_volume;
	p->profit = (p->sell_price - p->cost_price) * p->sales_volume;

	printf("商品添加成功！\n");
	++*count;
}
void Delete_product(Product* product[100], int id,int *count)
{
	int flag = 0;
	for(int i=0;i<*count;i++)
	{
		if (product[i]->ID == id)
		{
			flag = 1;
			free(product[i]);
			for (int j = i; j < *count; j++)
			{
				product[j] = product[j + 1];
			}
			-- * count;
			--i;
			break;
		}
	}
	if (flag == 1)
		printf("商品删除成功\n");
	else
		printf("未找到商品\n");
}
void Change_product(Product* product[100], int id, int* count)
{
	for (int i = 0; i < *count; i++)
	{
		if (product[i]->ID == id)
		{
			Product* p = product[i]; 
			printf("请输入更改后的商品编号：");
			scanf("%d", &p->ID);
			printf("请输入更改后的商品名称：");
			scanf("%s", p->name);
			printf("请输入更改后的商品进价：");
			scanf("%f", &p->cost_price);
			printf("请输入更改后的商品售价：");
			scanf("%f", &p->sell_price);
			printf("请输入更改后的商品销售量：");
			scanf("%d", &p->sales_volume);
			printf("请输入更改后的商品库存量：");
			scanf("%d", &p->stock);
			p->sales_revenue = p->sell_price * p->sales_volume;
			p->profit = (p->sell_price - p->cost_price) * p->sales_volume;
			printf("商品更改成功成功！\n");
		}
	}
}
void Creat_product(Product* product[100], int* count)
{
	int input = 0;
	int id = 0;
	do {
		menu1();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出系统\n");
			break;
		case 1:
			printf("添加商品信息：\n");
			Add_new_product(product,count);
			Display_product(product, count);
			break;
		case 2:
			printf("删除商品：\n");
			printf("请输入要删除的商品ID\n");
			scanf("%d", &id);
			Delete_product(product,id,count);
			Display_product(product, count);
			break;
		case 3:
			printf("修改商品信息：\n");
			printf("请输入要修改的商品ID\n");
			scanf("%d", &id);
			Change_product(product, id, count);
			Display_product(product, count);
			break;
		case 4:
			printf("返回主菜单\n");
			break;
		}
	} while (input!=4&&input!=0);
}







void Display_one_product(Product* product)
{
	printf("\n\n");
	printf("商品编号:%d\n", product->ID);
	printf("商品名称:%s\n", product->name);
	printf("商品进价:%.2f\n", product->cost_price);
	printf("商品售价:%.2f\n", product->sell_price);
	printf("商品销售量:%d\n", product->sales_volume);
	printf("商品库存量:%d\n", product->stock);
	printf("销售额：%.2f\n", product->sales_revenue);
	printf("毛利：%.2f\n", product->profit);
	printf("\n\n");
}
void Find_by_name(Product* product[100], char* name, int* count)
{
	int flag = 0;
	int i = 0;
	for (i = 0; i < *count; i++)
	{
		if (strcmp(name, product[i]->name)==0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
	{
		printf("\n\n");
		printf("找到了，信息如下：\n\n");
		Display_one_product(product[i]);
	}
	else {
		printf("没有找到\n");
	}
}
void Find_by_stock(Product* product[100], int stock, int* count)
{
	int choice;
	int flag = 0;
	int i = 0;
	printf("请选择查询条件：\n1.大于\n2.小于\n3.等于");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		for (int i = 0; i < *count; i++)
		{
			if (product[i]->stock > stock)
				Display_one_product(product[i]);
		}
		break;
	case 2:
		for (int i = 0; i < *count; i++)
		{
			if (product[i]->stock < stock)
				Display_one_product(product[i]);
		}
		break;
	case 3:
		for (int i = 0; i < *count; i++)
		{
			if (product[i]->stock == stock)
				Display_one_product(product[i]);
		}
		break;
	}
}

void Find_product(Product* product[100], int* count)
{
	int input = 0;
	int stock = 0;
	char name[20];
	do {
		menu2();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出系统\n");
			break;
		case 1:
			printf("请输入要查询的品名：");
			scanf("%s", name);
			Find_by_name(product,name,count);
			break;
		case 2:
			printf("请输入要查询的库存数量：");
			scanf("%d", &stock);
			Find_by_stock(product, stock, count);
			break;
		case 3:
			printf("返回主菜单\n");
			break;
		}
	} while (input != 3 && input != 0);
}

