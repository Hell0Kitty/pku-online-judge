#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <stack>
#include <string>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <deque>
#include <set>
using namespace std;

#define LOCAL_HOST
#define ONLINE_JUDGE
#define TIME_OUT_PUT

#define INF 0x7F7F7F7F
#define eps 1e-8
#define PI acos( -1. )
#define PI2 asin ( 1. );
typedef long long LL;

#define MP make_pair
typedef vector<int> VI;
typedef vector<int> VS;
typedef pair<int , int> PII;
#define pb push_back
#define mp make_pair

#define FOR(a,b,i) for ( i = a ; i < b ; i++ )
#define FORE(a,b,i) for ( i = a ; i <= b ; i++ )
#define REP(i,n) FOR(0,n,i)
#define CL(a,b) memset ( a , b , sizeof ( a ) )
#define sqr(a,b) sqrt ( (double)(a)*(a) + (b)*(b) )

template < typename T > double DIS ( T va , T vb ) { return sqr ( va.x - vb.x , va.y - vb.y ); }
template <class T> inline T INT_LEN( T v ) { int len = 1 ; while ( v /= 10 ) ++len; return len; }

#define le 23

typedef struct {
    double x , y;
}re;
re ar[le] , br[le] , pq[le];

int q[le << 1];

int N , M;

void input (){
    int i;
    scanf ( "%d" , &N );
    REP ( i , N ) scanf ( "%lf%lf" , &ar[i].x , &ar[i].y );
    scanf ( "%d" , &M );
    REP ( i , M ) scanf ( "%lf%lf" , &br[i].x , &br[i].y );
}

template < typename T >
T my_abs ( T num ){
    return num >= 0 ? num : -num;
}

inline int sgn ( double d ) {
    if ( d > eps )   return  1;
    if ( d < -eps )  return -1;
    return 0;
}

template < typename T >
inline int Cmp ( T a , T b , T c ){
    if ( my_abs ( b.x - c.x ) > my_abs ( b.y - c.y ) ){
        return sgn ( a.x - min ( b.x , c.x ) ) * sgn ( a.x - max ( b.x , c.x ) );
    }else {
        return sgn ( a.y - min ( b.y , c.y ) ) * sgn ( a.y - max ( b.y , c.y ) );
    }
}

template < typename T >
inline double det ( T a , T b , T c ){
    return ( b.x - a.x ) * ( c.y - a.y ) - ( b.y - a.y ) * ( c.x - a.x );
}

template < typename T >
inline int insec_line ( T a , T b , T c , T d , T &P ){
    double s1 , s2;
    int d1 = sgn ( s1 = det ( a , b , c ) );
    int d2 = sgn ( s2 = det ( a , b , d ) );
    if ( ( d1 ^ d2 ) == -2 ){
        s1 = fabs ( s1 );   s2 = fabs ( s2 );
        P.x = ( c.x * s2 + d.x * s1 ) / ( s1 + s2 );
        P.y = ( c.y * s2 + d.y * s1 ) / ( s1 + s2 );
    }else if ( d1 == 0 ){
        P = c; return 1;
    }else if ( d2 == 0 ){
        P = d; return 1;
    }else {
        return 0;
    }
}

template < typename T >
int Melkman ( T p[] , int *q , int &front , int &rear , int n ){
    int i;
    q[n] = 0;
    FOR ( 2 , n , i ){
        q[-~n] = ~-i;
        if ( det ( p[0] , p[~-i] , p[i] ) ) break;
    }
    if ( i >= n ) return 0;
    front = n , rear = -~n;
    q[--front] = q[++rear] = i;
    if ( det ( p[0] , p[ q[-~n] ] , p[ q[n + 2] ] ) < 0 ) swap ( p[0] , p[ q[-~n] ] );
    for ( ++i ; i < n ; i++ ){
        if ( det ( p[ q[~-rear] ] , p[ q[rear] ] , p[i] ) > 0 && det ( p[ q[front] ] , p[ q[-~front] ] , p[i] ) > 0 ) continue;
        while ( det ( p[ q[~-rear] ] , p[ q[rear] ] , p[i] ) <= 0 ) rear--;
        q[++rear] = i;
        while ( det ( p[ q[front] ] , p[ q[-~front] ] , p[i] ) <= 0 ) front++;
        q[--front] = i;
    }
    return 1;
}

template < typename T >
double convex_cal_min_dis ( T p[] , int *q , int &front , int &rear , int n ){
    int i , j;
    double dis , mn = INF , mx ;
    FORE ( -~front , rear , i ){
        dis = DIS ( p[ q[i] ] , p[ q[~-i] ] );
        mx = 0;
        FOR ( front , rear , j ){
            mx = max ( mx , fabs ( det ( p[ q[~-i] ] , p[ q[i] ] , p[ q[j] ] ) ) / dis );
        }
        mn = min ( mn , mx );
    }
    return mn;
}

template < typename T >
double convex_min_dis ( T p[] , int n ){
    int front , rear ;
    if ( Melkman ( p , q , front , rear , n ) ){
        return convex_cal_min_dis ( p , q , front , rear , n );
    }else return -1;
}

template < typename T >
inline bool inside ( T p[] , T &o , int n ){
    int i , num = 0;
    T va , vb;
    REP ( i , n ){
        if ( !sgn ( det ( o , p[i] , p[-~i] ) ) && Cmp ( o , p[i] , p[-~i] ) <= 0 )
            return true;
    }
    REP ( i , n ){
        va = p[i] , vb = p[-~i];
        if ( va.y > vb.y ) swap ( va , vb );
        if ( det ( o , va , vb ) < 0 && va.y <= o.y && o.y <= vb.y ) num++;
    }
    return num & 1;
}

bool convex_cmp ( re va , re vb ){
    return fabs ( va.x - vb.x ) <= eps ? va.y < vb.y : va.x < vb.x;
}

template < typename T >
inline double hole_cal_max_len ( T &p1 , T &p2 , T p[] , T pq[] , int n ){
    int i , k = 0;
    REP ( i , n ){
        if ( insec_line ( p1 , p2 , p[i] , p[-~i] , pq[k] ) ) k++;
    }
    sort ( pq , pq + k , convex_cmp );
    double len = 0 , mx = 0 ;
    T mid;
    k--;
    REP ( i , k ){
        mid.x = ( pq[i].x + pq[-~i].x ) / 2.;
        mid.y = ( pq[i].y + pq[-~i].y ) / 2.;
        if ( inside ( p , mid , n ) ){
            len += DIS ( pq[i] , pq[-~i] );
            mx = max ( mx , len );
        }else {
            len = 0;
        }
    }
    return mx;
}

template < typename T >
double hole_max_len ( T p[] , int n ){
    int i , j;
    double mx = 0 , len;
    p[n] = p[0];
    REP ( i , n ){
        FOR ( -~i , n , j ){
            len = hole_cal_max_len ( p[i] , p[j] , p , pq , n );
            mx = max ( mx , len );
        }
    }
    return mx;
}

void solve ( re hole[] , re coin[] , int n , int m ){
    double mn = convex_min_dis ( coin , m );
    double mx = hole_max_len ( hole , n );
    if ( mn <= mx ) puts ( "legal" );
    else puts ( "illegal" );
}

int main (void){
    int cas;
    scanf ( "%d" , &cas );
    while ( cas-- ){
        input ();
        solve ( ar , br , N , M );
    }
    return 0;
}



