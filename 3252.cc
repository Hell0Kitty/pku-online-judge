#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long s, e;
long long f[50];

long long com(long long n, long long r)
{
    if (n <=0)
        return 1;
    if (n - r < r)
        r = n - r;
    long long i, j, s =1;
    for (i =0, j =1; i < r; ++i)
    {
        s *= (n - i);
        for (; j <= r && s % j ==0; ++j)
            s /= j;
    }
    return s;
}

long long cal(long long a)
{
    long long num1, num0, bit =0, ret =0;
    num1 = num0 =0;
    long long x =1;
    while (x <= a)
    {
        x <<=1;
        bit++;
    }
    for (int i =1; i < bit; i++)
        for (int j =0; j <= i /2-1; j++)
            ret += com(i -1, j);
    long long pos = bit;
    x >>=1;
    num1++;
    while (pos--, x >>=1)
    {
        if (x & a)
            num1++;
        else
        {
            num0++;
            continue;
        }
        for (long long i = pos -1; num1 -1+ (pos -1- i)<= num0 +1+ i && i >=0; i--)
            ret += com(pos -1, i);
    }
    return ret;
}

int main()
{
    scanf("%lld%lld", &s, &e);
    printf("%lld\n", cal(e +1) - cal(s));
    return 0;
}


