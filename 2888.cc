#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
#define MP make_pair
#define mnx 50005
#define mod 9973

int pri[mnx], tot;
bool isnot[mnx];
void init(){
    for( int i = 2; i < mnx; ++i ){
        if( !isnot[i] ){
            pri[tot++] = i;
        }
        for( int j = 0; j < tot && i * pri[j] < mnx; ++j ){
            isnot[i*pri[j]] = 1;
            if( i % pri[j] == 0 )
                break;
        }
    }
}
int phi( int x ){
    int ret = x;
    for( int i = 0; i < tot && pri[i] * pri[i] <= x; ++i ){
        if( x % pri[i] == 0 )
            ret = ret / pri[i] * ( pri[i] - 1 );
        while( x % pri[i] == 0 )
            x /= pri[i];
    }
    if( x > 1 ) ret = ret / x * ( x - 1 );
    return ret % mod;
}
int n, m;
struct Matrix{
    int g[12][12];
    Matrix operator * ( const Matrix &b ) const {
        Matrix ret;
        memset( ret.g, 0, sizeof(ret.g) );
        for( int i = 1; i <= m; ++i )
            for( int j = 1; j <= m; ++j ){
                for( int k = 1; k <= m; ++k )
                    ret.g[i][j] += g[i][k] * b.g[k][j];
                ret.g[i][j] %= mod;
            }
        return ret;
    }
};
Matrix qpow( Matrix x, int k ){
    Matrix ret;
    memset( ret.g, 0, sizeof(ret.g) );
    for( int i = 1; i <= m; ++i )
        ret.g[i][i] = 1;
    while( k ){
        if( k & 1 ) ret = ret * x;
        x = x * x;
        k >>= 1;
    }
    return ret;
}
int qpow( int x, int k ){
    int ret = 1;
    x %= mod;
    while( k ){
        if( k & 1 ) ret = ret * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return ret;
}
int k;
Matrix a;
int gao( int x ){
    int res = 0;
    Matrix ret = qpow( a, x );
    for( int i = 1; i <= m; ++i )
        res += ret.g[i][i];
    return res % mod;
}
void solve(){
    int ans = 0;
    int i;
    for( i = 1; i * i < n; ++i ){
        if( n % i == 0 ){
            int tmp = n / i;
            ans = ( ans + phi(tmp) * gao(i) ) % mod;
            ans = ( ans + phi(i) * gao(tmp) ) % mod;
        }
    }
    if( i * i == n )
        ans = ( ans + phi(i) * gao(i) ) % mod;
    int inv = qpow( n % mod, mod - 2 ) % mod;
    ans = ( ans * inv ) % mod;
    printf( "%d\n", ans );
}
int main(){
   // freopen( "tt.txt", "r", stdin );
    int cas;
    init();
    scanf( "%d", &cas );
    while( cas-- ){
        scanf( "%d%d%d", &n, &m, &k );
        for( int i = 1; i <= m; ++i )
            for( int j = 1; j <= m; ++j )
                a.g[i][j] = 1;
        for( int i = 0; i < k; ++i ){
            int u, v;
            scanf( "%d%d", &u, &v );
            a.g[u][v] = a.g[v][u] = 0;
        }
        solve();
    }
    return 0;
}


