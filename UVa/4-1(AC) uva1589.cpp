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
#include<iostream>
#include<string.h>
using namespace std;
//ȫ����ȥ����0���±�
void canMove(int x, int y, int ch[11][10][2])
{//�������ƶ�λ��
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
						ch[i1][j][1] = 0;//�����ƶ�
					else
					{
						ch[i1][j][1] = 0;//��һ��˧���ˣ�ʵ�ʹ�����Χ
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
				if (i - 2 >= 1 && j - 1 >= 1 && ch[i - 1][j][0] == 0)//����
					ch[i - 2][j - 1][1] = 0;
				if (i - 2 >= 1 && j + 1 <= 9 && ch[i - 1][j][0] == 0)//����
					ch[i - 2][j + 1][1] = 0;
				if (i + 2 <= 10 && j - 1 >= 1 && ch[i + 1][j][0] == 0)//����
					ch[i + 2][j - 1][1] = 0;
				if (i + 2 <= 10 && j + 1 <= 9 && ch[i + 1][j][0] == 0)//����
					ch[i + 2][j + 1][1] = 0;
				if (j - 2 >= 1 && i - 1 >= 1 && ch[i][j - 1][0] == 0)//����
					ch[i - 1][j - 2][1] = 0;
				if (j - 2 >= 1 && i + 1 <= 10 && ch[i][j - 1][0] == 0)//����
					ch[i + 1][j - 2][1] = 0;
				if (j + 2 <= 9 && i - 1 >= 1 && ch[i][j + 1][0] == 0)//����
					ch[i - 1][j + 2][1] = 0;
				if (j + 2 <= 9 && i + 1 <= 10 && ch[i][j + 1][0] == 0)//����
					ch[i + 1][j + 2][1] = 0;
			}
		}
}

int check(int ch[11][10][2])
{
	for (int i = 1; i <= 3; i++)
		for (int j = 4; j <= 6; j++)
			if (ch[i][j][1] == 1)
				return 0;//û����
	return 1;//����
}

int main()
{
	//freopen("data.out", "w", stdout);
	int n;
	while (scanf("%d", &n) == 1 && n != 0)
	{
		int board[11][10][2] = {};//��[1][1]��ʼ,���һ����ʶ״̬��[1]��ʶ���ӣ�[2]��ʶ�ɷ�����
		int x, y;
		char kind;//kind:G��˧ R�� C�� H��
		scanf("%d%d", &x, &y);
		canMove(x, y, board);//�����ƶ�,������˧λ��,�൱��������
		/*
		for (int i = 0; i < 11; i++)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 2; k++)
					board[i][j][k] = 1;
					*/
		while (n--)
		{
			cin >> kind >> x >> y;
			//getchar();//���ո�
			//scanf("%c%d%d", &kind, &x, &y);
			board[x][y][0] = kind;
		}
		solve(board);//���㲻���ƶ�����
		
		if (check(board))
			printf("YES\n");
		else
			printf("NO\n");
	
	}

	return 0;
}
