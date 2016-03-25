#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct clothes
{
	char color[12]; // 每种衣服颜色
	int num; //每种衣服的数量
	int sum; //洗每种衣服所用总时间
	int time[105]; //这种衣服中每一件用的时间
}clo[11];
int main()
{
	int m, n, i, j, k, time;
	int dp[500005];
    char color[12];
	while(~scanf("%d%d", &m, &n) && (m + n))
	{
		for(i = 0; i < m; i++)
		{
			scanf("%s", clo[i].color);
			clo[i].num = clo[i].sum = 0;
		}
		for(i = 0; i < n; i++)
		{
			scanf("%d%s",&time, color);
			for(j = 0; j < m; j++)
			{
				if(!strcmp(color,clo[j].color))
				{
					int tmp = clo[j].num; //第j种第clo[j].num件,
					clo[j].time[tmp] = time;
					clo[j].sum += time;
					clo[j].num++; //第j种数量加1
				}
			}
		}
		int Ans = 0;
		for(i = 0; i < m; i++)
		{
			memset(dp,0,sizeof(dp));
			int tmp_sum = clo[i].sum / 2;
			for(j = 0; j < clo[i].num; j++)
			{
				for(k = tmp_sum; k >= clo[i].time[j]; k--)
				{
					dp[k] = max(dp[k], dp[k - clo[i].time[j]] + clo[i].time[j]);
				}
			}
			Ans += clo[i].sum - dp[tmp_sum];
		}
		printf("%d\n",Ans);
	}
	return 0;
}



