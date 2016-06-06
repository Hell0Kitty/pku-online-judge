#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

#define maxn 1005

int n, m;
int pos[maxn];

void work()
{
    int a = n;
    int b = m;
    int cnt = 1;
    int i = 1;
    pos[a] = 0;
    putchar('.');
    while (true)
    {
        int temp = a * 10 / b;
        a = a * 10 % b;
        if (cnt % 50 == 0)
            putchar('\n');
        putchar(temp + '0');
        cnt++;
        if (pos[a] == -1)
            pos[a] = i;
        else
        {
            printf("\nThe last %d digits repeat forever.\n", i - pos[a]);
            return;
        }
        if (a == 0)
        {
            printf("\nThis expansion terminates.\n");
            return;
        }
        i++;
    }
}

int main()
{
    while (scanf("%d%d", &n, &m), n | m)
    {
        memset(pos, -1, sizeof(pos));
        work();
    }
    return 0;
}


