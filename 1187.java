import java.util.*;
public class Main {
  static int s[][][][]=new int[31][11][11][11];

static int get( int d, int l1, int l2, int l3 )
{
    int t, j, k, i, h;
    
    if( l1 == 0 && l2 == 0 && l3 == 0 && d >= 0 )
    	return 1;
	
 	if( d <= 0 )
    	return 0;
    	
	if( ( t = s[d][l1][l2][l3] ) >= 0 )
		return t;
		
	t = 0;
	
	if( d == 1 )
	{
	    if( l1!=0 ) t += get( d, l1-1, l2, l3 );
	    if( l2!=0 ) t += get( d, l1, l2-1, l3 );
	    if( l3!=0 ) t += get( d, l1, l2, l3-1 );
     	
     	t %= 11380;
      	s[d][l1][l2][l3] =  t;
	    return t ;
	}    
	
 	for( i=0; i<=l1-1; i++ )
	for( j=0; j<=l2; j++ )
 	for( k=0; k<=l3; k++ )
  	{
       	t += ( get( d-1, i, j, k ) * get( d, l1-1-i, l2-j, l3-k ) );
        if( t > ( 1 << 30 ) ) t %= 11380;
    }    
  	
	for( j=0; j<=l2-1; j++ )
	for( k=0; k<=l3; k++ )
	{
     	t += ( get( d-1, 0, j, k ) * get( d, l1, l2-1-j, l3-k ) );
 	 	if( t > ( 1 << 30 ) ) t %= 11380;
   	}  	 
	
	for( k=0; k<=l3-1; k++ )
	{
     	t += ( get( d-1, 0, 0, k ) * get( d, l1, l2, l3-1-k ) );
 	 	if( t > ( 1 << 30 ) ) t %= 11380;
   	}  	 

	t %= 11380;
	s[d][l1][l2][l3] = t;
	
	return t;
}

 public static void main(String[] args){

      Scanner in = new Scanner(System.in);



    int d, l1, l2, l3, i, j, k, l;
      l1=in.nextInt();
      l2=in.nextInt();
      l3=in.nextInt();
      d=in.nextInt();
    
 	
 	for( l=0; l<=d; l++ )
 	for( i=0; i<=l1; i++ )
 	for( j=0; j<=l2; j++ )
 	for( k=0; k<=l3; k++ )
 		s[l][i][j][k] = -1;
 		
	System.out.printf( "%d\n", ( get( d, l1, l2, l3 ) - get( d-1, l1, l2, l3 ) + 11380 ) % 11380 );
	
	}
 }	
