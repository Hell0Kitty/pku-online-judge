#include <iostream>
using namespace std;
#define MAXM 2710
#define MAXV 505
#define inf 1<<29

struct{
	int x,y,t;
}edge[MAXM];

int n,m,w;

int bellman_ford(){
	int i,j,d[MAXV],flag=1,cnt=1;
	for(i=1;i<=n;i++) d[i]=inf;

	while(flag){
		flag=0;
		if(cnt++>n) return 1;
		for(i=1;i<=m;i++){
			if(d[edge[i].x]+edge[i].t<d[edge[i].y]) {d[edge[i].y]=d[edge[i].x]+edge[i].t;flag=1;}
			if(d[edge[i].y]+edge[i].t<d[edge[i].x]) {d[edge[i].x]=d[edge[i].y]+edge[i].t;flag=1;}
		}
		for(;i<=m+w;i++)
			if(d[edge[i].y]>d[edge[i].x]-edge[i].t) {d[edge[i].y]=d[edge[i].x]-edge[i].t;flag=1;}
	}
	return 0;
}

int main(){
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&w);
		for(i=1;i<=m+w;i++)
			scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].t);
		if(bellman_ford()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}



