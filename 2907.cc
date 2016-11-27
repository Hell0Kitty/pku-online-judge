#include<iostream>
using namespace std;
const int Max = 15; 
struct{
    int r, c;
}node[Max];
int row, col, n, ans;
bool vis[Max];
int dis(int u, int v){    
    int r = node[u].r - node[v].r;
    if(r < 0) r = -r;
    int c = node[u].c - node[v].c;
    if(c < 0) c = -c;
    return r + c;
}

void dfs(int dep, int u, int len){   
    if(len >= ans) return;
    if(dep == n){
        if(len + dis(u, 0) < ans)
            ans = len + dis(u, 0);
        return;
    }
    for(int i = 1; i <= n; i ++)
        if(!vis[i]){
            vis[i] = true;
            dfs(dep + 1, i, len + dis(u, i));
            vis[i] = false;
        }
}

int main(){
    int t;
    cin >> t;
    while(t --){
        cin >> row >> col;
        cin >> node[0].r >> node[0].c;
        cin >> n;
        for(int i = 1; i <= n; i ++)
        cin >> node[i].r >> node[i].c;
        ans = 9999999;
        memset(vis, false, sizeof(vis));
        dfs(0, 0, 0);
        cout << "The shortest path has length " << ans << endl;
    }
    return 0;
}


