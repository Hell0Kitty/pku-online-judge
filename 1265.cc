#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct Point
{
    int x, y;
} s, e;

int t, n;

int gcd(int x, int y)
{
    if (!x || !y)
        return x > y ? x : y;
    for (int t; t = x % y; x = y, y = t)
        ;
    return y;
}

void work()
{
    int x, y;
    scanf("%d", &n);
    s.x = 0;
    s.y = 0;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        e.x = s.x + x;
        e.y = s.y + y;
        ans += e.y * s.x - e.x * s.y;
        cnt += gcd(abs(x), abs(y));
        s = e;
    }
    printf("%d %d %.1f\n", (ans - cnt) / 2 + 1, cnt, ans / 2.0);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Scenario #%d:\n", i + 1);
        work();
        putchar('\n');
    }
    return 0;
}


