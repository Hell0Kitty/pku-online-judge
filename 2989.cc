#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(v) ((int)(v).size())

const int maxn = 128;
int g[maxn+5][maxn+5],vis[maxn+5][maxn+5],com[maxn+5][maxn+5];
int n,m,ans;

void clique(int com_cnt,int vis_cnt,int dep){
    if(!com_cnt){
        if(!vis_cnt)    ans++;
        return;
    }
    for(int i=1;i<=vis_cnt;i++){
        bool found=false;
        int t=vis[dep][i];
        for(int j=1;j<=com_cnt;j++){
            if(!g[t][com[dep][j]]){
                found=true;
                break;
            }
        }
        if(!found)  return;
    }
    for(int i=1;i<=com_cnt;i++){
        int v=com[dep][i];
        int t,t_com_cnt=0,t_vis_cnt=0;
        for(int j=i+1;j<=com_cnt;j++){
            t=com[dep][j];
            if(g[v][t]) com[dep+1][++t_com_cnt]=t;
        }
        for(int j=1;j<=vis_cnt;j++){
            t=vis[dep][j];
            if(g[v][t]) vis[dep+1][++t_vis_cnt]=t;
        }
        if(ans>1000)    return;
        clique(t_com_cnt,t_vis_cnt,dep+1);
        vis[dep][++vis_cnt]=v;
    }
}

int main() {
    while(scanf("%d%d",&n,&m)==2){
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u][v]=g[v][u]=1;
        }
        ans=0;
        for(int i=1;i<=n;i++)   com[1][i]=i;
        clique(n,0,1);
        if(ans>1000){
            printf("Too many maximal sets of friends.\n");
        }
        else{
            printf("%d\n",ans);
        }
    }
    return 0;
}




