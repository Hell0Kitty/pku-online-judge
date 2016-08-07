#include <iostream>
#include <queue>
using namespace std;

#define MAXV 410
#define INF INT_MAX
#define min(a,b) (a>b?b:a)

int res[MAXV][MAXV];		
int	dis[MAXV];				
int source,sink,n,maxflow;	

int bfs(){
	int k;
	queue<int> q;
    memset(dis,-1,sizeof(dis));
    dis[sink]=0;

    q.push(sink);
    while(!q.empty()){
		k=q.front();
		q.pop();
        for(int i=0;i<n;i++){
            if(dis[i]==-1 && res[i][k]){
                dis[i] = dis[k] + 1;
                q.push(i);
            }
        }
        if(k==source) return 1;
    }
	return 0;
}

int dfs(int cur,int cp){
    if(cur==sink)	return cp;

    int tmp=cp,t;
    for(int i=0;i<n && tmp;i++){
        if(dis[i]+1==dis[cur] && res[cur][i]){
            t=dfs(i,min(res[cur][i],tmp));
            res[cur][i]-=t;
            res[i][cur]+=t;
            tmp-=t;
        }
    }
    return cp-tmp;
}

void dinic(){
    maxflow=0;
    while(bfs()) maxflow+=dfs(source,INF);
}

int main(){
	int f,d;
	int i,j,f_sum,d_sum,tmp;
	while(~scanf("%d%d%d",&n,&f,&d)){
		memset(res,0,sizeof(res));
		source=0,sink=2*n+f+d+1;

		for(i=1;i<=f;i++) res[source][i]=1;		
		for(i=1;i<=d;i++) res[2*n+f+i][sink]=1;		
		for(i=1;i<=n;i++) res[f+i][f+n+i]=1;	

		for(i=1;i<=n;i++){
			scanf("%d%d",&f_sum,&d_sum);
			for(j=1;j<=f_sum;j++){
				scanf("%d",&tmp);
				res[tmp][f+i]=1;		
			}
			for(j=1;j<=d_sum;j++){
				scanf("%d",&tmp);
				res[i+f+n][2*n+f+tmp]=1;	
			}
		}
		n=sink+1;				

		dinic();
		printf("%d\n",maxflow);
	}
	return 0;
}



