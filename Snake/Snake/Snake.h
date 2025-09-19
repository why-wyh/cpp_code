#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<Windows.h>
enum driction
{
	up = 1,
	down,
	left,
	right
};
enum game_state
{
	normal,
	die_wall,
	die_self,

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

}snake,* psnake;

void GameStart();
void GameRun();
void GameEnd();