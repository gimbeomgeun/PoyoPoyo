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

/*�Լ� ���� ����*/
void createArea();	//�� ����?
void printArea();	//�� ���
void spawnPoyo();
void downPoyo(int x,int y);
void putPoyo(int x, int y);
int main()
{
	srand(time(NULL));
	createArea();
	printArea();
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
	for (int i = 0; i < AREA_ROW; i++)
	{
		for (int j = 0; j < AREA_COL; j++)
		{
			printf("%d ", testArea[i][j]);
		}
		printf("\n");
	}
}
void spawnPoyo()
{
	poyo[0][0] = rand(1, 4);
	poyo[0][1] = rand(1, 4);
}
void downPoyo(int x,int y)
{
	
}
void putPoyo(int x, int y)
{

}