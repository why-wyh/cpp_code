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
		wprintf(WALL) ;
	}
	Set_Pos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(WALL);
	}
	for(i=1;i<=25;i++)
	{
		Set_Pos(0, i);
		wprintf(WALL);
	}
	for (i = 1; i <= 25; i++)
	{
		Set_Pos(56, i);
		wprintf(WALL);
	}

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
void Init_Snake(pSnake snake)
{
    for (int i = 0; i < 5; i++)
    {
        pSNode cur = (pSNode)malloc(sizeof(SNode));
        if (cur == NULL)
        {
            perror("InitSnake::malloc");
            exit(EXIT_FAILURE); 
        }
        cur->x = 24 + i * 2;
        cur->y = 5;
        cur->next = NULL;
        if (snake->head == NULL)
        {
            snake->head = cur;
        }
        else
        {
            cur->next = snake->head;
            snake->head = cur;
        }
    }
    pSNode cur = snake->head;
    while (cur)
    {
        Set_Pos(cur->x, cur->y);
        wprintf(BODY);
        cur = cur->next;
    }
}
void Create_food(pSnake snake)
{
	int x, y;
	agin:
	do 
	{
		x = rand() % 55 + 2;
	    y = rand() % 25 + 1;
	} while (x % 2);
	pSNode cur = snake->head;
	while (cur)
	{
		if (cur->x == x && cur->y == y)
			goto agin;
		else
			cur = cur->next;
	}
	pSNode PFood= (SNode*)malloc(sizeof(SNode));
	if (PFood == NULL)
	{
		perror("Create_food::malloc()");
		exit(1);
	}
	PFood->x = x;
	PFood->y = y;
	PFood->next = NULL;
	snake->food = PFood;
	Set_Pos(PFood->x, PFood->y);
	wprintf(FOOD);
}
void Set_Snake(pSnake snake)
{
	snake->dirt = right;
	snake->food_wight = 10;
	snake->scor = 0;
	snake->sleep_time = 200;
	snake->statement = ok;
}
void GameStart(pSnake snake)
{
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	Welcom_To_Game();
	Creat_Map();
	Init_Snake(snake);
	Create_food(snake);
	Set_Snake(snake);
}
void GameRun(pSnake snake)
{
	;
}
