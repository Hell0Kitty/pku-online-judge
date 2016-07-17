#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#define for0(a,b) for(a=0;a<b;++a)
#define for1(a,b) for(a=1;a<=b;++a)
#define foru(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=a;i>=b;--i)
using namespace std;

typedef double db;
typedef long long ll;
const db eps = 1e-8;
const int inf = 1e9;
const int N = 105;
db a[N][N], g[N][N], x[N];
int pos[N][N];
int n, m, d, cnt;

int dis(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

void Gauss()
{
    db tmp, big;
    for(int i=0; i<cnt; ++i) {
        int r, big = 0;
        for(int j=i; j<cnt; ++j) {
            if(abs(g[j][i])>big) {
                big = abs(g[j][i]);
                r = j;
            }
        }
        if(r != i) {
            for (int j = 0; j <= cnt; j++) {
                swap(g[i][j], g[r][j]);
            }
        }

        for(int j=i+1; j<cnt; ++j) {
            if(g[j][i]) {
                tmp = g[j][i]/g[i][i];
                for(int k=i; k<=cnt; ++k) {
                    g[j][k] -= tmp*g[i][k];
                }
            }
        }

        for(int i=cnt-1; i>=0; --i) {
            tmp = 0;
            for(int j=i+1; j<cnt; ++j) {
                tmp += g[i][j]*x[j];
            }
            x[i] = (g[i][cnt] - tmp)/g[i][i];
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.cpp", "r", stdin);
    freopen("out.cpp","w", stdout);
#endif // ONLINE_JUDGE
    bool first = 1;
    while(~scanf("%d%d%d", &m, &n, &d)) {
        if(m==0&&n==0&&d==0) break;
        if(!first) puts("");
        else first = 0;
        cnt = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%lf", &a[i][j]);
                pos[i][j] = cnt++;
            }
        }
        memset(g, 0, sizeof g );
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                for(int k=0; k<n; ++k) {
                    for(int l=0; l<m; ++l) {
                        if(dis(i,j,k,l)<=d) {
                            g[pos[i][j]][pos[k][l]] = 1;
                            g[pos[i][j]][cnt] += a[i][j];
                        }
                    }
                }
            }
        }

        Gauss();
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                printf("%8.2lf", x[i*m + j]);
            }
            printf("\n");
        }
    }
    return 0;
}


