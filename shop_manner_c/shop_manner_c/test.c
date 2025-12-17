#define _CRT_SECURE_NO_WARNINGS 
#include"shop.h"
int main()
{
	Product product[100] = {0};
	int product_count = 0;
	int input = 0;
	do {
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出系统\n");
			break;
		case 1:
			break;
		case 2:
			Creat_product(product, &product_count);
			break; 
		case 3:
				break;
		case 4:
			Find_product(product, &product_count);
			break;
		case 5:
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);

	return 0;
}