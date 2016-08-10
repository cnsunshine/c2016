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
#include<string.h>

int check(int ch[11][10], int x, int y)//1遇到不能落子，0可以落子
{
	for (int begin = 0, i = x - 1; i >= 1; i--)//向上判断车和炮
	{
		if (ch[i][y] == 'R')
			if (begin == 0)
				return 1;
			else
				break;
		else if (ch[i][y] == 'C')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				return 1;
		else if (ch[i][y] == 'H')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				break;
	}
	for (int begin = 0, i = x + 1; i <= 10; i++)//向下判断车和炮和将
	{
		if (ch[i][y] == 'R')
			if (begin == 0)
				return 1;
			else
				break;
		else if (ch[i][y] == 'C')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				return 1;
		else if (ch[i][y] == 'H')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				break;
		else if (ch[i][y] == 'G')
			if (begin == 0)
				return 1;
			else
				break;
	}
	for (int begin = 0, j = y - 1; j >= 1; j--)//向左判断车和炮
	{
		if (ch[x][j] == 'R')
			if (begin == 0)
				return 1;
			else
				break;
		else if (ch[x][j] == 'C')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				return 1;
		else if (ch[x][j] == 'H')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				break;
	}
	for (int begin = 0, j = y + 1; j <= 9; j++)//向右判断车和炮
	{
		if (ch[x][j] == 'R')
			if (begin == 0)
				return 1;
			else
				break;
		else if (ch[x][j] == 'C')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				return 1;
		else if (ch[x][j] == 'H')
			if (begin == 0)
			{
				begin = 1;
				continue;
			}
			else
				break;
	}
	if (x - 2 >= 1 && y - 1 >= 1 && ch[x - 2][y - 1] == 'H')//向上左探测马
		if (ch[x - 1][y - 1] == 0)
			return 1;
	if (x - 2 >= 1 && y + 1 <= 9 && ch[x - 2][y + 1] == 'H')//向上右探测马
		if (ch[x - 1][y + 1] == 0)
			return 1;
	if (x + 2 <= 10 && y - 1 >= 1 && ch[x + 2][y - 1] == 'H')//向下左探测马
		if (ch[x + 1][y - 1] == 0)
			return 1;
	if (x + 2 <= 10 && y + 1 <= 9 && ch[x + 2][y + 1] == 'H')//向下右探测马
		if (ch[x + 1][y + 1] == 0)
			return 1;
	if (x - 1 >= 1 && y - 2 >= 1 && ch[x - 1][y - 2] == 'H')//向左上探测马
		if (ch[x - 1][y - 1] == 0)
			return 1;
	if (x + 1 <= 10 && y - 2 >= 1 && ch[x + 1][y - 2] == 'H')//向左下探测马
		if (ch[x + 1][y - 1] == 0)
			return 1;
	if (x - 1 >= 1 && y + 2 <= 9 && ch[x - 1][y + 2] == 'H')//向右上探测马
		if (ch[x - 1][y + 1] == 0)
			return 1;
	if (x + 1 <= 10 && y + 2 <= 9 && ch[x + 1][y + 2] == 'H')//向右下探测马
		if (ch[x + 1][y + 1] == 0)
			return 1;
	return 0;//可以落子
}
int solve(int ch[11][10],int x,int y)
{
	if (x > 1)//试探向上移
		if (check(ch, x - 1, y) == 0)//如果能落子没将死
			return 0;
	if (x < 3)//试探向下移
		if (check(ch, x + 1, y) == 0)
			return 0;
	if (y > 4)//试探向左移
		if (check(ch, x, y - 1) == 0)
			return 0;
	if (y < 6)//试探向左移
		if (check(ch, x, y + 1) == 0)
			return 0;
	return 1;
	
}
int main()
{
	//freopen("data.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		int board[11][10] = {};//从[1][1]开始
		int x, y, x0, y0;
		char kind;//kind:G将帅 R车 C炮 H马
		scanf("%d%d", &x0, &y0);
		while (n--)
		{
			getchar();//读空格
			scanf("%c%d%d", &kind, &x, &y);
			board[x][y] = kind;
		}
		

		if (solve(board, x0, y0))
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}
