import java.util.*;

public class Main
{
 static String w[] = new String[10];
 public static void main(String args[])
{
   int t, n, i, j = 0, k;
   Scanner cin = new Scanner( System.in );

   t = cin.nextInt();
   String p = new String();
   String best;// = new String("");

   while( t-- != 0 ) {
     n = cin.nextInt();
     best = "";
     for( i=0; i< n; i++ )
  	   w[i] = cin.next();

     for( i=w[0].length(); i>=3; i-- ) {
        for( j=0; j<=w[0].length()-i; j++ ) {
    	    p = w[0].substring( j, i+j );
    	    for( k=1; k< n; k++ ) {
    		if( w[k].indexOf( p ) == -1 )
    		   break;
    	    }

    	   if( k == n && ( best == "" || p.compareTo( best ) < 0 ) )
    		   best = p;
    	}
   	if( best != "" )
   	   break;
    }
    if( i >= 3 )
	System.out.println( best );
   else
	System.out.println( "no significant commonalities" );
  }
  return;
 }
}

