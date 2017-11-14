#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 105

char st1[maxn], st2[maxn];
int len;

int gcd(int a, int b)
{
    if (a == 0)
        return 1;
    b %= a;
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int cal(char *st1, char *st2)
{
    int ret = 0;
    for (int i = 0; st1[i] && st2[i]; i++)
        if (st1[i] == st2[i])
            ret++;
    return ret;
}

int work()
{
    int len1 = strlen(st1);
    int len2 = strlen(st2);
    int ret = cal(st1, st2);

    len = len1 + len2;
    for (int i = 1; i < len1; i++)
        ret = max(ret, cal(st1 + i, st2));
    for (int i = 1; i < len2; i++)
        ret = max(ret, cal(st1, st2 + i));
    return ret;    
}

int main()
{
    while (scanf("%s", st1), strcmp(st1, "-1"))
    {
        scanf("%s", st2);
        int ans = work() * 2;
        int g = gcd(ans, len);
        ans /= g;
        len /= g;
        printf("appx(%s,%s) = ", st1, st2);
        if (ans == 0)
            puts("0");
        else if (len == 1)
            printf("%d\n", ans);
        else
            printf("%d/%d\n", ans, len);
    }
    return 0;
}


