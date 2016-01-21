#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 100005

int n, m, f[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &f[i]);
    sort(f, f + n);
    char st[30];
    scanf("%s", st);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", f[a - 1]);
    }
    return 0;
}



