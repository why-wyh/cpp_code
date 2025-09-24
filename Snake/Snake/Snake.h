#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>
#include<Windows.h>
#include<time.h>
#define  BODY L"¡ñ"
# define WALL L"¡õ"
# define FOOD L"¡ø"
#define KEY_PRESS(VK)  ( (GetAsyncKeyState(VK) & 0x1) ? 1 : 0 )
enum driction
{
	up = 1,
	down,
	left,
	right
};
enum game_state
{
	ok,
	die_wall,
	die_self,
	end_normal

};
typedef struct SNode
{
	int x;
	int y;
	struct SNode* next;
}SNode,* pSNode;
typedef struct snake
{
	pSNode head;
	pSNode food;
	enum driction dirt;
	enum game_state statement;
	int food_wight;
	int scor;
	int sleep_time;

}Snake,* pSnake;

void GameStart(pSnake snake);

void Set_Pos(short x,short y);

void Creat_Map();

void Init_Snake(pSnake snake);

void Create_food(pSnake snake);

void Set_Snake(pSnake snake);

void Welcom_To_Game();

int NextIsFood(pSnake snake, pSNode net);

void Snake_Move(pSnake snake, pSNode net);

void GameRun(pSnake snake);

void GameEnd(pSnake snake);