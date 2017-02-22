#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

struct Elem
{
    int a, b;
}ans;

double n;
int lim;

int binarysearch(int x)
{
    int l = 1;
    int r = min(lim, x * 10);
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid * 1.0 / x < n)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

void make(int a, int b)
{
    if (abs(a * 1.0 / b - n) < abs(ans.a * 1.0 / ans.b - n))
    {
        ans.a = a;
        ans.b = b;
    }
}

int main()
{
    scanf("%lf%d", &n, &lim);
    ans.a = (int)(n + 0.5);
    ans.b = 1;
    if (ans.a == 0)
        ans.a = 1;
    if (ans.a > lim)
        ans.a = lim;
    for (int i = 2; i <= lim; i++)
    {
        int x = binarysearch(i);
        make(x, i);
        if (x > 1)
            make(x - 1, i);
    }
    printf("%d %d\n", ans.a, ans.b);
    return 0;
}



