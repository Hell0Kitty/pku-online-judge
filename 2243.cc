#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define maxn 10

struct Point
{
    int x, y;
}s, t;

int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

bool in_bound(Point a)
{
    return a.x >= 0 && a.y >= 0 && a.x < 8 && a.y < 8;
}

int bfs()
{
    if (s.x == t.x && s.y == t.y)
        return 0;
    queue <Point> q;
    bool vis[maxn][maxn];
    int dist[maxn][maxn];
    memset(vis, 0, sizeof(vis));
    q.push(s);
    vis[s.x][s.y] = true;
    dist[s.x][s.y] = 0;
    while (!q.empty())
    {
        Point a = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            Point b;
            b.x = a.x + dir[i][0];
            b.y = a.y + dir[i][1];
            if (in_bound(b) && !vis[b.x][b.y])
            {
                vis[b.x][b.y] = true;
                dist[b.x][b.y] = dist[a.x][a.y] + 1;
                q.push(b);
                if (b.x == t.x && b.y == t.y)
                    return dist[b.x][b.y];
            }
        }
    }
    return -1;
}

int main()
{
    char st1[10], st2[10];
    while (~scanf("%s", st1))
    {
        s.x = st1[0] - 'a';
        s.y = st1[1] - '1';
        scanf("%s", st2);
        t.x = st2[0] - 'a';
        t.y = st2[1] - '1';
        printf("To get from %s to %s takes %d knight moves.\n", st1, st2, bfs());
    }
    return 0;
}



