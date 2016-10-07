#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define pi acos(-1)

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x1, y1, x2, y2, d1, d2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &d1, &x2, &y2, &d2);
        double k1 = tan((450 - d1)%180 * pi/ 180);
        double k2 = tan((450 - d2)%180 * pi/ 180);
        double x = (y2 - y1 - x2 * k2 + x1 * k1) / (k1 - k2);
        double y = ((x2 - x1) * k1 * k2 + y1 * k2 - y2 * k1) / (k2 - k1);
        printf("%.4f %.4f\n", x, y);
    }
    return 0;
}



