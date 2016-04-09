#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxd 105

int n, q;
int f[maxd];

void input()
{
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            int a;
            scanf("%d", &a);
            f[a]++;
        }
    }
}

void work()
{
    int temp = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (f[i] > f[temp])
            temp = i;
    }
    if (f[temp] < q)
        printf("0\n");
    else
        printf("%d\n", temp);
}

int main()
{

    while (scanf("%d%d", &n, &q), n | q)
    {
        input();
        work();
    }
    return 0;
}



