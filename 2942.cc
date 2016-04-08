#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <set>
#include <cmath>
#include <map>

using namespace std;
#define N (1000 + 10)
#define M (2000000 + 10)
struct EDGE{
    int to,next;
} e[100005];

int min(int x,int y){
    return x < y ? x : y;
}

int head[N],stack[N],DFN[N],Low[N],Belong[N];
int cnt,scnt,top,n,tot,cc,color[N],tmp[N];
int mapp[N][N];
bool can[N],instack[N];

bool dfs(int u,int col){
    int v;
    color[u] = col;
    for(int i = head[u]; ~i; i = e[i].next){
        v = e[i].to;
        if(Belong[v] != Belong[u]) continue;
        if(color[v] != -1){
            if(color[v] == col) return false;
            continue;
        }
        if(!dfs(v,1-col)) return false;
    }
    return true;
}

void add(int u,int v){
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot++;
}
void tarjan(int u,int fa){
    int v,t;
    DFN[u]=Low[u]=++cnt;
    stack[top++]=u;
    instack[u]=1;
    for(int i=head[u]; i!=-1; i=e[i].next){
        v=e[i].to;
        if(v == fa) continue;
        if(!DFN[v]){
            tarjan(v,u);
            Low[u]=min(Low[v],Low[u]);
            if(Low[v] >= DFN[u] && (Belong[u] = ++scnt)){
                do
                {
                    t = stack[--top];
                    tmp[cc++] = t;
                    Belong[t] = scnt;
                    instack[t]= 0;
                }while(v != t );

                for(int j = 0; j < cc; j++) color[tmp[j]] = -1;
                if(!dfs(u,0)){
                    can[u] = true;
                    while(cc--) can[tmp[cc]] = true;
                }
                cc = 0;
            }
        }
        else if(instack[v]) Low[u]=min(DFN[v],Low[u]);
    }
}
void solve()
{
    top=scnt=cnt=cc=0;
    memset(DFN,0,sizeof DFN);
    memset(instack,false,sizeof instack);
    memset(color, -1, sizeof color);
    memset(can, false, sizeof can);
    memset(Belong, 0, sizeof Belong);
    for(int i=1; i<=n; i++){
        if(!DFN[i]) tarjan(i,0);
    }
    int ans = n;
    for(int i=1; i<=n; i++) if(can[i]) ans--;
    printf("%d\n",ans);
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m) && (n+m)){
        memset(head,-1,sizeof(head));
        memset(mapp,0,sizeof mapp);
        tot = 0;
        for(int i=0; i<m; i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mapp[a][b]=mapp[b][a]=1;
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++){
                if(i == j) continue;
                if(!mapp[i][j]) add(i,j);
            }
        solve();
    }
    return 0;
}



