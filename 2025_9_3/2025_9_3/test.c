#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"

void testContact1()
{
	Contact con;
	ContactInit(&con);
	addContact(&con);
	addContact(&con);
	showContact(&con);
	//FindContact(&con);
	//delContact(&con);
	//showContact(&con);
	ModifyContact(&con);
	showContact(&con);
}
int main()
{
	
	testContact1();
	return 0;
}