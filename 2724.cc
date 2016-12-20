#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2000;
const int N = 1000 + 10;

int X,Y;
int g[maxn][maxn];
int vis[maxn];
int linker[maxn];

bool dfs(int u){
    for(int v = 0; v < Y; v++)
        if(g[u][v] && !vis[v]){
            vis[v] = true;
            if(linker[v] == -1 || dfs(linker[v])){
                linker[v] = u;
                return true;
            }
        }
    return false;
}

int hungary(){
    int ans = 0;
    memset(linker, -1, sizeof(linker));
    for(int u = 0; u < X; u++){
        memset(vis, 0, sizeof(vis));
        if(dfs(u)) ans++;
    }
    return ans;
}

int n, m;
struct Str{
          char S[20];
          bool operator < (const Str &rhs) const{
                    return strcmp(S, rhs.S) < 0;
          }
}str[N];

bool Equal(int i, int j){
          for(int k = 0; k < n; k++)
                    if(str[i].S[k] != str[j].S[k])
                              return false;
          return true;
}

bool is_ok(int i, int j){
          int cnt = 0;
          for(int k = 0; k < n; k++)
                    if(str[i].S[k] != str[j].S[k])
                              cnt++;
          return cnt == 1;
}

int main()
{
          //freopen("in.txt", "r", stdin);
          while(scanf("%d%d", &n, &m) != EOF){
                    if(!n && !m) break;
                    memset(g, 0, sizeof(g));
                    int cnt = 0;
                    char s[20];
                    for(int i = 0; i < m; i++){
                              scanf("%s", s);
                              bool f = true;
                              for(int j = 0; j < n; j++)if(s[j] == '*'){
                                        f = false;
                                        strcpy(str[cnt].S, s);
                                        str[cnt++].S[j] = '0';
                                        strcpy(str[cnt].S, s);
                                        str[cnt++].S[j] = '1';
                                        break;
                              }
                              if(f) strcpy(str[cnt++].S, s);
                    }
                    sort(str, str + cnt);
                    int cur = 0;
                    for(int i = 1; i < cnt; i++){
                              if(strcmp(str[cur].S, str[i].S) != 0)
                                        str[++cur] = str[i];
                    }
                    cur++;
                    X = Y = cur;
                    for(int i = 0; i < cur; i++)
                    for(int j = 0; j < cur; j++)if(i != j){
                              if(is_ok(i, j)) g[i][j] = 1;
                    }
                    printf("%d\n", cur - hungary() / 2);
          }
          return 0;
}



