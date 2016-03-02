import java.math.BigInteger;
import java.util.*;

public class Main
{
    static String name[] = new String[20];
    static int pos[] = new int[20];
    public static void main(String args[])
    {
       Scanner cin = new Scanner( System.in );
       int t, n, m, a, b;
       t = cin.nextInt();
       while( t-- != 0 ) {
    	 n = cin.nextInt();
    	 m = cin.nextInt();
    	 for( int i=0; i< n; i++ ) {
    	   name[i] = cin.next();
    	   pos[i] = i;
    	 }
    	 boolean sign[] = new boolean[20];
    	 boolean flag[] = new boolean[20];
    	 while( m-- != 0 ) {
    	   a = cin.nextInt();
    	   b = cin.nextInt();
    	   a--;
    	   b--;
    	   pos[b] = a;
    	   sign[a] = true;
    	   flag[b] = true;
    	 }
    	 int j=0;
    	 for( int i=0; i< n; i++ ){
    	   if( flag[i])
    	     System.out.print( name[pos[i]] );
    	   else {
    	     while( sign[j] )
    	       j++;
    	   System.out.print( name[j] );
    	       j++;
    	}
    	if( i< n-1 )
    	   System.out.print( " " );
    	else
    	   System.out.print( "\n" );
     }
   }
   return;
  }
}

