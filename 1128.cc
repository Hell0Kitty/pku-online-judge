#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define Abs(a) ((a)>0?(a):(-(a)))
#define llong long long int
using namespace std;
const int N=35;
const int inf=(1<<30);
int n,m,w;
char mat[N][N];
int pos[N][4];//every frame has the left top point and the right buttom point
int total;
bool vis[N];
int indgr[N];
bool line[N][N];
void addedge(int u,int v)
{
	if(!line[v][u])
	{
		line[v][u]=true;
		indgr[u]++;
	}
}
void findcover(int now)
{
	int left=pos[now][1];
	int top=pos[now][0];
	int right=pos[now][3];
	int buttom=pos[now][2];
	for(int i=top;i<=buttom;i++)
	{
		if(mat[i][left]!=now+'A'-1)//this point cannot be '.'this char
		{
			addedge(mat[i][left]-'A'+1,now);
		}
		if(mat[i][right]!=now+'A'-1)//this point cannot be '.'this char
		{
			addedge(mat[i][right]-'A'+1,now);
		}
	}
	for(int j=left+1;j<=right-1;j++)
	{
		if(mat[top][j]!=now+'A'-1)//this point cannot be '.'this char
		{
			addedge(mat[top][j]-'A'+1,now);
		}
		if(mat[buttom][j]!=now+'A'-1)//this point cannot be '.'this char
		{
			addedge(mat[buttom][j]-'A'+1,now);
		}
	}
}
void dfs(int now,int deep,char * s)
{
	s[deep]='A'-1+now;
	if(deep==total)
	{
		printf("%s\n",s+1);
		return;
	}
	vis[now]=true;
	for(int i=1;i<=total;i++)
	{
		if(line[now][i])
		{
			indgr[i]--;
		}
	}
	for(int i=1;i<=total;i++)
	{
		if(!indgr[i]&&!vis[i])
		{
			dfs(i,deep+1,s);
		}
	}	
	for(int i=1;i<=total;i++)
	{
		if(line[now][i])
		{
			indgr[i]++;
		}
	}
	vis[now]=false;
}
void solve()
{
	memset(line,0,sizeof(line));
	memset(indgr,0,sizeof(indgr));
	memset(pos,0,sizeof(pos));
	total=0;
	for(int i=0;i<N;i++)
	{
		pos[i][0]=n+2;
		pos[i][1]=m+2;
		pos[i][2]=0;
		pos[i][3]=0;
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
		  int now =mat[i][j]-'A'+1;
		  total=Max(now,total);
		  if(now!='.')
		  {
			  pos[now][0]=Min(i,pos[now][0]);
			  pos[now][1]=Min(j,pos[now][1]);
			  pos[now][2]=Max(i,pos[now][2]);
			  pos[now][3]=Max(j,pos[now][3]);
		  }

	  }
	for(int i=1;i<=total;i++)
	{
		findcover(i);
	}
	char s[N];
	memset(s,0,sizeof(s));
	for(int i=1;i<=total;i++)
	{
		if(!indgr[i])
		{
			dfs(i,1,s);
		}
	}
}
int main()
{
	while(EOF!=scanf("%d%d",&n,&m))
	{
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",mat[i]+1);
		}
		solve();
	}
	return 0;
}


