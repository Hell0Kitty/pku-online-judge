#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxp 140000

struct Stone
{
    int x, y;
}stone[maxp];

int n, m, p;
int ans;
bool vis[maxp];

bool operator < (const Stone &a, const Stone &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int cal(int a)
{
    if (a > 1)
        return 1;
    return 0;
}

void input()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < p; i++)
        scanf("%d%d", &stone[i].x, &stone[i].y);
}

void work()
{
    int pos = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < p - 1; i++)
    {
        ans += cal(stone[i].y - pos - 1);
        pos = stone[i].y;
        if (stone[i].x != stone[i + 1].x)
        {
            ans += cal(m - stone[i].y);
            pos = 0;
        }
        vis[stone[i].x] = true;
    }
    ans += cal(stone[p - 1].y - pos - 1);
    ans += cal(m - stone[p - 1].y);
    vis[stone[p - 1].x] = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ans += cal(m);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        if (n == 1 && m == 1)
        {
            printf("0\n");
            continue;
        }
        if (p == 0)
        {
            printf("%d\n", cal(n) * m + cal(m) * n);
            continue;
        }
        sort(stone, stone + p);
        ans = 0;
        work();
        swap(n, m);
        for (int i = 0; i < p; i++)
            swap(stone[i].x, stone[i].y);
        sort(stone, stone + p);
        work();
        printf("%d\n", ans);
    }
    return 0;
}



