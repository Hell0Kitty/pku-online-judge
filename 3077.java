import java.math.BigInteger;
import java.util.*;

public class Main
{

    public static void main(String args[])
    {
       int n, s, i;
       Scanner cin = new Scanner( System.in );
       n = cin.nextInt();
       while( n-- != 0 ) {
    	   s = cin.nextInt();
    	   for( i=10; i<=100000000; i*=10 )
    		   if( s >= i ) {
    			   s = (s+i/2)/i*i;
    		   }
    	   System.out.println( s );
       }
       return;
    }
}

