#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>  
#include <map>
#include <queue>
#include <cmath>
#define INF 1e8 
#define eps 1e-6
#define MAXN 605
using namespace std;
struct Node
{
	int x,y; 
};
struct cmp
{
	bool operator()(const Node &a,const Node &b) const
	{
		if(a.x!=b.x)
			return a.x<b.x;
		else
			return a.y<b.y;
	}
};
Node s,e,node[MAXN];
int Map[MAXN][MAXN];
double E[MAXN][MAXN];//最后构建的图
int G[1005][1005];
int deg[MAXN],ans[MAXN];
int pre[MAXN];
double dis[MAXN];
bool vis[MAXN],mark[MAXN];
map<Node,int,cmp>hash;
int cnt;//表示总的点数
int scr,sink,N;
void ini()
{
	hash.clear();
	memset(Map,0,sizeof(Map));
	memset(G,0,sizeof(G));
	memset(deg,0,sizeof(deg));
	memset(mark,true,sizeof(mark));
	cnt=0;
}
int gcd(int n,int m)//求最大公约数
{
	if(m==0) return n;
	return gcd(m,n%m);
}
int xmulti(Node p1,Node p2,Node p0)//叉积
{
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int dmulti(Node p1,Node p2)//点积
{
	return p1.x*p2.x+p1.y*p2.y;
}
double get_dis(int a,int b)
{
	return sqrt((double)((node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y)));
}
int ponls(Node a,Node b,Node p)
{
	return ((xmulti(b,p,a)==0)&&(((p.x-a.x)*(p.x-b.x)<0)||((p.y-a.y)*(p.y-b.y)<0)));
}

void f(Node now)
{
	int i,j;
	bool ok=false;
	hash[now]=++cnt;
	//now.id=cnt;
	node[cnt]=now;
	for(i=1;i<=cnt&&!ok;i++)
	{
		for(j=i+1;j<=cnt;j++)
		{
			if(Map[i][j]&&ponls(node[i],node[j],now))
			{
				Map[i][j]=Map[j][i]=0;
				Map[i][cnt]=Map[cnt][i]=1;
				Map[j][cnt]=Map[cnt][j]=1;
				deg[cnt]=3;
				ok=true;
				break; 
			}
		}
	}
	if(!ok)
	{
		deg[cnt]=1;
	}	
}
void Run()
{
	int i,dx,dy,nx,ny,w;
	Node a,b,c;
	scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
	if(!hash[a])
	{
		f(a);
	}
	else
		deg[hash[a]]++;
	if(!hash[b])
	{
       	f(b);		
	}
	else
		deg[hash[b]]++;
	dx=abs(a.x-b.x);
	dy=abs(a.y-b.y);
	w=gcd(dx,dy);
	dx=(b.x-a.x)/w;
	dy=(b.y-a.y)/w;
	int pre=hash[a];
	int after=hash[b];
	for(i=1;i<w;i++)
	{
		nx=a.x+dx*i;
		ny=a.y+dy*i;
		if(G[nx][ny])
		{
			c.x=nx;
			c.y=ny;
			int id=hash[c];
			deg[id]+=2;
			Map[pre][id]=Map[id][pre]=1;
			pre=id;
		}
	}
	Map[pre][after]=Map[after][pre]=1;
	G[a.x][a.y]=G[b.x][b.y]=1;
}
int go(int ith,int id,int k)
{
	Node p1,p2;
	p1.x=node[ith].x-node[id].x;
	p1.y=node[ith].y-node[id].y;
	p2.x=node[k].x-node[id].x;
	p2.y=node[k].y-node[id].y;
	int res=dmulti(p1,p2);
	if(res>0) return 1;
	if(res==0) return 0;
	return -1;
}
int dfs(int pre,int now)
{
	int i;
	if(mark[now]) return now;
	for(i=1;i<=cnt;i++)
	{
		if(i==pre) continue;
		if(Map[now][i]==1 && deg[i]>1)
			return dfs(now,i);
	}
}
void fuck(int ith)
{
	int i,id,a,b;
	for(i=1;i<=cnt;i++)
	{
		if(Map[ith][i]==1&&i!=ith)
		{id=i;break;}
	}
	mark[ith]=mark[id]=false;
	int k=0;
	for(i=1;i<=cnt;i++)
	{
		if(Map[id][i]==1&&i!=id && deg[i]>1)
		{
			if(k==0) 
			{a=dfs(id,i);k++;}
			else
			{b=dfs(id,i);k++;break;} 
			//go(ith,id,i);
		}
	}
	int res=go(ith,id,b);
	if(res==0) 
		Map[a][b]=Map[b][a]=-1;
	else if(res<0)
	{
		Map[b][a]=-1;
		if(Map[a][b]!=-1)
			Map[a][b]=1;
	}
	else
	{
		Map[a][b]=-1;
		if(Map[b][a]!=-1)
			Map[b][a]=1; 
	} 
}
void Build()
{
	int i,j;
	for(i=1;i<=cnt;i++)
	{
		if(deg[i]==1)
		{
			mark[i]=false;
			for(j=1;j<=cnt;j++)
			{
				if(Map[i][j]==1)
				{mark[j]=false;break;}
			}
		}
	}
	for(i=1;i<=cnt;i++)
	{
		if(deg[i]==1)
			fuck(i);
	}
	for(i=1;i<=cnt;i++)
	{
		for(j=1;j<=cnt;j++)
		{
			if(i==j||!mark[i]||!mark[j]||Map[i][j]==-1||Map[i][j]==0) 
				E[i][j]=-1;
			else
				E[i][j]=get_dis(i,j); 
		} 
	}
}
queue<int>Q;
void SPFA(int s,int e)
{
	int i,u,v,w;
	while(!Q.empty()) Q.pop();
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	for(i=1;i<=cnt;i++)
		dis[i]=INF;
	Q.push(s);
	vis[s]=true;
	dis[s]=0;
	while(!Q.empty())
	{
		u=Q.front();Q.pop();
		vis[u]=false;
		for(i=1;i<=cnt;i++)
		{
			if(E[u][i]==-1) continue;
			if(dis[i]>dis[u]+E[u][i])
			{
				dis[i]=dis[u]+E[u][i];
				pre[i]=u;
				if(!vis[i])
				{
					vis[i]=true;
					Q.push(i);
				}
			}
		}
	}
	if(dis[e]==INF)
		printf("-1\n");
	else
	{
		int num=0;
		u=e;
		while(true)
		{
			ans[num++]=u;
			u=pre[u];
			if(u==-1) break;
		}
		for(i=num-1;i>=0;i--)
		{
			printf("%d %d\n",node[ans[i]].x,node[ans[i]].y);
		}
		printf("0\n");
	}
}
void Print()
{
	int i;
	for(i=1;i<=cnt;i++)
		printf("%d %d\n",node[i].x,node[i].y);
	printf("****\n");
}
void Solve()
{
	int i;
	ini();
	scanf("%d%d%d%d",&s.x,&s.y,&e.x,&e.y);
	for(i=1;i<=N;i++)
	{
		Run();
	}
	scr=hash[s];
	sink=hash[e];
	Build();
	SPFA(scr,sink);

}
int main()
{
	while(scanf("%d",&N),N)
	{
		Solve();
	}
return 0;
}



