/*
·Ö×ÓÁ¿
2016-8-4
edited by sunshine
*/
#include<stdio.h>
#define cMass 12.01
#define hMass 1.008
#define oMass 16.00
#define nMass 14.01
int main()
{
	int n;	
	scanf("%d", &n);
	while (n--)
	{
		int num = 0, i = 0;
		float temp = 0.0, total = 0.0;
		char a[100];
		scanf("%s", a);
		while (a[i] != NULL)
		{
			if(a[i]=='C')
			{
				num == 0 ? total = temp * 1 + total : total = temp*num + total;	
				temp = cMass;
				num = 0;
			}
			else if (a[i] == 'H')
			{
				num == 0 ? total = temp * 1 + total : total = temp*num + total;
				temp = hMass;
				num = 0;
			}
			else if (a[i] == 'O')
			{
				num == 0 ? total = temp * 1 + total : total = temp*num + total;
				temp = oMass;
				num = 0;
			}
			else if (a[i] == 'N')
			{
				num == 0 ? total = temp * 1 + total : total = temp*num + total;
				temp = nMass;
				num = 0;
			}
			else
			{
				num = num * 10 + (a[i]-'0');
			}
			i++;
		}
		num == 0 ? total = temp * 1 + total : total = temp*num + total;
		printf("%.3f\n", total);
	}
	return 0;
}