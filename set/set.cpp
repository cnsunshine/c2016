//一个集合里面有两个数，利用这两个数进行加法运算得出一个无限集
//集合出来后就已经按照从小到大进行排列
//通过修改n和添加跳转得到制定长度
#include<stdio.h>
int num[1000000] = { -1 };
int main()
{
	int temp, count = 1;

	int min, max, a, b;
	scanf("%d %d", &min, &max);
	a = max / min;
	b = max % min;
	printf("%d %d\n", a, b);
	for (int n = 1; n <= 50; n++)
	{
		int i = n / (a + 1);
		for (int count1 = 0; count1 <= i; count1++)
		{
			temp = b*(i - count1) + min*(n - i + count1);
			if (temp > num[count - 1])
			{
				num[count] = temp;
				printf("%d\n", num[count]);
				count = count + 1;
			}
		}
	}
	getchar();
	getchar();
	return 0;
}