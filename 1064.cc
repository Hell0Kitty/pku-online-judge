#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 10005

int n, k;
long long f[maxn];
long long sum;

bool ok(long long a)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += f[i] / a;
    return cnt >= k;
}

long long binarysearch(long long l, long long r)
{
    while (l < r)
    {
        long long mid = (l + r) / 2 + ((l + r) & 1);
        if (!ok(mid))
            r = mid - 1;
        else
            l = mid;
    }
    if (!ok(l))
        return -1;
    return l;
}

int main()
{

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        double a;
        scanf("%lf", &a);
        f[i] = a * 100;
        sum += f[i];
    }
    long long ans = binarysearch(1, sum / k);
    if (ans == -1)
        printf("0.00\n");
    else
        printf("%lld.%02lld\n", ans / 100, ans % 100);
    return 0;
}


