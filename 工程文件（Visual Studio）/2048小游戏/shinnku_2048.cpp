//shinnku 2048

#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

//游戏窗口大小
const int ROW = 4;   //行数
const int COL = 4;	 //列数
int game[ROW][COL] = { 0 };  //每个格上的数

//定义上下左右
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

//游戏运行状态
const int GAME_OVER = 1;
const int GAME_WIN = 2;
const int GAME_CONTINUE = 3;

//每个格子上的数字
enum GameNum
{
	Game_2 = 2,
	Game_4 = 4,
	Game_8 = 8,
	Game_16 = 16,
	Game_32 = 32,
	Game_64 = 64,
	Game_128 = 128,
	Game_256 = 256,
	Game_512 = 512,
	Game_1024 = 1024,
	Game_2048 = 2048,
	Game_4096 = 4096,
	Game_8192 = 8192,
};

//打印游戏窗口
void print()
{
	system("cls");
	cout << "**************2048*****************" << endl;

	for (int i = 0; i < ROW; ++i)
	{
		cout << "----------------------------" << endl;
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 0)
			{
				cout << "|	\t";
			}
			else
			{
				cout << "|	" << game[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "|" << endl;
	cout << "-------------------------------" << endl;
}

//创建一个数字
bool CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW * COL;

	//三分之二概率生成2，三分之一概率生成4
	do 
	{
		x = rand() % ROW;
		y = rand() % COL;
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//如果格子满了
	if (times >= maxTimes)
	{
		return false;
	}
	else
	{
		GameNum num;
		if (widtch = 0)
		{
			num = Game_4;
		}
		else if (whitch)
		{
			num = Game_2;
		}
		game[x][y] = num;
	}

	return true;
}

//过程
void Process(int direction)
{
	switch (direction)
	{
	case UP:
		//执行向上操作
		//最上面一行不动
		for (int row = 1; row < ROW; ++row)
		{

		}
	}
}

//处理输入输出，返回上下左右
int Input()
{
	//读取上下左右四个方向键
	int upArrow = 0;
	int downArrow = 0;
	int leftArrow = 0;
	int rightArrow = 0;
	int direction = 0;

	while (true)
	{
		upArrow = GetAsyncKeyState(VK_UP);
		downArrow = GetAsyncKeyState(VK_DOWN);
		leftArrow = GetAsyncKeyState(VK_LEFT);
		rightArrow = GetAsyncKeyState(VK_RIGHT);

		if (upArrow)
		{
			direction = UP;
			break;
		}
		else if (downArrow)
		{
			direction = DOWN;
			break;
		}
		else if (leftArrow)
		{
			direction = LEFT;
			break;
		}
		else if (rightArrow)
		{
			direction = RIGHT;
			break;
		}

		Sleep(100);
	}

	return direction;
}

//判断游戏状态
int judge()
{
	//赢得游戏
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 2048)
			{
				return GAME_WIN;
				break;
			}
		}
	}

	//横向检查
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL - 1; ++j)
		{
			if (!game[i][j] || (game[i][j] == game[i][j + 1]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}

	//纵向检查
	for (int j = 0; j < COL; ++j)
	{
		for (int i = 0; i < ROW - 1; ++i)
		{
			if (!game[i][j] || (game[i][j] == game[i + 1][j]))
			{
				return GAME_CONTINUE;
				break;
			}
		}
	}

	//不符合上面的情况，则游戏结束
	return GAME_OVER
}