#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 55
#define inf 0x3f3f3f3f
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
struct Lux
{
	int x,y;
	Lux(int a,int b):x(a),y(b){}
	Lux(){}
};
char mp[N][N];
int map[N][N];/*0可行，1森林，2枚举线段，3起点*/
int n,m,ans=inf;
int dist[N][N],tx,ty;

int in[N][N],cnt;
queue<Lux>q;
int bfs(int sx,int sy)
{
	int i,fr,ret;
	int vx,vy;

	for(ret=fr=0;fr<2;fr++)
	{
		memset(dist,0x3f,sizeof(dist));
		while(!q.empty())q.pop();
		for(i=fr*5;i<fr*5+3;i++)
		{
			vx=sx+dx[i];
			vy=sy+dy[i];
			if(in[vx][vy]&&!map[vx][vy])dist[vx][vy]=1,q.push(Lux(vx,vy));
		}
		while(!q.empty())
		{
			Lux U=q.front();q.pop();
			for(i=0;i<8;i++)
			{
				vx=U.x+dx[i];
				vy=U.y+dy[i];
				if(in[vx][vy]&&!map[vx][vy]&&dist[vx][vy]>dist[U.x][U.y]+1)
				{
					dist[vx][vy]=dist[U.x][U.y]+1;
					q.push(Lux(vx,vy));
				}
			}
		}
		ret+=dist[tx][ty];
	}
	return ret;
}
int main()
{
//	freopen("test.in","r",stdin);
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%s",mp[i]+1);
	for(j=1;j<=m;j++)for(i=1;i<=n;i++)
	{
		in[i][j]=++cnt;
		if(mp[i][j]=='X')
		{
			map[i][j]=1;
			x=i;y=j;
		}
		else if(mp[i][j]=='*')tx=i,ty=j;
	}
	if(tx==x&&ty>y)
	{
		for(i=y;mp[x][i]=='X';i--);
		y=i;
		for(i=y;i;i--)map[x][i]=3;
		for(i=y;i;i--)ans=max(ans,bfs(x,i));
	}
	else
	{
		for(i=y+1;i<=m;i++)map[x][i]=3;
		for(i=y+1;i<=m;i++)ans=min(ans,bfs(x,i));
	}
	printf("%d\n",ans);
	return 0;
}



