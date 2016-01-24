#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxl 35
#define maxn 205
#define maxm 300

int m, n, l;
int member[maxl];
int dist[maxn][maxn];
int wall[maxm][maxm];
int map[maxm][maxn];

void floyd()
{
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist[j][i] != -1)
                for (int k = 0; k < n; k++)
                    if (dist[i][k] != -1 && (dist[j][k] == -1 || dist[j][k] > dist[j][i] + dist[i][k]))
                        dist[j][k] = dist[j][i] + dist[i][k];
}

int main()
{
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i < l; i++)
        scanf("%d", &member[i]);
    memset(dist, -1, sizeof(dist));
    memset(wall, -1, sizeof(wall));
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        int first, last, now;
        scanf("%d%d", &first, &last);
        if (wall[first][last] != -1)
            dist[i][wall[first][last]] = dist[wall[first][last]][i] = 1;
        else
            wall[first][last] = wall[last][first] = i;
        map[first][i] = true;
        map[last][i] = true;
        for (int j = 2; j < a; j++)
        {
            scanf("%d", &now);
            if (wall[now][last] != -1)
                dist[i][wall[now][last]] = dist[wall[now][last]][i] = 1;
            else
                wall[now][last] = wall[last][now] = i;
            last = now;
            map[now][i] = true;
        }
        if (wall[first][last] != -1)
            dist[i][wall[first][last]] = dist[wall[first][last]][i] = 1;
        else
            wall[first][last] = wall[last][first] = i;
    }
    floyd();
    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < l; j++)
        {
            int x = 0x3f3f3f3f;
            for (int k = 0; k < n; k++)
                if (map[member[j]][k])
                    x = min(x, dist[k][i]);
            sum += x;
        }
        ans = min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}


