#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int INF = 10000000;
const int N = 160;
int n,p,root;
int head[N],son[N],dp[N][N];
bool f[N];

int min(int a, int b) {return  a < b ? a : b;}

void dfs(int v)
{
    int i,j,k;
    for(i = 0; i <= p; i++) dp[v][i] = INF;
    dp[v][1] = 0;
    int s = son[v];
    while(s)
    {
        dfs(s);
        for(i = p; i >= 0; i--)
        {
            int tmp = dp[v][i]+1;
            for(j = 1; j < i; j++)
                tmp = min(tmp, dp[v][j]+dp[s][i-j]);
            dp[v][i] = tmp;
        }
        s = head[s];
    }
}

int main()
{
    int i,j,k;
    while(~scanf("%d%d", &n, &p))
    {
        memset(son, 0, sizeof(son));
        memset(f, 1, sizeof(f));
        for(i = 1; i < n; i++)
        {
            scanf("%d%d", &j, &k);
            head[k] = son[j];
            son[j] = k;
            f[k] = 0;
        }
        for(i = 1; i <= n; i++)
            if(f[i]) {root = i;break;}
        dfs(root);
        int ans = dp[root][p];
        for(i = 1; i <= n; i++)
            ans = min(ans, dp[i][p]+1);
        printf("%d\n", ans);
    }
    return 0;
}



