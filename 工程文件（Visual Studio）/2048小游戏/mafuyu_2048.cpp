#include <iostream>
#include <windows.h>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void InitGame(); //��Ϸ��ʼ������
int Input(); //��ȡ�û����뺯��
int Judge(); //�ж���Ϸ״������
void Process(int);  //��Ϸ��������
bool CreateNumber(); //����һ�����������
void printGame(); //��ӡ��Ϸ���ں���

////�洢����������Ϸ״������ı���
//int direction;
//int gameState;

//�������
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;

//��Ϸ״������
const int GameContinue = 0;
const int GameOver = -1;
const int GameWin = 1;

//��Ϸ��Ļ
const int ROW = 4;
const int COL = 4;
int game[ROW][COL] = {0};

int main()
{
	//InitGame();   //��ʼ����Ϸ

	srand((unsigned int)time(0));
	CreateNumber();
	CreateNumber();
	printGame();

	int direction = 0;
	int gameState = 0;

	//��Ϸѭ��
	while (true)
	{
		direction = Input(); //��ȡ�û����룬��ת��Ϊ�������

		gameState = Judge(); //�ж���Ϸ״������������Ϸ״������

		//���ݷ��������Ϸ״��������ִ����Ӧ�Ĳ���
		//�����Ϸ��û�н����ҷ������Ϸ�
		if (direction && gameState == GameContinue)
		{
			Process(direction); //���ݷ������ִ����Ӧ�Ĳ���
			CreateNumber(); //����һ���µ�������������������Ŀտռ�
			printGame(); //��ӡ��Ϸ����
			Sleep(100); //����Ļͣ��100����,������ײ�ϲ���Ч��
		}
		else if (gameState == GameOver)
		{
			printGame(); //��ӡ��Ϸ����
			cout << "You lose" << endl; //��ӡʧ����Ϣ
			break; //������Ϸѭ������Ϸ����
		}
		else if (gameState == GameWin)
		{
			printGame(); //��ӡ��Ϸ����
			cout << "You win" << endl; //��ӡʤ����Ϣ
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
	//direction = 0; //���÷������

	//��ʼ������״̬��Ĭ���κμ���û�а��£�
	int upButton = 0;
	int downButton = 0;
	int leftButton = 0;
	int rightButton = 0;
	int direction = 0;

	while (true) //һֱ��ȡ���룬ֱ���к��ʵ�����Ϊֹ
	{
		upButton = GetAsyncKeyState(VK_UP);
		downButton = GetAsyncKeyState(VK_DOWN);
		leftButton = GetAsyncKeyState(VK_LEFT);
		rightButton = GetAsyncKeyState(VK_RIGHT);

		if (upButton) //��������ϼ�
		{
			direction = UP; //�������Ϊ���ϡ�
			break; //��ȡ�ɹ�
		}
		else if (downButton) //��������¼�
		{
			direction = DOWN; //�������Ϊ���¡�
			break; //��ȡ�ɹ�
		}
		else if (leftButton) //����������
		{
			direction = LEFT; //�������Ϊ����
			break; //��ȡ�ɹ�
		}
		else if (rightButton) //��������Ҽ�
		{
			direction = RIGHT; //�������Ϊ���ҡ�
			break;	//��ȡ�ɹ�
		}

		Sleep(100); //����������룬���100ms
	}

	return direction;
}

int Judge()
{
	//��Ϸʤ��
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

	//����Ƿ��ܹ�����ϲ�
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

	//����Ƿ��ܹ�����ϲ�
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

	//����Ƿ��пո�
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

	//��������������״������Ϸ����  
	return GameOver;

}

void Process(int direction)
{
	switch (direction)
	{
	case UP:
		//������һ�в���  
		for (int row = 1; row < ROW; ++row)
		{
			for (int crow = row; crow >= 1; --crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//��һ������Ϊ��  
					if (game[crow - 1][col] == 0)
					{
						game[crow - 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//�ϲ�  
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
		//������һ�в���  
		for (int row = ROW - 2; row >= 0; --row)
		{
			for (int crow = row; crow < ROW - 1; ++crow)
			{
				for (int col = 0; col < COL; ++col)
				{
					//��һ������Ϊ��  
					if (game[crow + 1][col] == 0)
					{
						game[crow + 1][col] = game[crow][col];
						game[crow][col] = 0;
					}
					else
					{
						//�ϲ�  
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
		//�����һ�в���  
		for (int col = 1; col < COL; ++col)
		{
			for (int ccol = col; ccol >= 1; --ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//��һ������Ϊ��  
					if (game[row][ccol - 1] == 0)
					{
						game[row][ccol - 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//�ϲ�  
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
		//���ұ�һ�в���  
		for (int col = COL - 2; col >= 0; --col)
		{
			for (int ccol = col; ccol <= COL - 2; ++ccol)
			{
				for (int row = 0; row < ROW; ++row)
				{
					//��һ������Ϊ��  
					if (game[row][ccol + 1] == 0)
					{
						game[row][ccol + 1] = game[row][ccol];
						game[row][ccol] = 0;
					}
					else
					{
						//�ϲ�  
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
	int x = 0; //������
	int y = 0; //������

	int times = 0;
	int maxTime = ROW * COL;
	
	do	
	{
		x = rand() % ROW;  //����һ������X����
		y = rand() % COL;  //����һ������Y����
		++times;
	} while (game[x][y] != 0 && times <= maxTime); //һֱѭ����ֱ���ҵ��ո���Ϊֹ

	if (times >= maxTime)
	{
		return false;
	}

	/*
		temp ������������ֱ�Ϊtemp = 0 ,temp = 1, temp = 2;
		���ʷֱ�Ϊ1/3
	*/
	int temp = rand() % 3; 

	if (temp == 0) // 1/3�ĸ���
		game[x][y] = 4; //��������֮һ�ĸ�������4
	else if (temp == 1 || temp == 2) //2/3�ĸ���
		game[x][y] = 2; //��������֮���ĸ�������2

	return true;
}

void printGame() 
{
	//����Ļ�������
	system("cls");

	//��ӡ��Ϸ���ֺ�������
	cout << "*****************************************************************" << endl;
	cout << "*                         2048С��Ϸ                            *" << endl;
	cout << "*                produce by foreverrainbowlight                 *" << endl;
	cout << "*****************************************************************" << endl;
	cout << endl;

	//����Ϊ��׼���д�ӡ
	for (int i = 0; i < ROW; ++i)
	{
		cout << "-----------------------------------------------------------------" << endl;
		//�ڵ�i�д�ӡ��
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