#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define cls(a) memset(a,0,sizeof(a))
#define rise(i,a,b) for(int i=a;i<=b;i++)
#define fall(i,a,b) for(int i=a;i>=b;i--)
int n, m, a[501][501], b[501][501], dp[501][501];
int main()
{
	cls( a ); cls( b );
	while( scanf( "%d %d" , &m, &n ) )
	{
		if( !m && !n ) break;
		rise( i , 1 , n ) rise( j , 1 , m )
		scanf( "%d" , &a[i][j] );
		rise( i , 1 , n ) rise( j , 1 , m )
		scanf( "%d" , &b[i][j] );
		cls( dp );
		rise( i , 1 , n )
		rise( j , 0 , m )
		{
			rise( k , 0 , j ) dp[i][j] = max( dp[i-1][k] , dp[i][j] );
			rise( k , 0 , j ) dp[i][j] += a[i][k];
			rise( k , j + 1 , m ) dp[i][j] += b[i][k];
		}
		int ans = 0;
		rise( j , 0 , m )
		ans = max( dp[n][j] , ans );
		cout << ans << endl;
	}
	return 0;
}



