//һ�����������������������������������мӷ�����ó�һ�����޼�
//���ϳ�������Ѿ����մ�С�����������
//ͨ���޸�n�������ת�õ��ƶ�����
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