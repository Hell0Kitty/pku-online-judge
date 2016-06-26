#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int maps[2000];
int imge[20][20];
int mind[17]={0};

void fix( int n, int p, int m, int L )
{
	if ( n < m ) {
		for ( int i = 1 ; i <= 4 ; ++ i ) {
			if ( maps[n] ) n = maps[n];
			fix( 4*n+i, p, m, L );
		}
	}else imge[maps[n]/L][maps[n]%L] = p;
}

int main()
{
	mind[1] = 0;
	mind[2] = 1;
	mind[4] = 5;
	mind[8] = 21;
	mind[16] = 85;

	int T,n,m,a,b,p,l;
	while ( cin >> T )
	for ( int t = 1 ; t <= T ; ++ t ) {
		if ( t > 1 ) printf("\n");
		scanf("%d",&n);
		scanf("%d",&m);
		memset( maps, 0, sizeof(maps) );
		for ( int i = 0 ; i < m ; ++ i ) {
			scanf("%d%d",&a,&b);
			maps[a] = b;
		}
		scanf("%d",&m);
		for ( int i = 0 ; i < m ; ++ i ) {
			scanf("%d%d",&p,&l);
			fix( p, l, mind[n], n );
		}
		printf("Case %d\n\n",t);
		for ( int i = 0 ; i < n ; ++ i ) {
			for ( int j = 0 ; j < n ; ++ j )
				printf("%4d",imge[i][j]);
			printf("\n");
		}
	}
	return 0;
}



