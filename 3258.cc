#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 50005

int p, n, m, ans;
int rock[maxn];

bool ok(int l)
{
    int d =0;
    int j =0;
    int t = n -1;
    while (t >=0&& rock[n -1] - rock[t] < l)
        t--;
    if (t <0)
        return false;
    d = n - t -1-1;
    for (int i =1; i <= t; i++)
        if (rock[i] - rock[j] < l)
            d++;
        else
            j = i;
    if (d <= m)
        return true;
    return false;
}

void binarysearch()
{
    int l =1;
    int r = p;

    while (l < r)
    {
        int mid = (l + r) /2;
        mid += (l + r) &1;
        if (ok(mid))
            l = mid;
        else
            r = mid -1;
    }
    ans = l;
}

int main()
{

    scanf("%d%d%d", &p, &n, &m);
    rock[0] =0;
    rock[1] = p;
    for (int i =2; i <= n +1; i++)
        scanf("%d", &rock[i]);
    n +=2;
    sort(rock, rock + n);
    binarysearch();
    printf("%d\n", ans);
    return 0;
}



