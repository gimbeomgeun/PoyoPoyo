/*�������*/
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

/*���*/
#define AREA_ROW 14 //0��° �� �� �� ����, 13��° �� �ٴ� ���
#define AREA_COL 8 //�� �� ��
//���� ���̴� ���� ������ 12*6 -> [1~12][1~6]

/*����*/
int testArea[AREA_ROW][AREA_COL] = { 0, };
int nowArea[AREA_ROW][AREA_COL] = { 0, };
int poyo[2][2] = { 0 };


enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

/*�Լ� ���� ����*/
void createArea();	//�� ����?
void printArea();	//�� ���
void spawnPoyo();
void downPoyo(int x,int y);
void putPoyo(int x, int y);
void clearPoyo(int x, int y);
int isCrash(int x, int y);
void saveArea();
void returnArea();
int setColor(int n);

int main()
{
	srand(time(NULL));
	createArea();
	printArea();
	spawnPoyo();
}
void createArea()
{
	for (int i = 0; i < AREA_COL; i++)
	{
		testArea[13][i] = -1;
	}
	for (int i = 0; i < AREA_ROW; i++)
	{
		testArea[i][0] = testArea[i][7] = -1;
	}
}
void printArea()
{
	system("cls");
	/*for (int i = 0; i < AREA_ROW; i++)
	{
		for (int j = 0; j < AREA_COL; j++)
		{
			printf("%d ", nowArea[i][j]);
		}
		printf("\n");
	}*/
	for (int i = 1; i < AREA_ROW - 1; i++)
	{
		for (int j = 1; j < AREA_COL - 1; j++)
		{
			switch (nowArea[i][j])
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				printf("��");
				break;
			default:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor(nowArea[i][j]));
				printf("��");
				break;
			}
		}
		printf("\n");
	}
}
void spawnPoyo()
{
	poyo[0][0] = rand()%4+1;
	poyo[0][1] = rand()%4+1;
	downPoyo(3, 0);
}
void downPoyo(int x,int y)
{
	putPoyo(x, y);
	if (isCrash(x, y))
	{
		printf("1");
		spawnPoyo();
	}
	printArea();
	clearPoyo(x, y);
	time_t start_time = time(NULL);
	while (1)
	{
		time_t now_time = time(NULL);
		if (now_time - start_time >= 1)     //1�ʵ���
		{
			break;
		}
	}
	downPoyo(x, y + 1);
}
void putPoyo(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			testArea[i + y][j + x] += poyo[i][j];
		}
	}
}
void clearPoyo(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (poyo[i][j] == 0)
				continue;
			testArea[i + y][j + x] = 0;
		}
	}
}
int isCrash(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (poyo[i][j] == 0)
				continue;
			if (poyo[i][j] != testArea[i + y][j + x])	//�浹���� �� 1 ��ȯ
			{
				returnArea();
				return 1;
			}
		}
	}
	saveArea();
	return 0;
}
void saveArea()
{
	for (int i = 0; i < AREA_ROW; i++)
	{
		for (int j = 0; j < AREA_COL; j++)
		{
			nowArea[i][j] = testArea[i][j];
		}
	}
}
void returnArea()
{
	for (int i = 0; i < AREA_ROW; i++)
	{
		for (int j = 0; j < AREA_COL; j++)
		{
			testArea[i][j] = nowArea[i][j];
		}
	}
}

int setColor(int n)
{
	switch (n)
	{
	case 1:
		return RED;
	case 2:
		return GREEN;
	case 3:
		return YELLOW;
	case 4:
		return VIOLET;
	}
}