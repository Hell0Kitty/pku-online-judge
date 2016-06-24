#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

int a, b;

Point cal(int a)
{
    Point ret;
    if (a == 1)
    {
        ret.x = 0;
        ret.y = 0;
        return ret;
    }
    int n = sqrt((a - 1) / 3);
    while (3 * (n - 1) * n + 1 < a)
        n++;
    while (3 * (n - 1) * n + 1 >= a)
        n--;
    a -= 3 * (n - 1) * n + 1;
    if (a <= n)
    {
        ret.x = n;
        ret.y = -a;
    }else if (a > n && a <= 2 * n)
    {
        ret.x = n - a + n;
        ret.y = -n;
    }else if (a > 2 * n && a <= 3 * n)
    {
        ret.x = 2 * n - a;
        ret.y = -n - ret.x;
    }else if (a > 3 * n && a <= 4 * n)
    {
        ret.x = -n;
        ret.y = a - 3 * n;
    }else if (a > 4 * n && a <= 5 * n)
    {
        ret.x = (a - 4 * n) - n;
        ret.y = n;
    }else
    {
        ret.x = a - 5 * n;
        ret.y = n - ret.x;
    }
    return ret;
}

int main()
{
      while (scanf("%d%d", &a, &b), a | b)
    {
        Point p = cal(a);
        Point q = cal(b);
        Point ans;
        ans.x = p.x - q.x;
        ans.y = p.y - q.y;
        int temp;
        if (ans.x * ans.y <= 0)
            temp = max(abs(ans.x), abs(ans.y));
        else
            temp = abs(ans.x + ans.y);
        printf("The distance between cells %d and %d is %d.\n", a, b, temp);
    }
    return 0;
}



