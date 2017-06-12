#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 10005

int a[maxn];
int cnt, n;

int findit()
{
    for (int i = 1; i <= n; i++)
        if (a[i] != i)
            return i;
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        cnt = 0;
        int temp = 1;
        while (1)
        {
            if (a[temp] == temp)
                temp = findit();
            if (temp == -1)
                break;
            swap(a[temp], a[a[temp]]);
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}



