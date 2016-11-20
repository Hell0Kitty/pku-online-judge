#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 10

struct Partition
{
    long long a, b;
    Partition(long long aa, long long bb) :
        a(aa), b(bb)
    {
    }
    Partition()
    {
    }
} par[maxn];

long long ans;
long long p, q, a, n;

bool operator<(const Partition &x, const Partition &y)
{
    return x.a * y.b < y.a * x.b;
}

long long gcd(long long x, long long y)
{
    if (!x ||!y)
        return x > y ? x : y;
    for (long long t; t = x % y; x = y, y = t)
        ;
    return y;
}

Partition abstract(Partition a, Partition b)
{
    Partition ret;
    ret.b = a.b * b.b;
    ret.a = a.a * b.b - b.a * a.b;
    long long g = gcd(ret.a, ret.b);
    ret.a /= g;
    ret.b /= g;
    return ret;
}

void dfs(long long t, Partition left, long long sum)
{
    if (left.b / left.a * sum > a)
        return;
    if (left.a ==1&& left.b >= par[t -1].b && sum * left.b <= a)
    {
        ans++;
    }
    if (t >= n)
        return;
    if ((n - t +1.0) * left.b / left.a < par[t -1].b)
        return;
    for (long long i = max(par[t -1].b, left.b / left.a); sum * i <= a && (n - t +1.0) * left.b / left.a >= i; i++)
    {
        par[t].a =1;
        par[t].b = i;
        if (par[t] < left)
        {
            dfs(t +1, abstract(left, par[t]), sum * i);
        }
    }
}

int main()
{
   while (scanf("%lld%lld%lld%lld", &p, &q, &a, &n), p | q | a | n)
    {
        ans =0;
        par[0].a = par[0].b =1;
        long long g = gcd(p, q);
        dfs(1, Partition(p / g, q / g), 1);
        printf("%lld\n", ans);
    }
    return 0;
}



