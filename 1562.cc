#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define maxn 105

struct Point
{
    int x, y;
    Point()
    {}
    Point(int xx, int yy):x(xx), y(yy)
    {}
};

int n, m;
bool grid[maxn][maxn];
bool vis[maxn][maxn];
int dir[8][2] = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
char st[maxn];

void input()
{
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", st);
        for (int j = 1; j <= m; j++)
        {
            grid[i][j] = (st[j - 1] == '@');
        }
    }
}

bool ok(Point a)
{
    if (a.x > n || a.x < 1 || a.y > m || a.y < 1)
        return false;
    if (vis[a.x][a.y])
        return false;
    return grid[a.x][a.y];
}

void bfs(int sx, int sy)
{
    queue<Point> q;
    q.push(Point(sx, sy));
    vis[sx][sy] = true;
    while (!q.empty())
    {
        Point u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            Point v;
            v.x = u.x + dir[i][0];
            v.y = u.y + dir[i][1];
            if (ok(v))
            {
                vis[v.x][v.y] = true;
                q.push(v);
            }
        }
    }    
}

int main()
{
    while (scanf("%d%d", &n, &m), n)
    {
        input();
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (grid[i][j] && !vis[i][j])
                {
                    bfs(i, j);
                    ans++;
                }
        printf("%d\n", ans);
    }
    return 0;
}


