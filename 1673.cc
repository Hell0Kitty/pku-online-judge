#include<stdio.h>
#include<string.h>
#include<math.h>
#define zero 1e-8
double x3, y3, x4, y4, x5, y5;
int dcmp(double x)
{
    return fabs(x) < zero ? 0 : (x < 0 ? -1 : 1);
}
void solve()
{
    double x, y, x1, y1, x2, y2, k1, k2;
    if(dcmp(y3 - y4) == 0)
    {
        k2 = (x4 - x5) / (y5 - y4);
        x = x5;
        y = k2 * (x - x3) + y3;
    }
    else
    {
        if(dcmp(y4 - y5) == 0)
        {
            k1 = (x3 - x4) / (y4 - y3);
            x = x3;
            y = k1 * (x - x5) + y5;
        }
        else
        {
            k1 = (x3 - x4) / (y4 - y3);
            k2 = (x4 - x5) / (y5 - y4);
            x = (k1 * x5 - k2 * x3 + y3 - y5) / (k1 - k2);
            y = k1 * (x - x5) + y5;
        }
    }
    printf("%.4lf %.4lf\n", x + zero, y + zero);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%lf%lf%lf%lf%lf%lf", &x3, &y3, &x4, &y4, &x5, &y5);
        solve();
    }
    return 0;
}



