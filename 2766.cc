#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int step[ 4 ][ 2 ] = { { 1, 0 }, { 0, -1 }, { -1, 0 }, { 0, 1 } };
int main() {
	int t;
	scanf( "%d", &t );
	while ( t-- ) {
		int r, c, n, m, dir;
		scanf( "%d %d", &n, &m );
		vector< vector< bool > > graph = vector< vector< bool > >( n + 2, vector< bool >( n + 2, 0 ) );

		for ( int i = 0; i < m; ++i ) {
			scanf( "%d %d", &r, &c );
			graph[ r ][ c ] = 1;
		}

		scanf( "%d %d", &r, &c );
		dir = !r ? 0 : ( r == n + 1 ? 2 : ( !c ? 3 : 1 ) );
		do {
			r += step[ dir ][ 0 ], c += step[ dir ][ 1 ];
			dir = graph[ r ][ c ] ? ( dir + 1 ) % 4 : dir;
		} while ( r && r != n + 1 && c && c != n + 1 );
		printf( "%d %d\n", r, c );
	}

	return 0;
}
