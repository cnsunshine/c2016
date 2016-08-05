/*
直接计算前n个数
2016-8-4
edited by sunshine
*/
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a[10] = {};
		int i = 1, temp, N;
		scanf("%d", &N);
		while (i <= N)
		{
			temp = i;
			while (temp)
			{
				a[temp % 10] += 1;
				temp /= 10;
			}
			i++;
		}
		for (int i = 0; i <= 8; i++)
		{
			printf("%d ", a[i]);
		}
		printf("%d", a[9]);
		printf("\n");
	}
	return 0;
}