#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 100

int f1[maxn], f2[maxn], count1, count2;

void make(int x, char *st)
{
    if (strcmp(st, "too high") == 0)
        f1[count1++] = x;
    else
        f2[count2++] = x;
}

bool check(int x)
{
    for (int i = 0; i < count1; i++)
        if (f1[i] <= x)
            return false;
    for (int i = 0; i < count2; i++)
        if (f2[i] >= x)
            return false;
    return true;
}

int main()
{
    int x;
    char st[30];
    while (scanf("%d", &x), x != 0)
    {
        count1 = 0;
        count2 = 0;
        getchar();
        gets(st);
        if (strcmp(st, "right on") == 0)
        {
            printf("Stan may be honest\n");
            continue;
        }
        make(x, st);
        while (1)
        {
            scanf("%d", &x);
            getchar();
            gets(st);
            if (strcmp(st, "right on") == 0)
                break;
            make(x, st);
        }
        if (check(x))
            printf("Stan may be honest\n");
        else
            printf("Stan is dishonest\n");
    }
    return 0;
}



