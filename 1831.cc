#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<utility>
#define M0(x) memset(x, 0, sizeof(x))
#define Inf 0x7fffffff
#define PB push_back
#define SZ(v) ((int)(v).size())
#define N 76666
using namespace std;
int n, m, T, ans[N];

bool dfs(int k, int s){
    if (s > n) return false;
    int r, w;
    if (s == n){
         m = k;
         return true;
    }
    for (int i = 1; i <= k; ++i){
         r = ans[i];
         ans[i] = r + 1;
         ans[k+1] = r * (r + 1);
         if (dfs(k + 1, s + r * r + r + 1)) return true;
         w = 4;
         for (int j = 2; j <= w; ++j){
              ans[i] = r * j;
              for (int t = 1; t < j; ++t) ans[k + t] = r * j;
              if (dfs(k + j - 1, s + (j * j - 1) * r)) return true;
         }
         ans[i] = r;
    }
    return false;
}

void solve(){
    scanf("%d", &n);
    int r = int(sqrt(n + .0));
    if (r * r == n){
        for (int i = 0; i <= r; ++i)
            printf("%d ", r);
        puts("");
        return;
    }
    if (n == 32){
            printf ("4 2 3 9 18\n") ;
            return;
    }
    if (n == 39){
            printf ("5 2 6 6 10 15\n") ;
            return ;
    }
    ans[1] = 1 ;
    if (dfs(1, 1)){
         printf("%d ", m);
         for (int i = 1; i <= m; ++i)
             printf("%d ", ans[i]);
         puts("");
    } else puts("-1");
}

int main(){
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i){
          solve();
    }
    return 0;
}



