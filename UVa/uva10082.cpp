/*
��һ���ύ��û�п��ǵ��س�
û�����ϵķ����򵥣�����Ч��Ҳ����һ����
*/
#include<stdio.h>
int main()
{
	char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./", c;
	while ((c = getchar()) != EOF)
	{
		int found = 0;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == c)
			{
				putchar(s[i - 1]);
				found = 1;
				break;
			}
		}
		if (found == 0)
			putchar(c);

	}

	return 0;
}