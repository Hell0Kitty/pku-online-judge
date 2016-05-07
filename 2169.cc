#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100 + 10;
const int maxp = 10000 + 10;

int G[maxn][maxn], n, m, a1, b1, a2, b2;        
int d[maxn][maxn];      
int step[maxn][maxn];      
bool vis[maxn][maxn];     

struct Pair{
    int A, B;
    bool operator < (const Pair& e) const{
        return step[A][B] > step[e.A][e.B];
    }
}fa[maxn][maxn];        

void init(){
    memset(vis, 0, sizeof(vis));
    d[a1][b1] = 1;
    step[a1][b1] = 0;
}

void bfs(){
    init();
    priority_queue<Pair> qu;
    qu.push((Pair){a1, b1});
    vis[a1][b1] = 1;
    while(!qu.empty()){
        Pair p = qu.top(); qu.pop();
        for(int i = 1; i <= n; i++) if(G[p.A][i]){
            for(int j = 1; j <= n; j++) if(G[p.B][j] && G[i][j] && i != j){
                if(i == p.B && j == p.A) continue;
                int temp;
                if(i != p.A && j != p.B) temp = step[p.A][p.B] + 2;
                else temp = step[p.A][p.B] + 1;
                if(vis[i][j] && temp >= step[i][j]) continue;
                qu.push((Pair){i, j});
                d[i][j] = d[p.A][p.B] + 1;
                step[i][j] = temp;
                fa[i][j] = (Pair){p.A, p.B};
                vis[i][j] = 1;
            }
        }
    }
}

Pair ret[maxp];
int getRet(){
    int i = 0, x = a2, y = b2;
    while(x != a1 || y != b1){
        ret[i++] = (Pair){x, y};
        int tx = fa[x][y].A;
        int ty = fa[x][y].B;
        x = tx;
        y = ty;
    }
    ret[i++] = (Pair){a1, b1};
    return i;
}

int main()
{
    int u, v;
    while(scanf("%d%d%d%d%d%d", &n, &m, &a1, &b1, &a2, &b2) == 6){
        memset(G, 0, sizeof(G));
        for(int i = 1; i <= n; i++) G[i][i] = 1;
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        bfs();
        printf("%d %d\n", step[a2][b2], d[a2][b2]);
        int cnt = getRet();
        for(int i = cnt-1; i >= 0; i--) printf("%d %d\n", ret[i].A, ret[i].B);
    }
    return 0;
}



