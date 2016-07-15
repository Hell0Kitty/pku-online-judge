#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#define maxn 40
int n,m,k,sur_num,born_num;
int mice[maxn][maxn];
char s[20];
void Init()
{
    memset(mice,0,sizeof(mice));
    for(int i = 0; i <= 6; i++)
        mice[i][i] = 1;
}
void change()
{
    int i,t;
    n = m = k = 0;
    t = 1,i = strlen(s)-1;
    while(s[i] != ',')
    {
        k += t * (s[i]-'0');
        t *= 10;
        i--;
    }
    t = 1,i--;
    while(s[i] != ',')
    {
        m += t * (s[i]-'0');
        t *= 10;
        i--;
    }
    t = 1,i--;
    while(s[i] != ',' && i >= 0)
    {
        n += t * (s[i]-'0');
        t *= 10;
        i--;
    }
}
void solve()
{
    int i,j;
    for(i = 7; i <= k; i++)
    {
        sur_num = born_num = 0;
        for(j = 1; j <= n-1; j++)
            sur_num += mice[i-1][j];
        if(sur_num > 100)
            mice[i][1] = born_num;
        else
        {
            born_num += mice[i-1][6] + mice[i-1][7];
            for(j = 1; j <= m; j++)
                born_num += 2 * mice[i-1][7+j];
            mice[i][1] = born_num;
        }
        for(j = 2; j <= n; j++)
            mice[i][j] = mice[i-1][j-1];
    }
}
void print()
{
    int tal = 0;
    for(int j = 1; j <= n; j++)
        tal += mice[k][j];
    printf("%s: %d\n",s,tal);
}
int main()
{
    while(scanf("%s",s) && s[0] != '-')
    {
        int i,j;
        Init();
        change();
        solve();
        print();
    }
    return 0;
}


