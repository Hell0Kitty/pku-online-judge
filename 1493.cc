#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 20

int f[maxn];
int n, ans;

void input()
{
    ans = 0;
    getchar();
    for (int i = 0; i < n; i++)
    {
        f[i] = 0;
        for (int j = 0; j < 25; j++)
        {
            char ch = getchar();
            if (ch == 'X')
                f[i]++;
        }
        ans = max(ans, f[i]);
        getchar();
    }
}

int main()
{
    while (scanf("%d", &n), n)
    {
        input();
        int d = 0;
        for (int i = 0; i < n; i++)
            d += ans - f[i];
        printf("%d\n", d);
    }
    return 0;
}


