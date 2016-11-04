#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxl 1005

char st[maxl];
char ans[maxl];

void work()
{
    int len = strlen(st);
    int i = 0;
    int l = 0;
    int r;
    while (l < len)
    {
        r = l + 1;
        if (r < len && st[r] == st[l])
        {
            while (r < len && st[r] == st[l] && r - l < 9)
                r++;
            ans[i++] = '0' + r - l;
            ans[i++] = st[l];
            l = r;
        }else
        {
            while (r < len &&((r + 1 < len && st[r] != st[r + 1]) || r == len - 1))
                r++;
            ans[i++] = '1';
            for (int j = l; j < r; j++)
            {
                if (st[j] == '1')
                    ans[i++] = '1';
                ans[i++] = st[j];
            }
            ans[i++] = '1';
            l = r;
        }
    }
    ans[i] = '\0';
    printf("%s\n", ans);
}

int main()
{

    while (gets(st))
    {
        work();
    }
    return 0;
}



