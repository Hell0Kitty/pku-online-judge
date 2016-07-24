#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define PB push_back
#define MP make_pair
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define X first
#define Y second
#define lson l,m,o<<1
#define rson m+1,r,o<<1|1
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
int dp[110][210][2];
int N, K;
VI T[110];
int num[110];

void init() {
    REP(i, 110) T[i].clear();
}

void tree_dp(int o, int pa) {
    REP(i, T[o].size()) {
        int v = T[o][i];
        if (v != pa) {
            tree_dp(v, o);
            DEP(j, K, 1) {
                REP2(k, 1, j) {
                    dp[o][j][0] = max(dp[o][j][0], dp[o][j-k][1] + dp[v][k-1][0]);
                    dp[o][j][0] = max(dp[o][j][0], dp[o][j-k][0] + dp[v][k-2][1]);
                    dp[o][j][1] = max(dp[o][j][1], dp[o][j-k][1] + dp[v][k-2][1]);
                }
            }
        }
    }
}

int main() {
    while (~scanf("%d%d", &N, &K)) {
        init();
        REP(i, N) {
            int x;
            scanf("%d", &x);
            REP(j, K+1) dp[i][j][0] = dp[i][j][1] = x;
        }
        REP(i, N-1) {
            int u, v;
            scanf("%d%d", &u, &v);
            u--; v--;
            T[u].PB(v);
            T[v].PB(u);
        }
        tree_dp(0, -1);
        printf("%d\n", max(dp[0][K][1], dp[0][K][0]));
    }
    return 0;
}



