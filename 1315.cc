#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 10

int n;
char map[maxn][maxn];
bool rook[maxn][maxn];
int ans;
int dir[4][2] =
{
{ 0, 1 },
{ 1, 0 },
{ 0, -1 },
{ -1, 0 } };

void input()
{
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);
}

bool in(int x, int y)
{
    return x < n && y < n && x >= 0 && y >= 0;
}

bool ok(int sx, int sy)
{
    if (map[sx][sy] == 'X')
        return false;
    for (int i = 0; i < 4; i++)
    {
        int x = sx;
        int y = sy;
        while (in(x, y) && map[x][y] == '.')
        {
            if (rook[x][y])
                return false;
            x += dir[i][0];
            y += dir[i][1];
        }
    }
    return true;
}

void dfs(int a, int cnt)
{
    ans = max(ans, cnt);
    for (int i = a; i < n * n; i++)
    {
        int x = i / n;
        int y = i % n;
        if (ok(x, y))
        {
            rook[x][y] = true;
            dfs(i + 1, cnt + 1);
            rook[x][y] = false;
        }
    }
}

int main()
{
    while (scanf("%d", &n), n)
    {
        input();
        memset(rook, 0, sizeof(rook));
        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}


