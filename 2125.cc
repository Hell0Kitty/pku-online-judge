#include<iostream>
#include<cstdio>
#include<algorithm> 

using namespace std;

#define mm(a) memset((a),0,sizeof((a)))
#define INF 0xFFFFFF
#define MAXN 255

int n,m,c[MAXN][MAXN],dis[MAXN],gap[MAXN];
int st,ed;
bool visited[MAXN];
int stack[MAXN],top;

int sap(int u,int flow)
{
	if(u==ed) return flow;
	int ans=0,i,t;
	for(i=0;i<=n+1;++i)
		if(c[u][i]&&dis[u]==dis[i]+1)
		{
			t=sap(i,min(flow-ans,c[u][i]));
			c[u][i]-=t,c[i][u]+=t,ans+=t;
			if(ans==flow) return ans;
		}
	if(dis[st]>=n+2) return ans;
	if(!--gap[dis[u]]) dis[st]=n+2;
	++gap[++dis[u]];
	return ans;
}

void dfs(int p)
{
	if(visited[p]) return ;
	visited[p]=true;
	for(int i=0;i<n+1;i++)
		if(!visited[i] && c[p][i]) dfs(i);
}

void solve()
{
	int x,y,ans=0,temp;
	mm(dis),mm(gap),mm(c),mm(visited);
	for(int i=1;i<=n;i++) scanf("%d",&c[n+i][n*2+1]);
	for(int i=1;i<=n;i++) scanf("%d",&c[0][i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		c[x][y+n]=INF;
	}
	n=n<<1;
	st=0,ed=n+1;
	for(gap[0]=n+2;dis[st]<n+2;) ans+=sap(st,INF);
	dfs(0);
	cout<<ans<<endl;
	top=0;
	n=n>>1;
	for(int i=1;i<=n;i++)
	{
		if(!visited[i]) stack[top++]=i;
		if(visited[i+n]) stack[top++]=i+n;
	}
	cout<<top<<endl;
	while(top>0)
	{
		temp=stack[--top];
		if(temp<=n) cout<<temp<<" -"<<endl;
		else cout<<temp-n<<" +"<<endl;
	}	
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)	solve();
	return 0;
}




