#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, size;

void work()
{
    scanf("%d", &n);
    size = n * 2 + 1;
    for (int i = 0; i < size; i++)
    {
        printf("slice #%d:\n", i + 1);
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                int d = abs(j - n) + abs(k - n);
                if (d + abs(i - n) > n)
                    putchar('.');
                else
                    printf("%d", d + abs(i - n));
            }
            putchar('\n');
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        printf("Scenario #%d:\n", i + 1);
        work();
        putchar('\n');
    }
    return 0;
}



