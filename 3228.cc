#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 222
#define inf 1<<30

int vs,vt;
int dep[MAXN];
int map[MAXN][MAXN];

int gold[MAXN],store[MAXN];
int dist[MAXN][MAXN];
void Build_Map(int limit,int n)
{
    memset(map,0,sizeof(map));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(dist[i][j]<=limit)map[i][j]=inf;
    for(int i=1;i<=n;i++){
        map[vs][i]=gold[i];
        map[i][vt]=store[i];
    }
}

int BFS(){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(dep,-1,sizeof(dep));
    dep[vs]=0;
    q.push(vs);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=vs;v<=vt;v++)
            if(map[u][v]>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.push(v);
            }
    }
    return dep[vt]!=-1;
}

int DFS(int u,int minx){
    if(u==vt)
        return minx;
    int tmp;
    for(int v=vs;v<=vt;v++)
        if(map[u][v]>0 && dep[v]==dep[u]+1 && (tmp=DFS(v,min(minx,map[u][v])))){
            map[u][v]-=tmp;
            map[v][u]+=tmp;
            return tmp;
        }
    dep[u]=-1;
    return 0;
}

int Dinic(){
    int ans=0,tmp;
    while(BFS()){
        while(1){
            tmp=DFS(vs,inf);
            if(tmp==0)
                break;
            ans+=tmp;
        }
    }
    return ans;
}

int main()
{
    int total,n,m,a,b,c;
    while(~scanf("%d",&n)){
        if(n==0)break;
        total=0,vs=0,vt=n+1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=inf;
        for(int i=1;i<=n;i++){
            scanf("%d",&gold[i]);
            total+=gold[i];
        }
        for(int i=1;i<=n;i++)scanf("%d",&store[i]);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            dist[a][b]=dist[b][a]=c;
        }

        int low=0,high=100010,mid,ans=-1;
        while(low<=high){
            mid=(low+high)>>1;
            Build_Map(mid,n);
            if(Dinic()==total){
                ans=mid;
                high=mid-1;
            }else 
                low=mid+1;
        }
        if(ans==-1){
            printf("No Solution\n");
        }else 
            printf("%d\n",ans);
    }
    return 0;
}



