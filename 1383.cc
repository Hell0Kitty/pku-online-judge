#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 1005

struct Point
{
    int x, y;
}q[maxn * maxn];

int n, m;
char map[maxn][maxn];
int dist[maxn][maxn];
int dir[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};

void input()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);
}

bool in(Point b)
{
    return b.x < n && b.y < m && b.x >= 0 && b.y >= 0;
}

void bfs(int sx, int sy)
{
    int front = 0;
    int rear = 0;
    Point a;
    a.x = sx;
    a.y = sy;
    q[rear++] = a;
    dist[a.x][a.y] = 0;
    while (front != rear)
    {
        a = q[front++];
        if (front == maxn * maxn)
            front = 0;
        for (int i= 0; i < 4; i++)
        {
            Point b = a;
            b.x += dir[i][0];
            b.y += dir[i][1];
            if (in(b) && map[b.x][b.y] == '.' && dist[b.x][b.y] == -1)
            {
                dist[b.x][b.y] = dist[a.x][a.y] + 1;
                q[rear++] = b;
                if (rear == maxn * maxn)
                    rear = 0;
            }
        }
    }
}

void work()
{
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++)
    {
        bool did = false;
        for (int j = 0; j < m; j++)
            if (map[i][j] == '.')
            {
                bfs(i, j);
                did = true;
                break;
            }
        if (did)
            break;
    }
    int temp = -1;
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dist[i][j] > temp)
            {
                temp = dist[i][j];
                sx = i;
                sy = j;
            }
    memset(dist, -1, sizeof(dist));
    if (temp == -1)
    {
        printf("Maximum rope length is %d.\n", 0);
        return;
    }
    bfs(sx, sy);
    temp = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dist[i][j] > temp)
                temp = dist[i][j];
    printf("Maximum rope length is %d.\n", temp);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        work();
    }
    return 0;
}


