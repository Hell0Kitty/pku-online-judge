#include<stdio.h>
#include<string.h> 
#include<iostream>
using namespace std;
int main()
{
	char eight[ 20 ];
	char ten [ 60 ];

	int e;
	double r; 
	int i;
	long long d, s, j;
	while( memset( eight, 0, sizeof( char ) * 20 ) && scanf( "%s", eight) != EOF )
	{
		memset( ten, 0, sizeof( char ) * 60 );
		e = strlen( eight );
		s = 0;
		d = 1;
		i = e;
		while( i > 2)
		{
			d = d * 8;
			i--;
		}
		s = 0;
		j = 1;
		for( i = e - 1; i >= 2; i--)
		{
			s = s + ((long long)( eight[ i ] - '0') * j);
			j = j * 8;
		}
		ten[ 0 ] = '0';
		ten[ 1 ] = '.';

		i = 2;
		while( s != 0){
			s = s * 10;
			ten[ i++] = ( char) ( s / d)+ '0';
			s = s % d;
		}
		printf( "%s [8] = %s [10]\n",eight, ten);
	}
	return 0;
}


