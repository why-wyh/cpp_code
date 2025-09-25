#define _CRT_SECURE_NO_WARNINGS 
#include "Snake.h"

void test()
{
    char ch;
    do
    {
        system("cls");
        Snake snake = { 0 };
        GameStart(&snake);
        GameRun(&snake);
        GameEnd(&snake);

        Set_Pos(24, 14);
        wprintf(L"是否要再来一局（Y/N）：");
        ch = getchar();
        // 清理输入缓冲区
        while (getchar() != '\n');

        // 非法输入处理
        while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n')
        {
            Set_Pos(24, 15);
            wprintf(L"请输入 Y 或 N：");
            ch = getchar();
            while (getchar() != '\n');
        }
        system("cls");
    } while (ch == 'Y' || ch == 'y');
}

int main()
{
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));
    test();
    return 0;
}