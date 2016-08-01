#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define inf (1<<29)
const int maxn = 110 , maxm = 10010;
int n , m;
struct Edge{
    int v , w , next;
}edge[maxm];
int E , head[maxn];
inline void init() { E = 0;memset(head,-1,sizeof(head)); }
inline void addedge(int u,int v,int w) { edge[E].v=v;edge[E].w=w;edge[E].next=head[u];head[u]=E++; }
int dist[maxn];
bool mark[maxn];
int sta[maxn];
int s , t;
bool spfa() {
    int top = 0;
    memset(mark, false ,sizeof(mark));
    re1(i,n) dist[i] = inf;
    sta[++top] = s;
    mark[s] = true;
    dist[s] = 0;
    while(top) {
        int u = sta[top--];
        mark[u] = false;
        for(int i=head[u];i!=-1;i=edge[i].next) {
            int v = edge[i].v;
            if(dist[v] > dist[u] + edge[i].w) {
                dist[v] = dist[u] + edge[i].w;
                if(!mark[v]) {
                    mark[v] = true;
                    sta[++top] = v;
                }
            }
        }
    }
    return dist[t] != inf;
}

int main() {
    while(~scanf("%d%d%d",&n,&s,&t)) {
        init();
        re1(i,n) {
            scanf("%d",&m);
            re(j,m) {
                int u;
                scanf("%d",&u);
                addedge(i,u,(j)?1:0);
            }
        }
        if(spfa()) printf("%d\n",dist[t]);
        else printf("-1\n");
    }
    return 0;
}



