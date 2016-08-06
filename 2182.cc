#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 8005

int n, f[maxn];
int ar[maxn];
int ans[maxn];

int lowb(int t)
{
    return t &(-t);
}

void add(int i, int v)
{
    for (; i < maxn; ar[i] += v, i += lowb(i));
}

int sum(int i)
{
    int s =0;
    for (; i >0; s += ar[i], i -= lowb(i));
    return s;
}

int calspace(int index)
{
    return index - sum(index);
}

int binarysearch(int a)
{
    int l =1;
    int r = n;
    int mid;
    while (l < r)
    {
        mid = (l + r) /2;
        int temp = calspace(mid);
        if (temp < a)
            l = mid +1;
        else
            r = mid;
    }
    return l;
}

int main()
{
    scanf("%d", &n);
    f[0] =0;
    for (int i =1; i < n; i++)
        scanf("%d", &f[i]);
    for (int i = n -1; i >=0; i--)
    {
        int a = binarysearch(f[i] +1);
        ans[i] = a;
        add(a, 1);
    }
    for (int i =0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}



