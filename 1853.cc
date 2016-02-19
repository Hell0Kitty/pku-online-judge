#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105

double sum, rock[maxn];
bool vis[maxn];
int n;

void input()
{
    sum =0;
    for (int i =0; i < n; i++)
    {
        scanf("%lf", &rock[i]);
        sum += rock[i];
    }
}

bool dfs(double l, double r, int a)
{
    for (int i = a; i < n; i++)
    {
        if (rock[i] >= l && rock[i] <= r)
        {
            vis[i] =true;
            return true;
        }else if (rock[i] < l)
        {
            vis[i] =true;
            if (dfs(l - rock[i], r - rock[i], i +1))
                return true;
        }
        vis[i] =false;
    }
    return false;
} 

int main()
{
    while (scanf("%d", &n), n)
    {
        input();
        memset(vis, 0, sizeof(vis));
        dfs(sum /2.02, sum *1.02/2.02, 0);
        int i =0;
        while (!vis[i])
            i++;
        printf("%d", i +1);
        for (int j = i +1; j < n; j++)
            if (vis[j])
                printf(" %d", j +1);
        putchar('\n');
    }
    return 0;
}



