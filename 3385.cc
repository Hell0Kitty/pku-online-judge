#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 100005

int n, d;
int f[maxn];

int cal(int a)
{
    int ret = 0;
    while (a > d)
    {
        ret += a / d;
        a = a / d + a % d;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        f[a]++;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans += cal(f[i]);
    printf("%d\n", ans);
    return 0;
}


