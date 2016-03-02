#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>

#define	inf	(-0x3f3f3f3f)
const int maxn = 10010;
#define max(a,b)	((a)>(b)?(a):(b))

int dp[maxn], path[maxn], used[maxn];

int main()
{
	int num[4], val[4] = {1, 5, 10, 25};
	int n;
	while (scanf("%d %d %d %d %d", &n, &num[0], &num[1], &num[2], &num[3]))
	{
		if(n==0&&num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0)break;
		memset(dp, inf, sizeof(dp));
		memset(path, 0, sizeof(path));
		path[0] = -1;
		dp[0] = 0;

		int i, j;
		for (i=0; i<4; i++)
		{
			memset(used, 0, sizeof(used));
			for (j=val[i]; j<=n; j++)
			{
				if (dp[j-val[i]] + 1 > dp[j] && dp[j-val[i]] >= 0 && used[j-val[i]] < num[i])
				{
					dp[j] = dp[j-val[i]] + 1;
					used[j] = used[j-val[i]] + 1;
					path[j] = j - val[i];
				}
			}
		}
		int ans[100];
		memset(ans, 0, sizeof(ans));
		if (dp[n] < 0)
		{
			puts("Charlie cannot buy coffee.");
		}
		else
		{
			while (path[n] != -1)
			{
				ans[n-path[n]] ++;
				n = path[n];
			}
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", ans[val[0]], ans[val[1]], ans[val[2]], ans[val[3]]);
		}
	}
	return 0;
}



