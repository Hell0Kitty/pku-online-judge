import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
  static public void main( String [] string ) throws Exception{
   Scanner cin = new Scanner( System.in );
   long p, q;
   while( true ) {
    p = cin.nextLong();
    q = cin.nextLong();
    if( p == 0 && q == 0 )
	break;
    if( p == 0 ) {
	System.out.println( "0 2" );
	continue;
    }
    long s, i, j, sum=2;
    boolean key = false;
    for( i=1; i<=50000 && !key; i++ ) {
	if( sum*q%p == 0 ){
	  s = sum*q/p;
	  j = (long)Math.sqrt( s );
	  if( j+1 > 50000 )
	    break;
	  if( j*(j+1) == s ) {
	    System.out.println( (i+1) + " " + (j-i) );
	    key = true;
	    break;
	   }
	}
	sum += 2*i+2;
     }
     if( !key )
	System.out.println( "impossible" );
    }
    return;
   }
}

