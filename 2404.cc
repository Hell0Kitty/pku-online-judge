#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include<cstdlib>

using namespace std;

#define N 1005
#define L(x) x<<1
#define R(x) x<<1|1
#define M(x,y) (x + y)>>1
#define MOD 1000000007
#define MODD 1000000006
#define inf 0x7fffffff
#define llinf 0x7fffffffffffffff
#define LL long long

struct st
{
	void insert(int x,int y,int z)
	{
		u = x,v = y,w = z;
	}
	int u,v,w;
}s[N];

int maps[20][20];
int mark[20],cnt;
int dp[40000];
bool flag[40000];
int binary[20] = {0,1,1<<1,1<<2,1<<3,1<<4,1<<5,1<<6,1<<7,1<<8,1<<9,1<<10,1<<11,1<<12,1<<13,1<<14,1<<15,1<<16,1<<17,1<<18};

int main()
{
	int i,j,k,l;
	int n,m;
	//cout<<binary[16] - 1<<endl;
	while(scanf("%d",&n) && n)
	{
		scanf("%d",&m);
		int ans = 0;
		cnt = 0;
		memset(mark,0,sizeof(mark));
		memset(maps,-1,sizeof(maps));
		memset(dp,-1,sizeof(dp));
		memset(flag,0,sizeof(flag));
		for(i = 1;i <= m;i++)
		{
			scanf("%d%d%d",&j,&k,&l);
			mark[j]++;
			mark[k]++;
			if(maps[j][k] == -1)
				maps[j][k] = maps[k][j] = l;
			else
				maps[j][k] = maps[k][j] = min(maps[k][j],l);
			ans += l;
		}
		for(i = 1;i <= n;i++)
		{
			for(j = i + 1;j <= n;j++)
			{
				if(maps[i][j] != -1)
					s[cnt++].insert(i,j,maps[i][j]);
			}
		}
		int wtf = 0;
		for(i = 1;i <= n;i++)
		{
			if(mark[i]&1)
			{
				wtf += binary[i];
			}
		}
		dp[wtf] = ans;
		ans = inf;
		queue<int>q;
		q.push(wtf);
		flag[wtf] = 1;
		while(!q.empty())
		{
			i = q.front();
			q.pop();
			flag[i] = 0;
			{
				for(j = 0;j < cnt;j++)
				{
					int num = i;
					num ^= binary[s[j].u];
					num ^= binary[s[j].v];
					if(dp[num] == -1)
					{
						dp[num] = dp[i] + s[j].w;
						q.push(num);
						flag[num] = 1;
					}
					else if(dp[num] > dp[i] + s[j].w )
					{
						dp[num] = dp[i] + s[j].w;
						if(flag[num] == 0)
						{
							q.push(num);
							flag[num] = 1;
						}
					}
				}
			}
			if(dp[0] != -1)
				ans = min(ans,dp[0]);
		}
		printf("%d\n",ans);
	}
	return 0;
}



