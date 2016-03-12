#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void get_next(char* p, int next[])
{
    int k = -1;
    int j = 0;
    next[0] = -1;
    int len = strlen(p);
    while (j < len)
    {
        if (k == -1 || p[j] == p[k])
        {
            j++;
            k++;
            if (p[j] != p[k])
            {
                next[j] = k;
            }
            else
            {
                next[j] = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
}

int kmp(char* p, char* t, int next[])
{
    int ans = 0;
    int plen = strlen(p);
    int tlen = strlen(t);
    int i = 0, j = 0;
    while (i < tlen)
    {
        if (j == -1 || p[j] == t[i])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
        if (j == plen)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}
char t[1000010], p[1000010];
int next[1000010];
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", p);
        scanf("%s", t);
        get_next(p, next);
        int ans = kmp(p, t, next);
        printf("%d\n", ans);
    }
    return 0;
}
