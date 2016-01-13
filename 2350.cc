#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 1005

int n;
int f[maxn];
double average;

void input()
{
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
        sum += f[i];
    }
    average = sum * 1.0 / n;
}

double work()
{
    int num = 0;
    for (int i = 0; i < n; i++)
        if (f[i] > average)
            num++;
    return num * 100.0 / n;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        printf("%.3f%%\n", work());
    }
    return 0;
}



