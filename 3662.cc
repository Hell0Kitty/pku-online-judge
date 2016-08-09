#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
#define llong long long
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define Abs(a) ((a)>0?(a):-(a))
#define Mod(a,b) (((a)-1+(b))%(b)+1)
using namespace std;
const int N=1005;
const int M=10005;
const int inf=1e10;
int n,m,K,k;
int data[M][3];
struct 
{
	int v,next,w;
}edge[M<<1];
int edgehead[N];
bool vis[N];
int d[N];
void addedge(int u,int v,int w)
{
	edge[k].v=v;
	edge[k].w=w;
	edge[k].next=edgehead[u];
	edgehead[u]=k++;
}
bool OK(int value)
{
	queue<int> que;
	k=1;
	memset(edgehead,0,sizeof(edgehead));
	memset(edge,0,sizeof(edge));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		if(data[i][2]<=value)
		{
			addedge(data[i][0],data[i][1],0);
			addedge(data[i][1],data[i][0],0);
		}
		else
		{
			addedge(data[i][0],data[i][1],1);
			addedge(data[i][1],data[i][0],1);
		}
	}
	for(int i=1;i<=n;i++)
		d[i]=inf;
	que.push(1);
	vis[1]=true;
	d[1]=0;
	while(!que.empty())
	{
		int now=que.front();
		que.pop();
		vis[now]=false;
		for(int i=edgehead[now];i;i=edge[i].next)
		{
			int v=edge[i].v;
			int w=edge[i].w;
			if(d[v]>d[now]+w)
			{
				d[v]=d[now]+w;
				if(!vis[v])
				{
					que.push(v);
				}
			}
		}
	}
	if(d[n]<=K)
		return true;
	else
		return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&K);
	int l,r,rr=0,mid;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",data[i],data[i]+1,data[i]+2);
		rr=max(rr,data[i][2]);
	}
	l=0,r=rr+1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(OK(mid))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l<=rr)
		printf("%d\n",l);
	else
		printf("-1\n");
	return 0;
}


