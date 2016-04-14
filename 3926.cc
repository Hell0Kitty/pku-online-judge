#include <iostream>
#include <cstdio>
#include <string.h>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
using namespace std;
const int inf = 1 << 29;
const int maxn = 105;
const int maxm = 10005;
struct node
{
    int pos;
    int val;
}Q[maxm];
int suw[maxn][maxm],sul[maxn][maxm],dp[2][maxm];
char str[2000001];
int k,m,n,wei;

int getint()
{
    int data = 0,u = 1;
    while(str[wei] < '0' || str[wei] > '9' ) wei++;
    if(wei && str[wei-1]=='-')  u = -1;
    while(str[wei] >= '0' && str[wei] <= '9')
    {
        data = data * 10 + str[wei] - '0';
        wei++;
    }
    return data * u;
}

void read()
{
    for(int i=n+1;i>=1;i--)
    {
        suw[i][0] = 0;
        gets(str);
        wei = 0;
        for(int j=1;j<=m;j++)
        {
            suw[i][j] = getint();
            suw[i][j] += suw[i][j-1];
        }
    }
    for(int i=n+1;i>=1;i--)
    {
        sul[i][0] = 0;
        gets(str);
        wei = 0;
        for(int j=1;j<=m;j++)
        {
            sul[i][j] = getint();
            sul[i][j] += sul[i][j-1];
        }
    }
    return;
}

void init(int cho,int val)
{
    for(int i=0;i<=m;i++)
    {
        dp[cho][i] = val;
    }
    return;
}

void solve()
{
    init(0,0);
    for(int i=1;i<=n+1;i++)
    {
        int cur = i & 1;
        int pre = cur ^ 1;
        init(cur,-inf);
        int head = 0,rear = 0;
        for(int j=0;j<=m;j++)
        {
            int tmp = dp[pre][j] - suw[i][j];
            while(head < rear && Q[rear-1].val <= tmp)
            {
                rear--;
            }
            Q[rear].pos = j;
            Q[rear++].val = tmp;
            while(head < rear && sul[i][j] - sul[i][Q[head].pos] > k)
            {
                head++;
            }
            dp[cur][j] = MAX(dp[cur][j] , Q[head].val + suw[i][j]);
        }
        head = rear = 0;
        for(int j=m;j>=0;j--)
        {
            int tmp = dp[pre][j] + suw[i][j];
            while(head < rear && Q[rear-1].val <= tmp)
            {
                rear--;
            }
            Q[rear].pos = j;
            Q[rear++].val = tmp;
            while(head < rear && sul[i][Q[head].pos] - sul[i][j] > k)
            {
                head++;
            }
            dp[cur][j] = MAX(dp[cur][j] , Q[head].val - suw[i][j]);
        }
    }
    int res = -inf;
    for(int i=0;i<=m;i++)
    {
        res = MAX(res , dp[(n+1) & 1][i]);
    }
    printf("%d\n",res);
    return;
}

int main()
{
    while(gets(str))
    {
        wei = 0;
        n = getint();
        m = getint();
        k = getint();
        if(n+m+k == 0) break;
        read();
        solve();
    }
    return 0;
}



