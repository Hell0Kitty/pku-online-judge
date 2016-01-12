#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 10

int n;
int f[maxn][maxn];
int shift[maxn];

void input()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &f[i][j]);
}

bool make()
{
    int i = 0;
    while (i < n - 1)
    {
        shift[i] = (shift[i] + 1) % n;
        if (shift[i] != 0)
            return true;
        i++;
    }
    return false;
}

void work()
{
    memset(shift, 0, sizeof(shift));
    int ans = 0x3f3f3f3f;
    while (make())
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
                sum += f[j][(i + shift[j]) % n];
            temp = max(temp, sum);
            if (temp > ans)
                break;
        }
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
}

int main()
{
    while (scanf("%d", &n), ~n)
    {
        input();
        work();
    }
    return 0;
}



