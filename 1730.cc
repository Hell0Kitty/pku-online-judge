#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define eps 1.0e-12

long long n;

void work()
{
    bool fu =false;
    if (n <0)
    {
        fu =true;
        n =-n;
    }
    for (int i =32; i >=1; i--)
        if (!fu || (fu && (i &1)))
        {
            double a = pow(double(n), 1.0/ i);
            long long x = a;
            if (abs(a - x) < eps || abs(a - x -1) < eps)
            {
                printf("%d\n", i);
                return;
            }
        }
}

int main()
{
    while (scanf("%lld", &n), n)
        work();
    return 0;
}