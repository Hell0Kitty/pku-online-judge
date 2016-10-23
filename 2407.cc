#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define maxn ( 200000 + 100 )
#define maxe ( 800000 + 10 )
#define LL long long
#define eps 10e-8
#define pii pair<int, int>
#define MP make_pair

LL getans ( LL n )
{
    LL tn = n, res = n;
    for( int i = 2; i <= sqrt( n * 1.0 ); ++i ){
        if( n % i == 0 ) {
            res = res / i * ( i - 1 );
            while( n % i == 0 ) n /= i;
        }
    }
    if( n > 1 ) res = res / n * ( n - 1 );
    return res;
}

int main ()
{
    LL n;
    while( ~scanf("%I64d", &n ) && n )
    {
        printf("%I64d\n", getans( n ));
    }
}




