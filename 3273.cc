#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100005

int n, m, f[maxn], l, r, mid;

void init()
{
    scanf("%d%d", &n, &m);
    l =0;
    r =0;
    for (int i =0; i < n; i++)
    {
        scanf("%d", &f[i]);
        if (l < f[i])
            l = f[i];
        r += f[i];
    }
}

bool ok(int a)
{
    int sum =0, j =0;

    for (int i =0; i < n; i++)
    {
        if (sum + f[i] > a)
        {
            sum = f[i];
            j++;
        }
        else
            sum += f[i];
    }
    j++;
    if (j > m)
        return false;
    return true;
}

void binarysearch()
{
    while (l < r)
    {
        mid = (l + r) /2;
        if (!ok(mid))
            l = mid +1;
        else
            r = mid;
    }
    printf("%d\n", l);
}

int main()
{
    init();
    binarysearch();
    return 0;
}


