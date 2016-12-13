#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define eps 1.0e-8

double c, l1, n;

double cal(double b)
{
    double a = l1 /2;
    double d = sqrt(a * a + b * b);
    double h = a * d / b;
    double r = sqrt(h * h + d * d) /2;
    return atan(b / (l1 /2)) *4* r;
}

int main()
{
   while (scanf("%lf%lf%lf", &l1, &n, &c) != EOF)
    {
        if (n <0&& l1 <0&& c <0)
            break;
        double l2 = l1 * (n * c +1);
        if (l2 - l1 < eps)
        {
            printf("0.000\n");
            continue;
        }
        double l = eps;
        double r = l1 /2;
        double mid;
        while (abs(l - r) > eps)
        {
            mid = (l + r) /2;
            double x = cal(mid);
            if (abs(x - l2) < eps)
                break;
            if (x > l2)
                r = mid - eps;
            else
                l = mid + eps;
        }
        printf("%.3f\n", mid);
    }
    return 0;
}



