#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define maxn 50050
using namespace std;
__int64 tot,head[maxn];
struct node{
	__int64 v,next,w;
}edge[maxn*2];
void add(__int64 u,__int64 v,__int64 w){
	edge[tot].v=v;
	edge[tot].w=w;
	edge[tot].next=head[u];
	head[u]=tot++;
}
__int64 n,m,num[maxn];
__int64 sum[maxn];
void dfs(__int64 s){
	sum[s]=num[s];
	for(__int64 i=head[s];i!=-1;i=edge[i].next){
		__int64 v=edge[i].v;
		dfs(v);
		sum[v]+=sum[s];
	}
}
queue<__int64>q;
__int64 dis[maxn],mark[maxn];
void spfa(__int64 s){
	memset(mark,0,sizeof(mark));
	memset(dis,-1,sizeof(dis));
	dis[s]=0;
	mark[s]=1;
	q.push(s);
	while(!q.empty()){
		__int64 tmp=q.front();
		q.pop();
		mark[tmp]=0;
		for(__int64 i=head[tmp];i!=-1;i=edge[i].next){
			__int64 y=edge[i].v;
			if(dis[y]==-1||dis[y]>dis[tmp]+edge[i].w){
				dis[y]=dis[tmp]+edge[i].w;
				if(!mark[y]){
					q.push(y);
					mark[y]=1;
				}
			}
		}
	}
}
int main(){
	__int64 T,a,b,c;
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&m);
		for(__int64 i=1;i<=n;i++){
			scanf("%I64d",&num[i]);
		}
		tot=0;
		memset(head,-1,sizeof(head));
		for(__int64 i=1;i<=m;i++){
			scanf("%I64d%I64d%I64d",&a,&b,&c);
			add(a,b,c);add(b,a,c);
		}
		if(n==0||n==1){
			printf("0\n");
			continue;
		}
		spfa(1);
		__int64 ans=0;
		int flag=0;
		for(__int64 i=1;i<=n;i++){
			ans+=dis[i]*num[i];
			if(dis[i]==-1) flag=1;
		}
		if(flag)printf("No Answer\n");
		else printf("%I64d\n",ans);
	}
}



