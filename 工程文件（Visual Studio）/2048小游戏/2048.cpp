#include <iostream>  
#include <windows.h>  
#include <ctime>  
using namespace std;

int const ROW = 4;
int const COL = 4;
int game[ROW][COL] = { 0 };

//上下左右  
int const UP = 1;
int const DOWN = 2;
int const LEFT = 3;
int const RIGHT = 4;

//游戏所处的状态  
int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;

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
};

//打印所得的数组  
void Print()
{
	system("cls");
	cout << "*****************  2048 控 制 台 版  ******************" << endl;
	cout << "*****************  By Tanzf (Intern) ******************" << endl << endl;
	for (int i = 0; i < ROW; ++i)
	{
		cout << "---------------------------------" << endl;
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 0)
			{
				cout << "|   \t";
			}
			else
			{
				cout << "|   " << game[i][j] << "\t";
			}
		}
		cout << "|" << endl;
	}
	cout << "---------------------------------" << endl;
}


bool CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW * COL;
	//三分之二的概率生成2，三分之一的概率生成4  
	int whitch = rand() % 3;
	do
	{
		x = rand() % ROW;
		y = rand() % COL;
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//说明格子已经满了  
	if (times >= maxTimes)
	{
		return false;
	}
	else
	{
		GameNum num;
		if (whitch == 0)
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

void Process(int direction)
{
	switch (direction)
	{
	case UP:
		//最上面一行不动  
		for (int row = 1; row < ROW; ++row)
		{
			for (int crow = row; crow >= 1; --crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//上一个格子为空  
					if (game[crow - 1][col] == 0)
					{
						game[crow - 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//合并  
						if (game[crow - 1][col] == game[crow][col])
						{
							game[crow - 1][col] *= 2;
							game[crow][col] = 0;
						}

					}
				}
			}
		}
		break;
	case DOWN:
		//最下面一行不动  
		for (int row = ROW - 2; row >= 0; --row)
		{
			for (int crow = row; crow < ROW - 1; ++crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//上一个格子为空  
					if (game[crow + 1][col] == 0)
					{
						game[crow + 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//合并  
						if (game[crow + 1][col] == game[crow][col])
						{
							game[crow + 1][col] *= 2;
							game[crow][col] = 0;
						}

					}
				}
			}
		}
		break;
	case LEFT:
		//最左边一列不动  
		for (int col = 1; col < COL; ++col)
		{
			for (int ccol = col; ccol >= 1; --ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//上一个格子为空  
					if (game[row][ccol - 1] == 0)
					{
						game[row][ccol - 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//合并  
						if (game[row][ccol - 1] == game[row][ccol])
						{
							game[row][ccol - 1] *= 2;
							game[row][ccol] = 0;
						}

					}
				}
			}
		}
		break;
	case RIGHT:
		//最右边一列不动  
		for (int col = COL - 2; col >= 0; --col)
		{
			for (int ccol = col; ccol <= COL - 2; ++ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//上一个格子为空  
					if (game[row][ccol + 1] == 0)
					{
						game[row][ccol + 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//合并  
						if (game[row][ccol + 1] == game[row][ccol])
						{
							game[row][ccol + 1] *= 2;
							game[row][ccol] = 0;
						}

					}
				}
			}
		}
		break;
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
int Judge()
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
	for (int j = 0; j< COL; ++j)
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

	//不符合上述两种状况，游戏结束  
	return GAME_OVER;

}

int main()
{
	srand((unsigned int)time(0));  //设置一个随机数种子  
	CreateNumber();  //创建一个随机数
	CreateNumber();  //创建一个随机数
	Print();         //打印游戏屏幕
	int direction = 0;  //默认无输入，方向为0
	int gameState = -1; //默认游戏开始，状态代码为0
	while (true)  //执行游戏循环
	{
		direction = Input(); //获取用户输入的方向，并转换为方向代码

		gameState = Judge(); //在根据方向代码进行变换之前，判断游戏状态
		if (direction && gameState == GAME_CONTINUE)  //如果有合法的方向代码并且还没有GameOVer
		{
			Process(direction); //根据方向代码进行转换
			CreateNumber();  //创建一个随机数
			Print();  //打印屏幕
			Sleep(100); //程序睡眠100毫秒
		}
		else if (gameState == GAME_WIN)  //如果游戏胜利
		{
			Print(); //打印游戏窗口
			cout << "You Win！" << endl; //输出“胜利”提示
			break; //跳出游戏主循环，游戏结束
		}
		else if (gameState == GAME_OVER) //如果游戏失败
		{
			Print(); //打印游戏窗口
			cout << "You lose!" << endl; //输出"失败"提示
			break; //跳出游戏主循环，游戏结束
		}
	}

	return 0;
}