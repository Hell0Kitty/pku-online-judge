#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxr 55
#define maxc 55
#define maxx maxr * maxc / 2
#define maxy maxx

struct Edge
{
    int x, y;
}edge[maxr][maxc];

int row, column;
char map[maxr][maxc];
int xcount, ycount;
bool visit[maxy];
int match[maxy];
bool g[maxx][maxy];

void input()
{
    scanf("%d%d", &row, &column);
    for (int i = 0; i < row; i++)
        scanf("%s", map[i]);
}

void make()
{
    xcount = 0;
    ycount = 0;
    for (int i = 0; i < row; i++)
    {
        int j = 0;
        while (j < column)
        {
            while (j < column && map[i][j] == '.')
                j++;
            if (j >= column)
                break;
            while (j < column && map[i][j] == '*')
            {
                edge[i][j].x = xcount;
                j++;
            }
            xcount++;
        }
    }

    for (int i = 0; i < column; i++)
    {
        int j = 0;
        while (j < row)
        {
            while (j < row && map[j][i] == '.')
                j++;
            if (j >= row)
                break;
            while (j < row && map[j][i] == '*')
            {
                edge[j][i].y = ycount;
                j++;
            }
            ycount++;
        }
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (map[i][j] == '*')
            {
                //printf("%d %d\n", edge[i][j].x, edge[i][j].y);
                g[edge[i][j].x][edge[i][j].y] = true;
            }
}

bool dfs(int k)
{
    int t;
    for (int i = 0; i < ycount; i++)
    {
        if (g[k][i] && !visit[i])
        {
            visit[i] = true;
            t = match[i];
            match[i] = k;
            if (t == -1 || dfs(t))
                return true;
            match[i] = t;
        }
    }
    return false;
}

int max_match()
{
    int ans = 0;
    for (int i = 0; i < xcount; i++)
    {
        memset(visit, false, sizeof(visit));
        if (dfs(i))
            ans ++;
    }
    return ans;
}

int main()
{
    memset(g, 0, sizeof(g));
    input();
    make();
    memset(match, -1, sizeof(match));
    printf("%d\n", max_match());
    return 0;
}



