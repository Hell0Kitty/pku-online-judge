#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
#include<stack>
#include<cstdlib>
#define INF 0x3f3f3f3f
#define NODENUM 505
#define EDGENUM 501*501
using namespace std;

int Edge[NODENUM][NODENUM];
int dist[NODENUM];
int N,M,F;
int f[NODENUM];
int v[NODENUM];

void init()
{
	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) Edge[i][j]=i==j? 0:INF;
	memset(v,0,sizeof(v));
	for(int i=1;i<=N;++i) dist[i]=INF;
}

void read_case()
{
	init();
	for(int i=1;i<=F;++i) {scanf("%d",&f[i]);v[f[i]]=1;} getchar();
		int a,b,len;
		while(1)
		{
		char tmp[100];
		char c=getchar();
		if(c=='\n' || c==-1) break;
		scanf("%[^\n]",tmp+1); getchar();
		tmp[0]=c; 
		sscanf(tmp,"%d %d %d",&a,&b,&len);
		Edge[a][b]=Edge[b][a]=len;
		}
}

void Floyd()
{
	for(int k=1;k<=N;++k)
		for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j) Edge[i][j]=min(Edge[i][j],Edge[i][k]+Edge[k][j]);
}

void solve()
{
	for(int i=1;i<=F;++i)
	for(int j=1;j<=N;++j) dist[j]=min(dist[j],Edge[f[i]][j]);

	int mindist=INF;
	int ans=1;
	for(int k=1;k<=N;++k)
		if(!v[k])
		{
			int maxdist=-INF;
			for(int i=1;i<=N;++i) maxdist=max(maxdist,min(Edge[k][i],dist[i]));
			if(maxdist<mindist) mindist=maxdist,ans=k;
		}
	printf("%d\n",ans);
}

int main()
{

	while(~scanf("%d %d",&F,&N))
	{
		read_case();
		Floyd();
		solve();
	}
	return 0;
}


