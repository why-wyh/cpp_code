#define _CRT_SECURE_NO_WARNINGS 
#include "Snake.h"
void test()
{
	srand((unsigned int)time(NULL));
	Snake snake = { 0 };
	GameStart(&snake);
	GameRun(&snake);
}


int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	
	return 0;
}