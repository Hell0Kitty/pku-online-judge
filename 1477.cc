#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 55

int n;
int f[maxn];

int main()
{
    int t = 0;
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &f[i]);
        int mean = 0;
        for (int i = 0; i < n; i++)
            mean += f[i];
        mean /= n;
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs(f[i] - mean);
        printf("Set #%d\n", ++t);
        printf("The minimum number of moves is %d.\n", ans / 2);
        puts("");
    }
    return 0;
}


