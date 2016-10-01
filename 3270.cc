#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 10005
#define maxg 100005

struct Elem
{
    int v, index;
}elem[maxn];

int n;
int f[maxn];
bool vis[maxn];
int pos[maxg];

bool operator < (const Elem &a, const Elem &b)
{
    return a.v < b.v;
}

void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &elem[i].v);
        elem[i].index = i;
        f[i] = elem[i].v;
    }
}

int work()
{
    for (int i = 0; i < n; i++)
        pos[elem[i].v] = i;
    int mini = 0;
    for (int i = 0; i < n; i++)
        if (f[i] < f[mini])
            mini = i;
    int ret = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            int sum = 0, temp = i, x = f[i], num = 0;
            while (!vis[temp])
            {
                vis[temp] = true;
                sum += f[temp];
                x = min(x, f[temp]);
                temp = pos[f[temp]];
                num++;
            }
            ret += min((num - 1) * x + sum - x, (num - 1) * f[mini] + sum - x + (x + f[mini]) * 2);
        }
    return ret;
}

int main()
{
    memset(vis, 0, sizeof(vis));
    input();
    sort(elem, elem + n);
    printf("%d\n", work());
    return 0;
}



