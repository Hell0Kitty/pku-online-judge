#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long a[3][3], b[3];

void input()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            scanf("%lld", &a[i][j]);
        scanf("%lld", &b[i]);
    }
}

long long cal()
{
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1]
            * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0]
            * a[2][1] - a[1][1] * a[2][0]);
}

double val(double a)
{
    if (a < 0.0005 && -0.0005 < a)
        return 0;
    return a;
}

void work()
{
    long long A = cal();
    long long ans[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            swap(b[j], a[j][i]);
        ans[i] = cal();
        for (int j = 0; j < 3; j++)
            swap(b[j], a[j][i]);
    }
    for (int i = 0; i < 3; i++)
        printf("%lld ", ans[i]);
    printf("%lld\n", A);
    if (A == 0)
        printf("No unique solution\n");
    else
    {
        printf("Unique solution:");
        for (int i = 0; i < 3; i++)
            printf(" %.3f", val(ans[i] * 1.0 / A));
        putchar('\n');
    }
    putchar('\n');
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



