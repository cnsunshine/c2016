/*
�������⣬�ж��Ƿ���
���
2016-8-7
edited by sunshine
*/
//1���Ŀ��ƶ�λ�á���ȡ���岻���ƶ�������
/*
���������ܳ����ڶ���
�������û��������ܳ����ڳ��Լ�����λ����ֱ��λ����
�����ܳ������Լ��Ĺ�����Χ
�ڣ����ܳ������Լ��Ĺ�����Χ
*/
#include<stdio.h>
#include<string.h>

int check(int ch[11][10], int x, int y)//1�����������ӣ�0��������
{
	for (int begin = 0, i = x - 1; i >= 1; i--)//�����жϳ�����
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
	for (int begin = 0, i = x + 1; i <= 10; i++)//�����жϳ����ںͽ�
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
	for (int begin = 0, j = y - 1; j >= 1; j--)//�����жϳ�����
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
	for (int begin = 0, j = y + 1; j <= 9; j++)//�����жϳ�����
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
	if (x - 2 >= 1 && y - 1 >= 1 && ch[x - 2][y - 1] == 'H')//������̽����
		if (ch[x - 1][y - 1] == 0)
			return 1;
	if (x - 2 >= 1 && y + 1 <= 9 && ch[x - 2][y + 1] == 'H')//������̽����
		if (ch[x - 1][y + 1] == 0)
			return 1;
	if (x + 2 <= 10 && y - 1 >= 1 && ch[x + 2][y - 1] == 'H')//������̽����
		if (ch[x + 1][y - 1] == 0)
			return 1;
	if (x + 2 <= 10 && y + 1 <= 9 && ch[x + 2][y + 1] == 'H')//������̽����
		if (ch[x + 1][y + 1] == 0)
			return 1;
	if (x - 1 >= 1 && y - 2 >= 1 && ch[x - 1][y - 2] == 'H')//������̽����
		if (ch[x - 1][y - 1] == 0)
			return 1;
	if (x + 1 <= 10 && y - 2 >= 1 && ch[x + 1][y - 2] == 'H')//������̽����
		if (ch[x + 1][y - 1] == 0)
			return 1;
	if (x - 1 >= 1 && y + 2 <= 9 && ch[x - 1][y + 2] == 'H')//������̽����
		if (ch[x - 1][y + 1] == 0)
			return 1;
	if (x + 1 <= 10 && y + 2 <= 9 && ch[x + 1][y + 2] == 'H')//������̽����
		if (ch[x + 1][y + 1] == 0)
			return 1;
	return 0;//��������
}
int solve(int ch[11][10],int x,int y)
{
	if (x > 1)//��̽������
		if (check(ch, x - 1, y) == 0)//���������û����
			return 0;
	if (x < 3)//��̽������
		if (check(ch, x + 1, y) == 0)
			return 0;
	if (y > 4)//��̽������
		if (check(ch, x, y - 1) == 0)
			return 0;
	if (y < 6)//��̽������
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
		int board[11][10] = {};//��[1][1]��ʼ
		int x, y, x0, y0;
		char kind;//kind:G��˧ R�� C�� H��
		scanf("%d%d", &x0, &y0);
		while (n--)
		{
			getchar();//���ո�
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
