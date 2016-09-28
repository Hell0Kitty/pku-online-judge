#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10008

struct XPlayer
{
    int id, p;
} xplayer[maxn * 500];

int m, n;
int vis[maxn];
int pcount;

void input()
{
    pcount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int a;
            scanf("%d", &a);
            if (vis[a] != -1)
                xplayer[vis[a]].p++;
            else
            {
                xplayer[pcount].id = a;
                xplayer[pcount].p = 1;
                vis[a] = pcount;
                pcount++;
            }
        }
}

bool operator <(const XPlayer &a, const XPlayer &b)
{
    if (a.p == b.p)
        return a.id < b.id;
    return a.p > b.p;
}

int main()
{
    while (scanf("%d%d", &n, &m), m | n)
    {
        memset(vis, -1, sizeof(vis));
        input();
        sort(xplayer, xplayer + pcount);
        int i = 1;
        int temp = xplayer[1].p;
        while (xplayer[i].p == temp && i < pcount)
        {
            printf("%d ", xplayer[i].id);
            i++;
        }
        printf("\n");
    }
    return 0;
}



