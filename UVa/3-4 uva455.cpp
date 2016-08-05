/*
周期串
从1试探
2016-8-5
edited by sunshine
*/
#include<stdio.h>
#include<string.h>

int ifTrue(char s[],int n)
{
	int N = n, length = strlen(s);
	if (length%n != 0)//我认为这是没必要的，我理解的循环，但按照给出的调试结果的意思，是需要的
		return 1;
	while (N--)//注意这里已经-1
	{
		int begin = N;
		for (begin += n; begin < length; begin += n)
		{
			if (s[N] != s[begin])
				return 1;
		}
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)//个数
	{
		char a[85];
		int count = 1;
		scanf("%s", a);
		while (ifTrue(a, count))//试探
		{
			count++;
		}
		if (n != 0)
			printf("%d\n\n", count);
		else
			printf("%d\n", count);
	}
	return 0;
}