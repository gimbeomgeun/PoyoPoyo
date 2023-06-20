/*헤더파일*/
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

/*상수*/
#define AREA_ROW 14 //0번째 줄 위 빈 공간, 13번째 줄 바닥 블록
#define AREA_COL 8 //양 끝 벽
//실제 보이는 게임 공간은 12*6 -> [1~12][1~6]

/*변수*/
int testArea[AREA_ROW][AREA_COL] = { 0, };
int nowArea[AREA_ROW][AREA_COL] = { 0, };
int poyo[2][2] = { 0 };

/*함수 원형 선언*/
void createArea();	//맵 생성?
void printArea();	//맵 출력
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