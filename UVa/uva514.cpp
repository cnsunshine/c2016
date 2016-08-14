/*
简单的栈的问题
火车调度进出栈
*/
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;
void startTest(int b[1005],int n)
{
    int A = 1, B = 0;//A用来标示当前入队序列从1开始，B标示当前出队序列下标从0开始
    stack<int>  s;
    int cant = 0;
    while(B < n)
    {
        if(A == b[B])
        {
            A++;
            B++;
        }
        else if(!s.empty() && s.top() == b[B])
        {
            s.pop();
            B++;
        }
        else if(A <= n)
        {
            s.push(A++);
        }
        else
        {
            cant = 1;
            break;
        }
    }
    if(cant == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main()
{
    int n;
    while(cin >> n)
    {
        while(n != 0)
        {
            int a[1005];
            while(cin >> a[0] && a[0] )
            {
                for(int i = 1; i < n; i++)
                {
                    scanf("%d", &a[i]);
                }
                startTest(a, n);
            }
            cout << endl;
            break;
        }

    }

}
