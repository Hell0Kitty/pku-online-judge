#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define maxn 52
using namespace std;
vector<int> a[maxn];
int n,m,no;
int f[maxn][maxn];
int id[maxn*maxn];
bool vis[maxn];
void DFS(int u){
    vis[u]=1;
    int v;
    for(int i=0;i<a[u].size();i++){
        v=a[u][i];
        if(!vis[v]){
            id[f[u][v]]=++no;
            DFS(v);
        }
        else if(!id[f[u][v]]) id[f[u][v]]=++no;
    }
}
int main(){
    cin>>n>>m;
    no=0;
    memset(vis,0,sizeof(vis));
    memset(id,0,sizeof(id));
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
        f[x][y]=f[y][x]=i;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) DFS(i);
    printf("YES\n");
    for(int i=1;i<m;i++)
        printf("%d ",id[i]);
    printf("%d\n",id[m]);
    return 0;
}



