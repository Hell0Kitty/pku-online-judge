#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105
#define inf 0x3f3f3f3f

int n, m, pre[maxn], edge[maxn][3];
int dist[maxn];

int relax(int u, int v, int c)
{
    if (dist[v] > dist[u] + c)
    {
        dist[v] = dist[u] + c;
        pre[v] = u;
        return 1;
    }
    return 0;
}

int bellman(int src)
{
    int i, j;
    for (i =0; i < n; ++i)
    {
        dist[i] = inf;
        pre[i] =-1;
    }
    dist[src] =0;
    bool flag;
    for (i =1; i < n; ++i)
    {
        flag =false;
        for (j =0; j < m; ++j)
        {
            if (1== relax(edge[j][0], edge[j][1], edge[j][2]))
                flag =true;
        }
        if (!flag)
            break;
    }
    for (j =0; j < m; ++j)
    {
        if (1== relax(edge[j][0], edge[j][1], edge[j][2]))
            return 0;
    }
    return 1;
}

void input()
{
    char st[5];
    for (int i =0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%s%d", &a, &b, st, &c);
        if (st[0] =='g')
        {
            edge[i][0] = a + b;
            edge[i][1] = a -1;
            edge[i][2] =-c -1;
        }
        if (st[0] =='l')
        {
            edge[i][0] = a -1;
            edge[i][1] = a + b;
            edge[i][2] = c -1;
        }
    }
}

int main()
{
while (scanf("%d", &n), n)
    {
        n++;
        scanf("%d", &m);
        input();
        if (bellman(0))
            printf("lamentable kingdom\n");
        else
            printf("successful conspiracy\n");
    }
    return 0;
}


