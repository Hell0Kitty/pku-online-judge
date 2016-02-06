#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define NUM_INF 0x7FFFFFFF

int dir[6][2] = {{1,1},{1,0},{-1,-1},{-1,0},{0,-1},{0,1}};
struct Pos{
	int i,j;
	Pos(int ii,int jj)
	{
		i=ii;
		j=jj;
	}
};
int map[15][15];
bool mark[15][15];
int ans;
int n;

void dfs(Pos sur,int pre)
{
	int i;
	Pos temp(0,0);
	for(i=0;i<6;i++)
	{
		temp = sur;
		temp.i += dir[i][0];
		temp.j += dir[i][1];

		if(temp.i<0||temp.j<0||temp.i>=n||temp.j>temp.i)
			continue;

		if(mark[temp.i][temp.j] == true)
			continue;
		if(map[temp.i][temp.j] != pre && pre!=0)
			continue;
		if(map[temp.i][temp.j]==0)
			continue;

		if(pre==0||map[temp.i][temp.j]==pre)
		{
			mark[temp.i][temp.j] = true;
			dfs(temp,map[temp.i][temp.j]);
		}
	}
}

int main()
{
	int num;
	int i,j;
	int ii,jj;
	int ans_temp;
	while(scanf("%d%d",&n,&num)!=EOF&&(n||num))
	{
		ans = -9999999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(map[i][j]==0)
				{
					map[i][j] = num;
					memset(mark,false,sizeof(mark));
					for(ii=0;ii<n;ii++)
					{
						for(jj=0;jj<=ii;jj++)
						{
							if(map[ii][jj]==0)
							{
								dfs(Pos(ii,jj),0);
							}
						}
					}

					ans_temp = 0;
					for(ii=0;ii<n;ii++)
					{
						for(jj=0;jj<=ii;jj++)
						{
							if(map[ii][jj] == 0|| mark[ii][jj]==true )
								continue;
							if(map[ii][jj] == num)
								ans_temp--;
							else
								ans_temp++;
						}
					}
					map[i][j] = 0;
					if(ans_temp>ans)
						ans = ans_temp;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}


