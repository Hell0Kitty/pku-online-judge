#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 45

int f[maxn];

int main()
{
    f[1] = 2;
    f[2] = 3;
    for (int i = 3; i < maxn; i++)
        f[i] = f[i - 1] + f[i - 2];
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int a;
        scanf("%d", &a);
        printf("Scenario #%d:\n%d\n\n", i, f[a]);
    }
    return 0;
}


