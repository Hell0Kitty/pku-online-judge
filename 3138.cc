#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxs 105

int s, n, m;
int school[maxs];
int prob[maxs];

void input()
{
    for (int i = 0; i < s; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        school[a] = b + c;
    }
    memset(prob, 0, sizeof(prob));
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b >= m)
            prob[a] = true;
    }
}

int cal()
{
    int ret = 0;
    for (int i = 1; i <= s; i++)
    {
        int a = school[i] + prob[i];
        if (a > 3)
            a = 3;
        ret += a;
    }
    return ret;
}

int main()
{
    int t = 0;
    while (scanf("%d%d%d", &s, &n, &m), s | n | m)
    {
        t++;
        input();
        printf("Case %d: %d\n", t, cal());
    }
    return 0;
}




