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
		x = rand() % 53 + 2;
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
void printhelpinfo()
{
	Set_Pos(64, 15);
	wprintf(L"不能穿墙，不能咬到自己\n");
	Set_Pos(64, 16);
	wprintf(L"用↑↓←→控制蛇的移动\n");
	Set_Pos(64, 17);
	wprintf(L"F3为加速F4为减速\n");
	Set_Pos(64, 18);
	wprintf(L"加速能获得更高的分数\n");
	Set_Pos(64, 19);
	wprintf(L"ESC退出游戏，空格暂停游戏\n");
}
void EatFood(pSnake snake, pSNode net)
{
	net->next = snake->head;
	snake->head = net;
	pSNode cur = snake->head;
	while (cur)
	{
		Set_Pos(cur->x, cur->y);
		wprintf(BODY);
		cur = cur->next;
	}
	snake->scor += snake->food_wight;
	Create_food(snake);
}
void NoFood(pSnake snake, pSNode net)
{
	net->next = snake->head;
	snake->head = net;
	pSNode cur = snake->head;
	while (cur->next->next)
	{
		Set_Pos(cur->x, cur->y);
		wprintf(BODY);
		cur = cur->next;
	}
	Set_Pos(cur->next->x, cur->next->y);
	wprintf(L" ");
	free(cur->next);
	cur->next = NULL;
}
int NextIsFood(pSnake snake,pSNode net)
{
	return((snake->food->x == net->x) && (snake->food->y == net->y));
}
void pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
			break;
	}
}
void killbyself(pSnake snake)
{
	pSNode cur = snake->head->next;
	while (cur)
	{
		if (cur->x == snake->head->x && cur->y == snake->head->y)
		{
			snake->statement = die_self;
		}
		cur = cur->next;
	}
}
void killbywall(pSnake snake)
{
	if ((snake->head->x == 0)
		|| (snake->head->x == 56)
		|| (snake->head->y == 0)
		|| (snake->head->y == 26))
	{
		snake->statement = die_wall;
	}
}
void Snake_Move(pSnake snake,pSNode net)
{
	switch (snake->dirt)
	{
	case up:
		net->x = snake->head->x;
		net->y = snake->head->y - 1;
		break;
	case down:
		net->x = snake->head->x;
		net->y = snake->head->y +1;
		break;
	case left:
		net->x = snake->head->x-2;
		net->y = snake->head->y;
		break;
	case right:
		net->x = snake->head->x + 2;
		net->y = snake->head->y;
		break;
	}
	if (NextIsFood(snake, net))
	{
		EatFood(snake, net);
	}
	else
	{
		NoFood(snake, net);
	}
	killbyself(snake);
	killbywall(snake);
	Sleep(snake->sleep_time);
	

}
void GameRun(pSnake snake)
{
	do 
	{
		printhelpinfo();
		Set_Pos(64, 10);
		wprintf(L"得分：%2d ", snake->scor);
		Set_Pos(64, 11);
		wprintf(L"每个食物得分;%d分", snake->food_wight);

		if (KEY_PRESS(VK_UP) && snake->dirt != down)
			snake->dirt = up;
		else if (KEY_PRESS(VK_DOWN) && snake->dirt != up)
			snake->dirt = down;
		else if (KEY_PRESS(VK_RIGHT) && snake->dirt != left)
			snake->dirt = right;
		else if (KEY_PRESS(VK_LEFT) && snake->dirt != right)
			snake->dirt = left;
		else if (KEY_PRESS(VK_SPACE))
			pause();
		else if (KEY_PRESS(VK_F3))
		{
			if (snake->sleep_time > 110)
			{
				snake->sleep_time -= 30;
				snake->food_wight += 3;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (snake->food_wight > 1)
			{
				snake->sleep_time += 30;
				snake->food_wight -= 3;
			}
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			snake->statement = end_normal;
		}
		pSNode next = (pSNode)malloc(sizeof(SNode));
		Snake_Move(snake,next);
	}
	while(snake->statement==ok);
}
void GameEnd(pSnake snake)
{
	pSNode cur = snake->head;
	Set_Pos(24, 12);
	switch (snake->statement)
	{
	case end_normal:
		wprintf(L"退出游戏\n");
		break;
	case die_self:
		wprintf(L"您咬到了自己\n");
		break;
	case die_wall:
		wprintf(L"您撞到了墙\n");
		break;
	}
	Set_Pos(24, 13);
	wprintf(L"最终得分为：%d", snake->scor);
	while (cur)
	{
		pSNode del = cur;
		cur = cur->next;
		free(del);
	}
	snake->head = NULL;
	if (snake->food)
	{
		free(snake->food);
		snake->food = NULL;
	}
	snake->scor = 0;
	snake->statement = end_normal;
}