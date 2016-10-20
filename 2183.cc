#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1000000

int n;
int vis[maxn];

int main()
{
    scanf("%d", &n);
    memset(vis, -1, sizeof(vis));
    int i = 0;
    while (1)
    {
        if (vis[n] != -1)
            break;
        vis[n] = i;
        n = n / 10 % 10000;
        n = n * n;
        n %= 1000000;
        i++;
    }
    printf("%d %d %d\n", n, i - vis[n], i);
    return 0;
}



