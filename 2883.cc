#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
#define INF 10000001
#define esp 1
int n,m;
int head[2][30015],v[2][30015],next[2][30015];
double w[2][30015];
double dis[1005];
int input[1505],output[1505];
int cnt[2];
void add(int k,int a,int b,double c)
{
	v[k][cnt[k]]=b;
	w[k][cnt[k]]=c;
	next[k][cnt[k]]=head[k][a];
	head[k][a]=cnt[k]++;
}
bool spfa(int k)
{
	for(int i=1;i<=n;i++)
		dis[i]=-INF;
	memset(input,0,sizeof(input));
	memset(output,0,sizeof(output));
	queue<int> q;
	q.push(0);
	dis[0]=0;
	input[0]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		input[u]=0;
		output[u]++;
		if(output[u]>n)
			return 0;
		for(int i=head[k][u];i!=-1;i=next[k][i])
			if(dis[v[k][i]]<dis[u]+w[k][i])
			{
				dis[v[k][i]]=dis[u]+w[k][i];
				if(!input[v[k][i]])
				{
					q.push(v[k][i]);
					input[v[k][i]]=1;
				}
			}
	}
	return 1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(head,-1,sizeof(head));
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			add(0,0,i,0);
			add(1,0,i,0);
		}
		for(int i=0;i<m;i++)
		{
			int x,z;
			char y[10];
			scanf("%d%s%d",&x,&y,&z);
			if(y[0]=='N'&&y[1]=='E')
			{
				add(0,x,z,esp);//zy
				add(1,x,z,esp);//sx
				continue;
			}
			if(y[0]=='N'&&y[1]=='W')
			{
				add(0,z,x,esp);
				add(1,x,z,esp);
				continue;
			}
			if(y[0]=='N'&&y[1]=='\0')
			{
				add(0,x,z,0);
				add(0,z,x,0);
				add(1,x,z,esp);
				continue;
			}
			if(y[0]=='S'&&y[1]=='E')
			{
				add(0,x,z,esp);
				add(1,z,x,esp);
				continue;
			}
			if(y[0]=='S'&&y[1]=='W')
			{
				add(0,z,x,esp);
				add(1,z,x,esp);
				continue;
			}
			if(y[0]=='S'&&y[1]=='\0')
			{
				add(0,x,z,0);
				add(0,z,x,0);
				add(1,z,x,esp);
				continue;
			}
			if(y[0]=='E')
			{
				add(0,x,z,esp);
				add(1,x,z,0);
				add(1,z,x,0);	
				continue;
			}
			if(y[0]=='W')
			{
				add(0,z,x,esp);
				add(1,x,z,0);
				add(1,z,x,0);	
				continue;
			}
		}
		if(spfa(0)&&spfa(1))
			cout<<"POSSIBLE"<<endl;
		else
			cout<<"IMPOSSIBLE"<<endl;

	}
	return 0;
}



