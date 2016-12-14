#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 200

char st[maxn], up[maxn], down[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s%s%s", st, up, down);
        int len1 = strlen(st);
        int len2 = strlen(up);
        int temp = 0;
        for (int i = 0; i < len2 && temp < len1; i++)
            if (up[i] == st[temp] || down[i] == st[temp] || up[i] == '*' || down[i] == '*')
                temp++;
        if (temp == len1)
            printf("win\n");
        else
            printf("lose\n");
    }
    return 0;
}


