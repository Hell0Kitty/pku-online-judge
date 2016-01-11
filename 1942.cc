#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long n, m;

long long com(long long n, long long r)
{
    if (n - r < r)
        r = n - r;
    long long i, j, s = 1;
    for (i = 0, j = 1; i < r; i++)
    {
        s *= (n - i);
        for (; j <=r && s %j == 0; ++j) s /=j;
    }
    return s;
}

int main()
{
    while (scanf("%lld%lld", &n, &m), n | m)
        printf("%lld\n", com(n + m, n));
    return 0;
}



