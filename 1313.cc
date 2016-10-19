#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 105

int f[maxn][2];
int n;

void work()
{
    int page_num = (n + 3) / 4;
    for (int i = 0; i < page_num * 2; i++)
        f[i][(i & 1) ^ 1] = i + 1;
    int j = page_num * 2 + 1;
    for (int i = page_num * 2 - 1; i >= 0; i--, j++)
        f[i][i & 1] = j;
}

void output()
{
    int page_num = (n + 3) / 4;
    for (int i = 0; i < page_num * 2; i++)
    {
        if (f[i][0] > n && f[i][1] > n)
            continue;
        printf("Sheet %d, ", i / 2 + 1);
        if (i & 1)
            printf("back :");
        else
            printf("front:");
        if (f[i][0] <= n)
            printf(" %d", f[i][0]);
        else
            printf(" Blank");
        if (f[i][1] <= n)
            printf(", %d", f[i][1]);
        else
            printf(", Blank");
        puts("");
    }
}

int main()
{
    while (scanf("%d", &n), n)
    {
        printf("Printing order for %d pages:\n", n);
        work();
        output();
    }
    return 0;
}


