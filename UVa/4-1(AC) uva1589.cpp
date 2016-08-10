/*
象棋问题，判断是否将死
查表
2016-8-7
edited by sunshine
*/
//1将的可移动位置。读取红棋不可移动后清零
/*
将军：不能出现在对面
车：如果没有阻隔不能出现在除自己所在位置外直线位置上
马：不能出现在自己的攻击范围
炮：不能出现在自己的攻击范围
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
//全局舍去数组0号下标
void canMove(int x, int y, int ch[11][10][2])
{//将左右移动位置
	//ch[x][y][1] = 1;
	if (x > 1)
		ch[x - 1][y][1] = 1;
	if (x < 10)
		ch[x + 1][y][1] = 1;
	if (y > 1)
		ch[x][y - 1][1] = 1;
	if (y < 9)
		ch[x][y + 1][1] = 1;
}
void solve(int ch[11][10][2])
{
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 9; j++) 
		{
			if (ch[i][j][0] == 'G')
			{
				for (int i1 = i - 1; i1 >= 1; i1--)
				{
					if (ch[i1][j][0] == 0)
						ch[i1][j][1] = 0;//不可移动
					else
					{
						ch[i1][j][1] = 0;//万一被帅吃了，实际攻击范围
						break;
					}
				}
			}
			else if (ch[i][j][0] == 'R')
			{
				for (int i1 = i - 1; i1 >= 1; i1--)
				{
					if (ch[i1][j][0] == 0)
						ch[i1][j][1] = 0;
					else
					{
						ch[i1][j][1] = 0;
						break;
					}
				}
				for (int i1 = i + 1; i1 <= 10; i1++)
				{
					if (ch[i1][j][0] == 0)
						ch[i1][j][1] = 0;
					else
					{
						ch[i1][j][1] = 0;
						break;
					}
				}
				for (int j1 = j - 1; j1 >= 1; j1--)
				{
					if (ch[i][j1][0] == 0)
						ch[i][j1][1] = 0;
					else
					{
						ch[i][j1][1] = 0;
						break;
					}
				}
				for (int j1 = j + 1; j1 <= 9; j1++)
				{
					if (ch[i][j1][0] == 0)
						ch[i][j1][1] = 0;
					else
					{
						ch[i][j1][1] = 0;
						break;
					}
				}
			}
			else if (ch[i][j][0] == 'C')
			{
				for (int begin = 0, i1 = i - 1; i1 >= 1; i1--)
				{
					if (ch[i1][j][0] == 0)
						if (begin == 0)
							continue;
						else
							ch[i1][j][1] = 0;
					else
						if (begin == 0)
							begin = 1;
						else
						{
							ch[i1][j][1] = 0;
							break;
						}
				}
				for (int begin = 0, i1 = i + 1; i1 <= 10; i1++)
				{
					if (ch[i1][j][0] == 0)
						if (begin == 0)
							continue;
						else
							ch[i1][j][1] = 0;
					else
						if (begin == 0)
							begin = 1;
						else
						{
							ch[i1][j][1] = 0;
							break;
						}
				}
				for (int begin = 0, j1 = j - 1; j1 >= 1; j1--)
				{
					if (ch[i][j1][0] == 0)
						if (begin == 0)
							continue;
						else
							ch[i][j1][1] = 0;
					else
						if (begin == 0)
							begin = 1;
						else
						{
							ch[i][j1][1] = 0;
							break;
						}
				}
				for (int begin = 0, j1 = j + 1; j1 <= 9; j1++)
				{
					if (ch[i][j1][0] == 0)
						if (begin == 0)
							continue;
						else
							ch[i][j1][1] = 0;
					else
						if (begin == 0)
							begin = 1;
						else
						{
							ch[i][j1][1] = 0;
							break;
						}
				}
			}
			else if (ch[i][j][0] == 'H')
			{
				if (i - 2 >= 1 && j - 1 >= 1 && ch[i - 1][j][0] == 0)//上左
					ch[i - 2][j - 1][1] = 0;
				if (i - 2 >= 1 && j + 1 <= 9 && ch[i - 1][j][0] == 0)//上右
					ch[i - 2][j + 1][1] = 0;
				if (i + 2 <= 10 && j - 1 >= 1 && ch[i + 1][j][0] == 0)//下左
					ch[i + 2][j - 1][1] = 0;
				if (i + 2 <= 10 && j + 1 <= 9 && ch[i + 1][j][0] == 0)//下右
					ch[i + 2][j + 1][1] = 0;
				if (j - 2 >= 1 && i - 1 >= 1 && ch[i][j - 1][0] == 0)//左上
					ch[i - 1][j - 2][1] = 0;
				if (j - 2 >= 1 && i + 1 <= 10 && ch[i][j - 1][0] == 0)//左下
					ch[i + 1][j - 2][1] = 0;
				if (j + 2 <= 9 && i - 1 >= 1 && ch[i][j + 1][0] == 0)//右上
					ch[i - 1][j + 2][1] = 0;
				if (j + 2 <= 9 && i + 1 <= 10 && ch[i][j + 1][0] == 0)//右下
					ch[i + 1][j + 2][1] = 0;
			}
		}
}

int check(int ch[11][10][2])
{
	for (int i = 1; i <= 3; i++)
		for (int j = 4; j <= 6; j++)
			if (ch[i][j][1] == 1)
				return 0;//没将死
	return 1;//将死
}

int main()
{
	//freopen("data.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		int board[11][10][2] = {};//从[1][1]开始,最后一个标识状态，[1]标识棋子，[2]标识可否落子
		int x, y;
		char kind;//kind:G将帅 R车 C炮 H马
		scanf("%d%d", &x, &y);
		canMove(x, y, board);//将可移动,不设置帅位置,相当于拿起来
		/*
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 2; k++)
					board[i][j][k] = 1;
					*/
		while (n--)
		{
			cin >> kind >> x >> y;
			//getchar();//读空格
			//scanf("%c%d%d", &kind, &x, &y);
			board[x][y][0] = kind;
		}
		solve(board);//计算不可移动归零
		
		if (check(board))
			printf("YES\n");
		else
			printf("NO\n");
	
	}

	return 0;
}
