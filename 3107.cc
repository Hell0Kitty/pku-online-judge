#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int N;
int v[50010*2],next[50010*2],head[50010],E;
int vis[50010];
int num[50010],dp[50010];

void add(int a,int b){		//b为a的子节点 

	v[E]=b;
	next[E]=head[a];
	head[a]=E++;

}

void dfs_num(int n,int from){
	num[n]=1;
	for(int i=head[n];i!=-1;i=next[i]){
		int k=v[i];			//儿子 
		if(k==from)	continue;
		dfs_num(k,n);
		num[n]+=num[k];
	}
}

void dfs_node(int n,int from){
	dp[n]=0;
	for(int i=head[n];i!=-1;i=next[i]){
		int	k=v[i];
		if(k==from)	dp[n]=max(dp[n],N-num[n]);
		else{
			dp[n]=max(dp[n],num[k]);
			dfs_node(k,n);
		}
	}
}

int main()
{
	int i,j,k,T,u,v;
	while(scanf("%d",&N)!=EOF)
	{
		E=0;
		memset(head,-1,sizeof(head));

		for(i=1;i<=N-1;i++)	{
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		dfs_num(1,-1);
		dfs_node(1,-1);
		for(i=k=N;i>=1;i--)	if(k>dp[i])	k=dp[i];
		for(i=1;i<=N;i++)	if(dp[i]==k){
			printf("%d",i);
			break;
		}
		for(i=i+1;i<=N;i++){
			if(dp[i]==k)
			printf(" %d",i);
		}printf("\n");
	}
	return 0;
}


