#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define maxn 35
#define eps 10e-9

int map[maxn * maxn];
int n, m;
double water, least;

int dblcmp(double a, double b)
{
    if (fabs(a - b) < eps)
        return 0;
    if (a < b)
        return -1;
    return 1;
}

void input()
{
    least = 0x3f3f3f3f;
    for (int i = 0; i < n * m; i++)
    {
        scanf("%d", &map[i]);
        least = _cpp_min(least, double(map[i]));
    }
    scanf("%lf", &water);
}

bool high(double a)
{
    double sum = 0;
    for (int i = 0; i < n * m; i++)
        if (dblcmp(map[i], a) < 0)
            sum += (a - map[i]) * 100;
    return sum > water;
}

double binarysearch()
{
    double l = least;
    double r = water;
    while (dblcmp(l, r) < 0)
    {
        double mid = (l + r) / 2;
        if (high(mid))
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main()
{
    int t = 0;
    while (scanf("%d%d", &n, &m), n | m)
    {
        t++;
        input();
        int a = 0;
        double ans = binarysearch();
        for (int i = 0; i < n * m; i++)
            if (map[i] < ans)
                a++;
        printf(
                "Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n",
                t, ans, a * 100.0 / n / m);
    }
    return 0;
}



