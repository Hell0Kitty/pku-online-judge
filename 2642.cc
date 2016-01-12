#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MP make_pair
#define SQ(x) ((x)*(x))

using namespace std;
typedef long long int64;

const double PI = acos(-1.0);
const int MAXN = 210;
const int INF = 0x3f3f3f3f;
int n, m, copper[MAXN], price[MAXN];
int M[MAXN], CMin[MAXN], CMax[MAXN];
int f[22][20010];

int main(){

    while(~scanf("%d", &n)){

        for(int i=0; i<n; ++i)
            scanf("%d%d", &copper[i], &price[i]);

        scanf("%d", &m);
        int max_M = 0, max_weight=0;
        for(int i=0; i<m; ++i){
            scanf("%d%d%d", &M[i], &CMin[i], &CMax[i]);
            if(M[i] > max_M) max_M=M[i];
            if(CMax[i]*M[i] > max_weight) max_weight = CMax[i]*M[i];
        }

        memset(f, INF, sizeof(f));
        f[0][0] = 0;
        for(int i=0; i<n; ++i){
            for(int j=max_M; j>=1; --j){
                for(int v=max_weight; v>=copper[i]; --v){
                    f[j][v] = min(f[j][v], f[j-1][v-copper[i]]+price[i]);
                }
            }
        }

        for(int i=0; i<m; ++i){
            int minx = INF;
            for(int j=CMin[i]*M[i]; j<=CMax[i]*M[i]; ++j)
                if(f[M[i]][j] < minx) 
                    minx = f[M[i]][j];
            if(minx == INF) puts("impossible");
            else printf("%d\n", minx);
        }
    }
    return 0;
}



