#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 2005
#define inf 0x3f3f3f3f

int n;
char code[maxn][10];
int cost[maxn][maxn];
int vis[maxn];
int lowc[maxn];

int cal(int a, int b)
{
    int ret = 0;
    for (int i = 0; i < 7; i++)
        if (code[a][i] != code[b][i])
            ret++;
    return ret;
}

int prim()
{
    int i, j, p;
    int minc, res = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for (i = 1; i < n; i++)
    {
        minc = inf;
        p = -1;
        for (j = 0; j < n; j++)
            if (0 == vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        if (inf == minc) return -1;
        res += minc; vis[p] = 1;
        for (j = 0; j < n; j++)
            if (0 == vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return res;
}

int main()
{
        while (scanf("%d", &n), n)
    {
        memset(cost, 0, sizeof(cost));
        getchar();
        for (int i = 0; i < n; i++)
            gets(code[i]);
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                cost[i][j] = cal(i, j);
                cost[j][i] = cost[i][j];
            }
        printf("The highest possible quality is 1/%d.\n", prim());
    }
    return 0;
}

