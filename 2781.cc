#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Edge
{
	int v,next;
};

Edge edges[10000005];
int n,S,E,head[100005],e,dis[100005];

void Add(int u,int v)
{
	edges[e].v=v;
	edges[e].next=head[u];
	head[u]=e++;
}

void InPut()
{
	int i,u,v,num;	
	memset(head,-1,sizeof(head));
	e=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&u,&num);
		while(num--) scanf("%d",&v),Add(u,v);
	}
	scanf("%d%d",&S,&E);
}

void SPFA()
{
	queue<int> Q;
	int i,u,v,visit[100005]={0};

	for(i=0;i<n;i++) dis[i]=500000;
	dis[S]=0;visit[S]=1;
	Q.push(S);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();

		for(i=head[u];i!=-1;i=edges[i].next)
		{
			v=edges[i].v;
			if(visit[v]) continue;
			if(dis[v]>dis[u]+1) dis[v]=dis[u]+1,Q.push(v);
			visit[v]=1;
		}
	}
}

void Deal()
{
	SPFA();
	printf("%d %d %d\n",S,E,dis[E]-1);
}

int main()
{
	while(scanf("%d",&n)!=EOF) InPut(),Deal();
	return 0;
}



