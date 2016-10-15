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
int n, d, m, x, y, z, t, mole[20][40][40], dp[20][40][40], temp, stepj, stepk;
int gcd(int a,int b)  
{  
	return b==0?a:gcd(b,a%b);  
} 

int main()
{
	while( scanf( "%d %d %d" , &n , &d , &m ) )
	{
		if( !n && !d && !m ) break;
		cls( mole ); cls( dp ); t = 0;

		while( m -- )
		{
			scanf( "%d %d %d" , &x , &y , &z );
			mole[z][x+d][y+d] = 1;
			if( t < z ) t = z;
		}

		n += 2 * d;

		rise( i , 1 , t )
		for( x = 0 ; x < n ; x ++ )
		for( y = 0 ; y < n ; y ++ )
		{
			for( int j = 0 ; j < n ; j ++ )
			for( int k = 0 ; k < n ; k ++ )
			{
				temp = ( x - j ) * ( x - j ) + ( y - k ) * ( y - k );
				if( temp > d * d ) continue;
				if( temp == 0 )
				{
					dp[i][x][y] = max( dp[i][x][y] , dp[i-1][x][y] + mole[i][x][y] );
					continue;
				}
				temp = gcd( abs( j - x ) , abs( k - y ) );
				stepj = ( x - j ) / temp;
				stepk = ( y - k ) / temp;

				if( stepj == 0 && stepk == 0 ) temp = 0;
				else temp = mole[i][x][y];

				for( int nj = j , nk = k ; ( nj != x || nk != y ) ; nj += stepj , nk += stepk )
				{
					temp += mole[i][nj][nk];
				}

				dp[i][x][y] = max( dp[i][x][y] , dp[i-1][j][k] + temp );		
			}
		}
		int ans = 0;
		for( int j = 0 ; j < n ; j ++ )
		for( int k = 0 ; k < n ; k ++ )
		if( ans < dp[t][j][k] ) ans = dp[t][j][k];
		cout << ans << endl;
	}
	return 0;
}



