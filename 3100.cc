#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{

    int b, n;
    while (scanf("%d%d", &b, &n) != EOF && !(b == 0 && n == 0))
    {
        double a = pow(b, 1.0 / n);
        int a1, a2;
        a1 = (int) floor(a);
        a2 = (int) ceil(a);
        int d1 = abs((int) pow((double) a1, n) - b);
        int d2 = abs((int) pow((double) a2, n) - b);
        if (d1 > d2)
            printf("%d\n", a2);
        else
            printf("%d\n", a1);
    }
    return 0;
}


