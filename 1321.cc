#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 10

bool row[maxn], col[maxn];
bool map[maxn][maxn];
int ans, n, m;

void input()
{
    char ch;
    memset(map, 0, sizeof(map));
    getchar();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ch = getchar();
            if (ch == '#')
                map[i][j] = true;
            else
                map[i][j] = false;
        }
        getchar();
    }
}

void dfs(int pos, int a)
{
    if (a == m)
    {
        ans++;
        return;
    }
    while (pos < n * n)
    {
        int x = pos / n;
        int y = pos % n;
        if (map[x][y] && !row[x] && !col[y])
        {
            row[x] = col[y] = true;
            dfs(pos + 1, a + 1);
            row[x] = col[y] = false;
        }
        pos++;
    }
}

int main()
{
    while (scanf("%d%d", &n, &m), !(n == -1 && m == -1))
    {
        input();
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        ans = 0;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}


