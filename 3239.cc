#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;

int main()
{
while (scanf("%d", &n), n)
    {
        if (n %6!=2&& n %6!=3)
        {
            printf("2");
            for (int i =4; i <= n; i +=2)
                printf(" %d", i);
            for (int i =1; i <= n; i +=2)
                printf(" %d", i);
            putchar('\n');
            continue;
        }
        int k = n /2;
        printf("%d", k);
        if (!(k &1) &&!(n &1))
        {
            for (int i = k +2; i <= n; i +=2)
                printf(" %d", i);
            for (int i =2; i <= k -2; i +=2)
                printf(" %d", i);
            for (int i = k +3; i <= n -1; i +=2)
                printf(" %d", i);
            for (int i =1; i <= k +1; i +=2)
                printf(" %d", i);
        }
        else if (!(k &1) && (n &1))
        {
            for (int i = k +2; i <= n -1; i +=2)
                printf(" %d", i);
            for (int i =2; i <= k -2; i +=2)
                printf(" %d", i);
            for (int i = k +3; i <= n -2; i +=2)
                printf(" %d", i);
            for (int i =1; i <= k +1; i +=2)
                printf(" %d", i);
            printf(" %d", n);
        }
        else if ((k &1) &&!(n &1))
        {
            for (int i = k +2; i <= n -1; i +=2)
                printf(" %d", i);
            for (int i =1; i <= k -2; i +=2)
                printf(" %d", i);
            for (int i = k +3; i <= n; i +=2)
                printf(" %d", i);
            for (int i =2; i <= k +1; i +=2)
                printf(" %d", i);
        }
        else if ((k &1) && (n &1))
        {
            for (int i = k +2; i <= n -2; i +=2)
                printf(" %d", i);
            for (int i =1; i <= k -2; i +=2)
                printf(" %d", i);
            for (int i = k +3; i <= n -1; i +=2)
                printf(" %d", i);
            for (int i =2; i <= k +1; i +=2)
                printf(" %d", i);
            printf(" %d", n);
        }
        putchar('\n');
    }
    return 0;
}



