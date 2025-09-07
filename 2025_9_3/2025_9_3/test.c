#define _CRT_SECURE_NO_WARNINGS 
#include"SeqList.h"
void testContact1(Contact*p)
{
   
	ContactInit(p);
	addContact(p);
	//addContact(p);
	showContact(p);
}
int main()
{
	Contact con;
	testContact1(&con);
	return 0;
}