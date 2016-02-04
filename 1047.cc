#include<stdio.h>
#include<string.h> 
char *strrev( char *s )
{
	if( s == NULL || s[ 0 ] == '\0' )
		return s;

	for( char t, *p = s, *q = s + strlen( s ) - 1; p < q; p++, q-- )
		t = *p, *p = *q, *q = t;
	return s;
}
int main()
{
	char input[ 65 ];
	char c1[ 65 ], c2[ 130 ];
	int length;
	int i, j, k, p, q;
	int flag;
	while( memset( input, 0, sizeof( input ) ) && scanf( "%s", input ) != EOF )
	{
		length = strlen( input );

		memset( c1, 0, sizeof( c1 ) );
		strncpy( c1, input, length );//复制到c1 

		strrev( c1 ); //倒置 
		// 用来判断循环数，例如 142857 ，c2 就为 142857142857，结果只要是 c2 的子串，就是循环的
		memset( c2, 0, sizeof( c2 ) );
		strncpy( c2, c1, length ); 
		strncpy( c2 + length, c1, length );
		flag = 1;
		for( i = 2; i <= length; i++ )
		{
			for( j = 0; j < length; j++ )
			{
				c1[ j ] += ( c2[ j ] - '0' );
				if( c1[ j ] > '9' )
				{
					c1[ j ] -= 10;
					++ c1[ j + 1 ];
				}
			}
			if( strlen( c1 ) > length )
			{
				flag = 0;
				break;
			}
			if( !strstr( c2, c1 ) )
			{
				flag = 0;
				break;
			}
		}
		if( flag )
			printf( "%s is cyclic\n", input );
		else
			printf( "%s is not cyclic\n", input );
	}
	return 0;
}


