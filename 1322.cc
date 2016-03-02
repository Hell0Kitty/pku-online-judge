#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

double dp[2][102];

int main()
{
	int c, n, m, i, j;

	while(scanf("%d", &c) && c)
	{
		scanf("%d %d", &n, &m);
		if(m > n || m > c || (m + n) % 2){
		    printf("0.000\n");
			continue;
		}
		if(n > 1001)
			n = n % 2 ? 1001 : 1000;

		memset(dp, 0, sizeof(dp));
        dp[0][0] = 1.0;
        for(i = 1; i <= n; i++){
			for(j = 0; j <= i && j <= c; j++){
				dp[i%2][j] = 0.0;
				if((i + j) % 2) continue;
				if(j > 0)
			        dp[i%2][j] += dp[1-i%2][j-1] * ((c-j+1.0)*1.0/c);
				if(j+1 <= i-1)
					dp[i%2][j] += dp[1-i%2][j+1] * ((j+1.0)*1.0/c);
			}
		}
		printf("%.3lf\n", dp[n%2][m]);
	}
	return 0;
}


