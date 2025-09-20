#define _CRT_SECURE_NO_WARNINGS 
#include "Snake.h"
void test()
{
	Snake snake = { 0 };
	GameStart(&snake);

}


int main()
{
	setlocale(LC_ALL, "");
	test();
	return 0;
}