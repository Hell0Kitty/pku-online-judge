#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 1005

int uN, vN;
bool g[maxn][maxn];
int xM[maxn], yM[maxn];
bool chk[maxn];

bool SearchPath(int u)
{
    int v;
    for (v = 0; v < vN; v++)
        if (g[u][v] && !chk[v])
        {
            chk[v] = true;
            if (yM[v] == -1 || SearchPath(yM[v]))
            {
                yM[v] = u;
                xM[u] = v;
                return true;
            }
        }
    return false;
}

int MaxMatch()
{
    int u, ret = 0;
    memset(xM, -1, sizeof(xM));
    memset(yM, -1, sizeof(yM));
    for (u = 0; u < uN; u++)
    {
        if (xM[u] == -1)
            memset(chk, false, sizeof(chk));
        if (SearchPath(u))
            ret++;
    }
    return ret;
}

void input()
{
    scanf("%d%d", &uN, &vN);
    memset(g, 0, sizeof(g));
    for (int i = 0; i < vN; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a][i] = g[b][i] = true;
    }
}

void work()
{
    if (uN > vN)
    {
        printf("NO\n");
        return;
    }
    int ans = MaxMatch();
    if (ans != uN)
    {
        printf("NO\n");
        return;
    }
    if (yM[0] != -1)
        printf("%d", yM[0] + 1);
    else
    {
        int j = 0;
        while (!g[j][0])
            j++;
        printf("%d", j + 1);
    }
    for (int i = 1; i < vN; i++)
    {
        if (yM[i] != -1)
        {
            printf(" %d", yM[i] + 1);
            continue;
        }
        int j = 0;
        while (!g[j][i])
            j++;
        printf(" %d", j + 1);
    }
}

int main()
{
        int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        work();
        putchar('\n');
    }
    return 0;
}


