#include<stack>
#include<cmath>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2200;
stack <int> s;
vector <int> g[maxn];
int n,a,b,sx1,sy1,sx2,sy2;
int dist,dis1[maxn],dis2[maxn];
int xa[maxn],ya[maxn],xb[maxn],yb[maxn];
int ins[maxn],dfn[maxn],low[maxn],bel[maxn];
int calc(int x0,int y0,int xx,int yy){
	return abs(x0-xx)+abs(y0-yy);
}
void build(int lim){
	for(int i=n<<1|1;i>1;i--) g[i].clear(),dfn[i]=0;
	for(int i=1;i<=a;i++){
		g[xa[i]<<1].push_back(ya[i]<<1|1);
		g[ya[i]<<1].push_back(xa[i]<<1|1);
		g[xa[i]<<1|1].push_back(ya[i]<<1);
		g[ya[i]<<1|1].push_back(xa[i]<<1);
	}
	for(int i=1;i<=b;i++){
		g[xb[i]<<1].push_back(yb[i]<<1);
		g[yb[i]<<1].push_back(xb[i]<<1);
		g[xb[i]<<1|1].push_back(yb[i]<<1|1);
		g[yb[i]<<1|1].push_back(xb[i]<<1|1);
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			if(dis1[i]+dis1[j]>lim){
				g[i<<1].push_back(j<<1|1);
				g[j<<1].push_back(i<<1|1);
			}
			if(dis2[i]+dis2[j]>lim){
				g[i<<1|1].push_back(j<<1);
				g[j<<1|1].push_back(i<<1);
			}
			if(dis1[i]+dis2[j]+dist>lim){
				g[i<<1].push_back(j<<1);
				g[j<<1|1].push_back(i<<1|1);
			}
			if(dis2[i]+dis1[j]+dist>lim){
				g[j<<1].push_back(i<<1);
				g[i<<1|1].push_back(j<<1|1);
			}
		}
}
int cnt,sum;
void tarjan(int x){
	int i;
	dfn[x]=low[x]=++cnt,ins[x]=1,s.push(x);
	for(i=g[x].size()-1;~i;i--)
		if(!dfn[g[x][i]])
			tarjan(g[x][i]),low[x]=min(low[x],low[g[x][i]]);
		else if(ins[g[x][i]])
			low[x]=min(low[x],low[g[x][i]]);
	if(dfn[x]!=low[x]) return;
	sum++;
	do{
		i=s.top(),s.pop();
		ins[i]=0,bel[i]=sum;
	}while(i!=x);
}
bool jud(){
	cnt=sum=0;
	for(int i=n<<1|1;i>1;i--) 
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
		if(bel[i<<1]==bel[i<<1|1])
			return 0;
	return 1;
}
int main(){
	scanf("%d%d%d%d%d%d%d",&n,&a,&b,&sx1,&sy1,&sx2,&sy2);
	dist=calc(sx1,sy1,sx2,sy2);
	for(int x,y,i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		dis1[i]=calc(sx1,sy1,x,y);
		dis2[i]=calc(sx2,sy2,x,y);
	}
	for(int i=1;i<=a;i++) 
		scanf("%d%d",&xa[i],&ya[i]);
	for(int i=1;i<=b;i++) 
		scanf("%d%d",&xb[i],&yb[i]);
	int l=1,r=4000000,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		build(mid);
		if(jud()) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}



