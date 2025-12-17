#pragma once
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct product {
	int ID;
	char name[20];
	float cost_price;
	float sell_price;
	int stock;
	int sales_volume;
	float sales_revenue;
	float profit;
};
typedef struct product Product;
void Creat_product(Product* product[100],int* count);
void Add_new_product(Product* product[100], int* count);
void Delete_product(Product* product[100], int id,int *count);
void Change_product(Product* product[100], int id, int*count);
void Find_product(Product* product[100], int* count);
void Find_by_name(Product* product[100], char* name, int* count);
void Find_by_stock(Product* product[100], int stock, int* count);
void Display_product(Product* product[100], int count);
void Display_by_nothing(Product* product[100], int count);
void Display_sales_revenue(Product* product[100],int count);
void Display_profit(Product* product[100], int count);
void Statistics_product(Product* product[100], int count);





