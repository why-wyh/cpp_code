#define _CRT_SECURE_NO_WARNINGS 
#include"Smart_Ptr.h"
int main()
{
	int a = 9;
	why::Share_ptr <int>s1(new int);
	*s1 = 10;
	why::Share_ptr <int>s2(s1);
	return 0;
}