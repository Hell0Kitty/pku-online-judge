#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn=40100;
struct node
{
    int x;
    int y;
}a[maxn];
struct Edge 
{
    int u;
    int v;
    int l;
    char dir[5];
}e[maxn];
int n,m,p[maxn];
int find(int x)
{
    if(p[x]==-1)
	return x;
    int y=p[x];
    p[x]=find(p[x]);
    a[x].x+=a[y].x;
    a[x].y+=a[y].y;
    return p[x];
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
	memset(p,-1,sizeof(p));
	memset(a,0,sizeof(a));
	for(int i=0;i<m;i++)
	    scanf("%d%d%d%s",&e[i].u,&e[i].v,&e[i].l,&e[i].dir);
	int q,now=0;
	scanf("%d",&q);
	while(q--)
	{
	    int sa,sb,t;
	    scanf("%d%d%d",&sa,&sb,&t);
	    while(now<t)
	    {
		int u=e[now].u;
		int v=e[now].v;
		int x=find(e[now].u);
		int y=find(e[now].v);
		if(x==y)
		    continue;
		int x1=a[v].x;
		int y1=a[v].y;
		if(e[now].dir[0]=='E')
		{
		    a[y].x=a[u].x+e[now].l-a[v].x;
		    a[y].y=a[u].y-a[v].y;
		}
		else if(e[now].dir[0]=='W')
		{
		    a[y].x=a[u].x-e[now].l-a[v].x;
		    a[y].y=a[u].y-a[v].y;
		}
		else if(e[now].dir[0]=='S')
		{
		    a[y].x=a[u].x-a[v].x;
		    a[y].y=a[u].y-e[now].l-a[v].y;
		}
		else
		{
		    a[y].x=a[u].x-a[v].x;
		    a[y].y=a[u].y+e[now].l-a[v].y;
		}
		if(x!=y)
		    p[y]=x;
		now++;
	    }
	    int x=find(sa);
	    int y=find(sb);
	    if(x==y)
		printf("%d\n",abs(a[sa].x-a[sb].x)+abs(a[sa].y-a[sb].y));
	    else
		printf("-1\n");
	}
    }
    return 0;
}



