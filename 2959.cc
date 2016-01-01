#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

#define pi acos(-1)

double d, D, r, s;

int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lf%lf%lf", &D, &d, &s);
        d /= 2;
        D /= 2;
        r = D - d;
        d = 2 * d + s;
        int ans = (int)(2 * pi / acos((r * r * 2 - d * d) / (2 * r * r)));
        printf("%d\n", ans);
    }
    return 0;
}



