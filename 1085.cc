#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define LINE 18
#define TRI 9
#define INF (1<<25)
int edge[][2]={{1,2},{1,3},{2,3},{2,4},{2,5},{3,5},{3,6},{4,5},{5,6},{4,7},{4,8},{5,8},{5,9},{6,9},{6,10},{7,8},{8,9},{9,10}};
int tri[][3]=
{
	{0,1,2},
	{3,4,7},{2,4,5},{5,6,8},
	{9,10,15},{7,10,11},{11,12,16},{8,12,13},{13,14,17}
}; // 组成9个三角形的line编号，编号从0开始
int pw2[20],dp[(1<<18)+1000]; // 在这个状态下先手最多能得到多少个三角形
int cal(int state,int e)
{
	int ret=0;
	for(int i=0;i<TRI;++i)
	{
		bool flag=false;
		for(int j=0;j<3;++j)
			if(e==tri[i][j])
				flag=true;
		if(flag)
		{
			for(int j=0;j<3;++j)
				if(!(pw2[tri[i][j]]&state || e==tri[i][j]))
				{
					ret--;break;
				}
			ret++;
		}
	}
	return ret;
}

int dfs(int state)
{
	if(dp[state]!=-INF) 
		return dp[state];
	int ret=-INF;
	for(int i=0;i<LINE;++i)
		if(!(state&pw2[i]))
		{
			int tt=cal(state,i);
			if(tt)
				tt+=dfs(state|pw2[i]);
			else tt-=dfs(state|pw2[i]);
			ret=max(ret,tt);
		}
	return dp[state]=ret;
}
int main ()
{
	pw2[0]=1;
	for(int i=1;i<=19;++i)
		pw2[i]=pw2[i-1]*2;
	for(int i=0;i<=(1<<18);++i)
		dp[i]=-INF;
	dp[(1<<18)-1]=0; // wa在这里了，好惨！！，所有边都填满的时候先手的那个人无法得到任何三角形，base case初始化
	int test;scanf("%d",&test);
	for(int k=1;k<=test;++k)
	{
		int m,u,v;scanf("%d",&m);
		int side=0,m0=0,m1=0,state=0,tt;
		while(m--)
		{
			scanf("%d%d",&u,&v); // u<v
			for(int i=0;i<LINE;++i)
				if(edge[i][0]==u && edge[i][1]==v)
				{
					tt=cal(state,i);
					state=state|pw2[i];
					side==0?m0+=tt:m1+=tt;
					side++;
					if(tt)
						side++;
					side%=2;
					break;
				}
		}
		int ans=m0-m1;
		if(side==0)
			ans+=dfs(state);
		else ans-=dfs(state);
		if(ans>0)
			printf("Game %d: A wins. \n",k);
		else printf("Game %d: B wins. \n",k);
	}

	return 0;
}


