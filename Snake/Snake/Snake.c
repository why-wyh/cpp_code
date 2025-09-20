#define _CRT_SECURE_NO_WARNINGS 
#include "Snake.h"
void Set_Pos(short x,short y)
{
	//设置光标位置
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
void Creat_Map()
{
	int i = 0;
	Set_Pos(0, 0);
	for (i = 0; i < 29;i++)
	{
		wprintf(L"□") ;
	}
	Set_Pos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"□");
	}
	for(i=1;i<=25;i++)
	{
		Set_Pos(0, i);
		wprintf(L"□");
	}
	for (i = 1; i <= 25; i++)
	{
		Set_Pos(56, i);
		wprintf(L"□");
	}
	system("pause");

}
void Welcom_To_Game()
{
	//隐藏光标。
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOutput, &CursorInfo);
	Set_Pos(38,14);
	wprintf(L"欢迎来到贪吃蛇小游戏");
	Set_Pos(40, 25);
	system("pause");
	system("cls");
	Set_Pos(34, 12);
	wprintf(L"用↑↓←→控制蛇的方向，F3为加速，F4为减速！");
	Set_Pos(34, 14);
	wprintf(L"加速能获得更高的分数");
	Set_Pos(40, 25);
	system("pause");
	system("cls");
}

void GameStart(pSnake snake)
{
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	Welcom_To_Game();
	Creat_Map();

}