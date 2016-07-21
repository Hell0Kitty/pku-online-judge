#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxm 15005
#define maxn 1005

struct Edge
{
    int u, v, w;
}edge[maxm], mst[maxm];

int n, m, ecount, father[maxn];

void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
}

bool operator < (const Edge &a, const Edge &b)
{
    return a.w < b.w;
}

int getanc(int a)
{
    if (father[a] == a)
        return a;
    return father[a] = getanc(father[a]);
}

void merge(int a, int b)
{
    father[getanc(a)] = getanc(b);
}

void work()
{
    for (int i = 1; i <= n; i++)
        father[i] = i;
    int ans;
    ecount = 0;
    for (int i = 0; i < m; i++)
        if (getanc(edge[i].u) != getanc(edge[i].v))
        {
            merge(edge[i].u, edge[i].v);
            ans = edge[i].w;
            mst[ecount++] = edge[i];
        }
    printf("%d\n%d\n", ans, ecount);
    for (int i = 0; i < ecount; i++)
        printf("%d %d\n", mst[i].u, mst[i].v);
}

int main()
{
    input();
    sort(edge, edge + m);
    work();
    return 0;
}



