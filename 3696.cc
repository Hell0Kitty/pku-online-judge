#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn (1 << 16)

long long n;
long long factor[maxn];

long long euler(long long n)
{
    long long ret = n;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            ret = ret / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ret = ret / n * (n - 1);
    return ret;
}

long long mult(long long a, long long b, long long p)
{
    long long ret = 0;
    while (b)
    {
        if (b & 1)
            ret = (ret + a) % p;
        a = 2 * a % p;
        b >>= 1;
    }
    return ret;
}

long long power(long long x, long long n, long long p)
{
    long long ret = 1;
    x %= p;
    while (n)
    {
        if (n & 1)
            ret = mult(ret, x, p);
        x = mult(x, x, p);
        n >>= 1;
    }
    return ret;
}

long long work()
{
    n *= 9;
    for (int i = 0; i < 3; i++)
        if (n % 2 == 0)
            n /= 2;
        else
            break;
    long long p = n;
    if (p % 2 == 0 || p % 5 == 0)
        return 0;
    long long phi = euler(p);
    int cnt = 0;
    for (long long i = 1; i * i <= phi; i++)
        if (phi % i == 0)
        {
            factor[cnt++] = i;
            factor[cnt++] = phi / i;
        }
    sort(factor, factor + cnt);
    for (int i = 0; i < cnt; i++)
        if (power(10, factor[i], p) == 1)
            return factor[i];
    return 0;
}

int main()
{
    int t = 0;
    while (scanf("%lld", &n), n)
    {
        t++;
        printf("Case %d: ", t);
        printf("%lld\n", work());
    }
    return 0;
}



