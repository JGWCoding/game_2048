#include <iostream>
#include <windows.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void InitGame(); //游戏初始化函数
int Input(); //获取用户输入函数
int Judge(); //判断游戏状况函数
void Process(int);  //游戏操作过程
bool CreateNumber(); //创建一个随机数函数
void printGame(); //打印游戏窗口函数

////存储方向代码和游戏状况代码的变量
//int direction;
//int gameState;

//方向代码
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

//游戏状况代码
const int GameContinue = 0;
const int GameOver = -1;
const int GameWin = 1;

//游戏屏幕
const int ROW = 4;
const int COL = 4;
int game[ROW][COL] = {0};

int main()
{
	//InitGame();   //初始化游戏

	srand((unsigned int)time(0));
	CreateNumber();
	CreateNumber();
	printGame();

	int direction = 0;
	int gameState = 0;

	//游戏循环
	while (true)
	{
		direction = Input(); //获取用户输入，并转换为方向代码

		gameState = Judge(); //判断游戏状况，并返回游戏状况代码

		//根据方向代码游戏状况代码来执行相应的操作
		//如果游戏还没有结束且方向代码合法
		if (direction && gameState == GameContinue)
		{
			Process(direction); //根据方向代码执行相应的操作
			CreateNumber(); //产生一个新的随机数，随机放入数组的空空间
			printGame(); //打印游戏窗口
			Sleep(100); //另屏幕停顿100毫秒,产生相撞合并的效果
		}
		else if (gameState == GameOver)
		{
			printGame(); //打印游戏窗口
			cout << "You lose" << endl; //打印失败信息
			break; //跳出游戏循环，游戏结束
		}
		else if (gameState == GameWin)
		{
			printGame(); //打印游戏窗口
			cout << "You win" << endl; //打印胜利信息
			break;
		}
	}

	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	system("pause");
	return 0;
}

//void InitGame()
//{
//	srand((unsigned int)time(0));
//	CreateNumber();
//	CreateNumber();
//	printGame();
//}

int Input()
{
	//direction = 0; //重置方向代码

	//初始化按键状态（默认任何键都没有按下）
	int upButton = 0;
	int downButton = 0;
	int leftButton = 0;
	int rightButton = 0;
	int direction = 0;

	while (true) //一直读取输入，直到有合适的输入为止
	{
		upButton = GetAsyncKeyState(VK_UP);
		downButton = GetAsyncKeyState(VK_DOWN);
		leftButton = GetAsyncKeyState(VK_LEFT);
		rightButton = GetAsyncKeyState(VK_RIGHT);

		if (upButton) //如果按下上键
		{
			direction = UP; //方向代码为“上”
			break; //读取成功
		}
		else if (downButton) //如果按下下键
		{
			direction = DOWN; //方向代码为“下”
			break; //读取成功
		}
		else if (leftButton) //如果按下左键
		{
			direction = LEFT; //方向代码为“左”
			break; //读取成功
		}
		else if (rightButton) //如果按下右键
		{
			direction = RIGHT; //方向代码为“右”
			break;	//读取成功
		}

		Sleep(100); //读入键盘输入，间隔100ms
	}

	return direction;
}

int Judge()
{
	//游戏胜利
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 2048)
			{
				return GameWin;
				break;
			}
		}
	}

	//检查是否能够横向合并
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL - 1; ++j)
		{
			if (game[i][j] == game[i][j + 1])
			{
				return GameContinue;
			}
		}
	}

	//检查是否能够纵向合并
	for (int j = 0; j< COL; ++j)
	{
		for (int i = 0; i < ROW - 1; ++i)
		{
			if(game[i][j] == game[i + 1][j])
			{
				return GameContinue;
			}
		}
	}

	//检查是否还有空格
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (!game[i][j])
			{
				return GameContinue;
			}
		}
	}

	//不符合上述三种状况，游戏结束  
	return GameOver;

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

bool CreateNumber()
{
	int x = 0; //横坐标
	int y = 0; //纵坐标

	int times = 0;
	int maxTime = ROW * COL;
	
	do	
	{
		x = rand() % ROW;  //产生一个随意X坐标
		y = rand() % COL;  //产生一个随意Y坐标
		++times;
	} while (game[x][y] != 0 && times <= maxTime); //一直循环，直到找到空格子为止

	if (times >= maxTime)
	{
		return false;
	}

	/*
		temp 有三种情况，分别为temp = 0 ,temp = 1, temp = 2;
		概率分别为1/3
	*/
	int temp = rand() % 3; 

	if (temp == 0) // 1/3的概率
		game[x][y] = 4; //即有三分之一的概率生成4
	else if (temp == 1 || temp == 2) //2/3的概率
		game[x][y] = 2; //即有三分之二的概率生成2

	return true;
}

void printGame() 
{
	//将屏幕进行清空
	system("cls");

	//打印游戏名字和作者名
	cout << "*****************************************************************" << endl;
	cout << "*                         2048小游戏                            *" << endl;
	cout << "*                produce by foreverrainbowlight                 *" << endl;
	cout << "*****************************************************************" << endl;
	cout << endl;

	//以行为基准进行打印
	for (int i = 0; i < ROW; ++i)
	{
		cout << "-----------------------------------------------------------------" << endl;
		//在第i行打印列
		for (int j = 0; j < COL; ++j)
		{
			if (game[i][j] == 0)
			{
				cout << "|		";
			}
			else
			{
				cout << "|	" << game[i][j] << "	";
			}
		}
		cout << "|" << endl;
	}
	cout << "-----------------------------------------------------------------" << endl;
}