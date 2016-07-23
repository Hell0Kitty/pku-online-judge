#include<iostream> 
#include<string> 
#include<queue> 
#include<algorithm> 
#include<cstdio> 
#include<vector> 
#include<queue> 
#include<climits> 
#include<cstring> 
#include<ctime>
#include<cmath>
#include<cstdlib>
using namespace std; 
const double pi=acos(-1.0);
const int maxn=25;
bool vis[maxn][maxn];
double initAng;
double ans;
int x[maxn],y[maxn];

struct node
{
	double angle,dist;
	int num,pre;
	node(int n,int p,double a,double d)
		:num(n),pre(p),angle(a),dist(d){}
	node(){}
	bool operator<(const node& b)const
	{
		return dist>b.dist;
	}
};

struct nxtPnt
{
	int nxt;
	double dist,angle;
	nxtPnt(int n,double a,double d)
		:nxt(n),angle(a),dist(d){}
	nxtPnt(){}
};

priority_queue< node >que;
vector< nxtPnt > vec[maxn];

void searchAns(int n)
{
	memset(vis,0,sizeof(vis));
	while(!que.empty()) que.pop();
	que.push(node(0,0,initAng,0.0));
	while(!que.empty())
	{
		node top=que.top();
		que.pop();
	//	cout<<"debug:"<<top.num<<' '<<top.dist<<' '<<top.pre<<' '<<vis[top.num][top.pre]<<endl;
		int cur=top.num;
		int pre=top.pre;
		if(vis[cur][pre]) continue;
		vis[cur][pre]=true;
		if(cur==n) 
		{
			ans=top.dist;
			//cout<<"haha:"<<ans<<endl;
			break;
		}

		int size=vec[cur].size();
		for(int i=0;i<size;i++)
		{
			int nxt=vec[cur][i].nxt;
			if(!vis[nxt][cur])
			{
				double angleToTurn=vec[cur][i].angle-top.angle;
				if(angleToTurn<0.0) angleToTurn=-1.0*angleToTurn;
				else if(angleToTurn>=360.0) angleToTurn-=360.0;
				if(angleToTurn>=180.0) angleToTurn=360.0-angleToTurn;
				double distTo=vec[cur][i].dist+angleToTurn+top.dist;
				que.push(node(nxt,cur,vec[cur][i].angle,distTo));
			}
		}
	}

}

int main()
{
	int r,n;
	while(scanf("%d%d",&r,&n)!=EOF)
	{
		ans=INT_MAX+0.0;
		if(-1==r&&-1==n) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		initAng=atan2((double)(y[n-1]-y[0]),(double)(x[n-1]-x[0]))/pi*180.0;
		for(int i=0;i<n;i++)  vec[i].clear();
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				double distBet=sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
				if(distBet<=r)
				{
					double angleBet1=atan2((double)(y[j]-y[i]),(double)(x[j]-x[i]));
					double angleBet2=atan2((double)(y[i]-y[j]),(double)(x[i]-x[j]));
					vec[i].push_back(nxtPnt(j,angleBet1/pi*180.0,distBet));	
					vec[j].push_back(nxtPnt(i,angleBet2/pi*180.0,distBet));
				}
			}
		}
		searchAns(n-1);
		if(ans==INT_MAX+0.0) printf("impossible\n");
		else
		{
			int fl=(int)floor(ans);
			if(ans-(double)fl>0.50) printf("%d\n",fl+1);
			else printf("%d\n",fl);
		}

	}
}


