#include <stdio.h>
#include <string.h>
int n[1005], dp[1005][100005];
int main()
{
    #ifdef LOCAL
    freopen("data.in", "r", stdin);
    #endif

    int t, a, s, b, cur, ans;
    while(scanf("%d%d%d%d", &t, &a, &s, &b) != EOF)
    {
        memset(n, 0, sizeof(n));
        for(int i = 0; i < a; i++)
        {
            scanf("%d", &cur);
            n[cur]++;
        }
        for(int i = 0; i <= 100003; i++)
            dp[0][i] = 0;
        dp[0][0] = 1;
        for(int i = 1; i <= t; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= a; j++)
            {
                if(j - 1 - n[i] >= 0)
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]
                        - dp[i - 1][j - 1 - n[i]] + 1000000) % 1000000;
                }
                else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000;
            }
        }
        ans = 0;
        for(int i = s; i <= b; i++)
        {
            ans += dp[t][i];
            ans %= 1000000;
        }
        printf("%d\n", ans);
    }

    return 0;
}



