/*
���ڴ�
��1��̽
2016-8-5
edited by sunshine
*/
#include<stdio.h>
#include<string.h>

int ifTrue(char s[],int n)
{
	int N = n, length = strlen(s);
	if (length%n != 0)//����Ϊ����û��Ҫ�ģ�������ѭ���������ո����ĵ��Խ������˼������Ҫ��
		return 1;
	while (N--)//ע�������Ѿ�-1
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
	while (n--)//����
	{
		char a[85];
		int count = 1;
		scanf("%s", a);
		while (ifTrue(a, count))//��̽
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