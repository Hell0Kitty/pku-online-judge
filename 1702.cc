#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 25

int n;
int f[maxn];
bool l[maxn], r[maxn];
int ans[maxn];

void print(bool x[])
{
    bool first = true;
    for (int i = 0; i < maxn; i++)
        if (x[i])
        {
            if (first)
                first = false;
            else
                putchar(',');
            printf("%d", ans[i]);
        }
    if (first)
        printf("empty");
}

int main()
{
    ans[0] = 1;
    for (int i = 1; i <= 19; i++)
        ans[i] = ans[i - 1] * 3;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x;
        scanf("%d", &x);
        n = 0;
        memset(f, 0, sizeof(f));
        while (x > 0)
        {
            f[n++] = x % 3;
            x /= 3;
        }
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        int j = 0;
        for (int i = 0; i < maxn; i++)
        {
            int x = f[i] + j;
            if (x < 2)
            {
                f[i] = x;
                r[i] = x;
                j = 0;
                continue;
            }else
            {
                l[i] = (x == 2);
                f[i] = 0;
                j = 1;
            }
        }
        print(l);
        putchar(' ');
        print(r);
        putchar('\n');
    }
    return 0;
}


