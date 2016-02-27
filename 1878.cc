#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
	int x,y;

	node(){}
	node(int _x,int _y)
	{
		x=_x;
		y=_y;
	}
};

const int INF=1000000000;
int n,m,g[405][405],h[25][25],pre[405];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int judge(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y2>y1) return 0;
	if(x1==x2&&y2<y1) return 1;
	if(y1==y2&&x2>x1) return 2;
	return 3;
}

int get(int x,int y)
{
	return (x-1)*m+y;
}

int OK(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}

void deal(int x1,int y1,int x2,int y2)
{
	if(x1==x2&&y1==y2)
	{
		printf("To get from %d-%d to %d-%d, stay put!\n",x1,y1,x2,y2);
		return;
	}
	queue<node> Q;
	int i,visit[25][25];
	node p,q;

	memset(visit,0,sizeof(visit));
	memset(pre,-1,sizeof(pre));
	Q.push(node(x1,y1));
	visit[x1][y1]=1;
	pre[get(x1,y1)]=-1;
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();

		if(p.x==x2&&p.y==y2) break;
		for(i=0;i<4;i++)
		{
			q.x=p.x+dx[i];
			q.y=p.y+dy[i];
			if(OK(q.x,q.y)&&!visit[q.x][q.y]&&h[q.x][q.y]-h[p.x][p.y]<=10&&g[get(p.x,p.y)][get(q.x,q.y)])
			{
				Q.push(q);
				visit[q.x][q.y]=1;
				pre[get(q.x,q.y)]=get(p.x,p.y);
			}
		}
	}
	if(pre[get(x2,y2)]==-1) 
	{
		printf("There is no acceptable route from %d-%d to %d-%d.\n",x1,y1,x2,y2);
		return;
	}
	stack<node> s;
	int t=get(x2,y2);
	t=pre[t];
	while(pre[t]!=-1)
	{
		s.push(node((t+m-1)/m,(t-1)%m+1));
		t=pre[t];
	}
	s.push(node(x1,y1));
	while(!s.empty()) 
	{
		printf("%d-%d to ",s.top().x,s.top().y);
		s.pop();
	}
	printf("%d-%d\n",x2,y2);
}

int main()
{
	while(scanf("%d%d",&n,&m)!=-1)
	{
		int i,j;
		for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&h[i][j]);
		int x1,y1,x2,y2;
		memset(g,0,sizeof(g));
		while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2),x1||y1||x2||y2)
		{
			i=judge(x1,y1,x2,y2);
			while(x1!=x2||y1!=y2)
			{
				g[get(x1,y1)][get(x1+dx[i],y1+dy[i])]=1;
				x1+=dx[i];
				y1+=dy[i];
			}
		}
		while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2),x1||y1||x2||y2)
		{
			deal(x1,y1,x2,y2);
			puts("");
		}
	}
	return 0;
}



