#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 10005

int a, b, n;
double p[maxn], sum[maxn];

int dblcmp(double a, double b)
{
    if (a < b)
        return -1;
    return 1;
}

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &p[i]);
        sum[i] = sum[i - 1] + p[i];
    }
    if (dblcmp((sum[b] - sum[0]) * a, (sum[b] - sum[b - a]) * b) < 0)
        printf("BUY ON DAY %d\n", b);
    else
        printf("SELL ON DAY %d\n", b);
    for (int i = b + 1; i <= n; i++)
        if (dblcmp((sum[i] - sum[i - b]) * a, (sum[i] - sum[i - a]) * b) < 0
                && dblcmp((sum[i - 1] - sum[i - b - 1]) * a, (sum[i - 1]
                        - sum[i - a - 1]) * b) > 0)
            printf("BUY ON DAY %d\n", i);
        else if (dblcmp((sum[i] - sum[i - b]) * a, (sum[i] - sum[i - a]) * b)
                > 0 && dblcmp((sum[i - 1] - sum[i - b - 1]) * a, (sum[i - 1]
                - sum[i - a - 1]) * b) < 0)
            printf("SELL ON DAY %d\n", i);
    return 0;
}



