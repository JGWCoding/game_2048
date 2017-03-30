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

//��Ϸ���ڴ�С
const int ROW = 4;   //����
const int COL = 4;	 //����
int game[ROW][COL] = { 0 };  //ÿ�����ϵ���

//������������
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

//��Ϸ����״̬
const int GAME_OVER = 1;
const int GAME_WIN = 2;
const int GAME_CONTINUE = 3;

//ÿ�������ϵ�����
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

//��ӡ��Ϸ����
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

//����һ������
bool CreateNumber()
{
	int x = -1;
	int y = -1;
	int times = 0;
	int maxTimes = ROW * COL;

	//����֮����������2������֮һ��������4
	do 
	{
		x = rand() % ROW;
		y = rand() % COL;
		++times;
	} while (game[x][y] != 0 && times <= maxTimes);

	//�����������
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

//����
void Process(int direction)
{
	switch (direction)
	{
	case UP:
		//ִ�����ϲ���
		//������һ�в���
		for (int row = 1; row < ROW; ++row)
		{

		}
	}
}

//�������������������������
int Input()
{
	//��ȡ���������ĸ������
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

//�ж���Ϸ״̬
int judge()
{
	//Ӯ����Ϸ
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

	//������
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

	//������
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

	//��������������������Ϸ����
	return GAME_OVER
}