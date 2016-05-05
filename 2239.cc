#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 305

struct Edge
{
    int v, next;
} edge[maxn * 7 * 12];

int n, m;
int head[maxn];
int xM[maxn], yM[maxn];
bool chk[maxn];
int count;

void addedge(int a, int b)
{
    edge[count].next = head[a];
    edge[count].v = b;
    head[a] = count;
    count++;
}

void input()
{
    int t;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        for (int j = 0; j < t; j++)
        {
            int p, q;
            scanf("%d%d", &p, &q);
            addedge(i, (p - 1) * 12 + q);
        }
    }
}

bool SearchPath(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (!chk[v])
        {
            chk[v] = true;
            if (yM[v] == -1 || SearchPath(yM[v]))
            {
                yM[v] = u;
                xM[u] = v;
                return true;
            }
        }
    }
    return false;
}

int MaxMatch()
{
    int u, ret = 0;

    memset(xM, -1, sizeof(xM));
    memset(yM, -1, sizeof(yM));
    for (u = 0; u < n; u++)
        if (xM[u] == -1)
        {
            memset(chk, false, sizeof(chk));
            if (SearchPath(u))
                ret++;
        }
    return ret;
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        count = 0;
        memset(head, -1, sizeof(head));
        m = 7 * 12 + 1;
        input();
        printf("%d\n", MaxMatch());
    }
    return 0;
}



