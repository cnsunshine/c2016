//书上和网上习题不一致，代码是按照书上来的
#include<stdio.h>

void calculate()
{
	int n = 0, count = 0;
	char s[85];
	scanf("%s", s);
	while (s[n] != NULL)
	{
		count++;
		n++;
	}
	printf("%d", count);
	
}

int main()
{
	calculate();
	char c;
	int total = 0, count = 0;
	while (scanf("%c", &c) != EOF)
	{
		if (c == 'X')
		{
			count++;
			total += count;
		}
		else
		{
			count = 0;
		}
	}
	printf("%d", total);
	return 0;
}
