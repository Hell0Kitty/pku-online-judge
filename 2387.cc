#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
#define inf 0x3f3f3f3f
int g[1005][1005];
int d[1005],v[1005];
int main()
{
	int T,N;
	while(scanf("%d%d",&T,&N)==2)
	{
		memset(g,inf,sizeof(g));
		for(int k=1;k<=T;k++)
		{
			int i,j,f;
			scanf("%d%d%d",&i,&j,&f);
			if(f<g[i][j])
			g[i][j]=g[j][i]=f;
		}
		memset(v,0,sizeof(v));
		memset(d,0,sizeof(d));
		for(int i=1;i<=N;i++)d[i]=(i==N?0:inf);
		for(int i=1;i<=N;i++){
			int x=N,m=inf;
			for(int y=1;y<=N;y++)if(!v[y]&&d[y]<=m)m=d[x=y];
			v[x]=1;
			for(int y=1;y<=N;y++)d[y]=min(d[y],d[x]+g[x][y]);
		}
		printf("%d\n",d[1]);
	}
	return 0;
}



