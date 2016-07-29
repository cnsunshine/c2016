/*
edited by sunshine
2016-7-28
*/
#include<stdio.h>
#include<stdlib.h>
int a[100005] = {};
int main()
{
	int n;
	for (int i = 1; ; i++)
	{
		int x = i, sum = 0;
		while (x > 0)
		{
			sum = sum + x % 10;
			x /= 10;
		}
		if (sum + i <= 100000)
		{
			if (a[sum + i] > i || a[sum + i] == 0)
				a[sum + i] = i;
		}
			//((i < a[sum + i]) || (a[sum + 1] == 0)) && (a[sum + i] = i);
		else
			break;
		//else上面的括号丢了得调试一个小时，不骗你
	}
	while (scanf("%d", &n) == 1)
		printf("%d\n", a[n]);
	return 0;
}