#include "iostream"
#include "cstdio"
#include "cmath"
#include "cstring"
using namespace std;
typedef unsigned long long ull;
const ull mod = 10000000000;

char s[12];
int re[12];
ull cub[12], po[12];
int n;

ull cal(ull ans, int i, int j)
{
    ull tmp = (3*j*po[i])%po[i+1];
    tmp = (((tmp*ans)%po[i+1])*ans)%po[i+1];
    ull tp2 = (((ans*ans)%po[i+1])*ans)%po[i+1];
    return ((tmp+tp2)/po[i])%10;
}

bool dfs(int i, ull ans)
{
    if(i >= n) return true;
    for(int j = 0; j <= 9; j++)
    {
        if(cal(ans, i, j) == s[n-1-i]-'0')
        {
            re[n-1-i] = j;
            if(dfs(i+1, ans+j*po[i])) return true;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    po[0] = 1;
    for(int i = 1; i < 12; i++) po[i] = po[i-1]*10;
    while(t--)
    {
        scanf("%s",s);
        n = strlen(s);

        if(s[n-1] == '3') re[n-1] = 7;
        else if(s[n-1] == '7') re[n-1] = 3;
        else re[n-1] = s[n-1]-'0';
        dfs(1, re[n-1]);

        int i = 0;
        while(re[i] == 0) i++;
        while(i < n)
        {
            printf("%d",re[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}



