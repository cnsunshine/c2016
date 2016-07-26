#include<iostream>
using namespace std;
int main()
{
	
	for (int i = 123; i <= 987; i++)
	{
		int a[10] = {};
		int count = 0;
		if (3 * i > 987) continue;
		for (int j = 1; j <= 3; j++)
		{
			int I = i*j;
			a[I / 100] += 1;
			a[I / 10 % 10] += 1;
			a[I % 10] += 1;
		}
		for (int j = 1; j <= 9; j++)
		{
			if (a[j] != 1)
				break;
			else
				count += 1;
		}
		if (count == 9)
			cout << i <<" "<< i * 2 << " " << i * 3 << endl;
	} 
	return 0;
}