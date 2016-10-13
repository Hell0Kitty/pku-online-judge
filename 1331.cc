#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxl 20

char p[maxl], q[maxl], r[maxl];

long long cal(char *st, int base)
{
    long long x = 1, ret = 0;
    for (int i = strlen(st) - 1; i >= 0; i--)
    {
        ret += x * (st[i] - '0');
        x *= base;
    }
    return ret;
}

int getmax(char *st)
{
    char ret = '0';
    for (int i = 0; i < strlen(st); i++)
        ret = max(ret, st[i]);
    return ret - '0' + 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%s%s", p, q, r);
        int ans = 0;
        int start = 2;
        start = max(start, getmax(p));
        start = max(start, getmax(q));
        start = max(start, getmax(r));
        for (int i = start; i <= 16; i++)
            if (cal(p, i) * cal(q, i) == cal(r, i))
            {
                ans = i;
                break;
            }
        printf("%d\n", ans);
    }
    return 0;
}


