#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	int a, status = 0;
	while ((a = getchar()) != EOF)
	{
		if (a == '"')
		{
			if (status == 0)
			{
				cout << "``";	status = !status;
			}
			else if (status == 1)
			{
				cout << "''";	status = !status;
			}
			
		}
		else
			printf("%c", a);

	}
	return 0;
}