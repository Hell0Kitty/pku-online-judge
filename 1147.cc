#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define maxn 3004

int n;
int f[maxn];
int g[maxn];
int next[maxn];
int cnt, cnt1;

int main()
{
    scanf("%d", &n);
    cnt = cnt1 =0;
    for (int i =0; i < n; i++)
    {
        scanf("%d", &f[i]);
        if (f[i] ==0)
            cnt++;
    }
    for (int i =0; i < n; i++)
    {
        if (f[i])
            next[i] = cnt + cnt1++;
        else
            next[i] = i - cnt1;
    }
    memset(f, 0, sizeof(f));
    for (int i = cnt; i < n; i++)
        f[i] =1;
    printf("%d", f[0]);
    for (int i =0; i < n -1; i++)
    {
        for (int j =0; j < n; j++)
            g[next[j]] = f[j];
        memcpy(f, g, n *sizeof(int));
        printf(" %d", f[0]);
    }
    putchar('\n');
    return 0;
}


