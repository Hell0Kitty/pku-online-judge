/* @author: */
import java.util.Scanner;
public class Main {
   public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
	int n, i, k, t, tt, p, count = 0;
       tt=sc.nextInt();
	while(( tt-- )!=0) {
         n=sc.nextInt();
         int a[]=new int[100];
         int b[]=new int[100];
         k = 0;
	  p = 0;
	  while( n!=0 ) {
	   for( ; (n&1)==0; p++, n>>=1 )
		;
	    for( t=1, i=0; t*3<=n; t*=3,i++ )
		;
	    a[k] = p;
	    b[k] = i;
	    n -= t;
	    k++;
	  }
	  System.out.printf( "%d %d", ++count, k );
	  while(( k--)!=0 )
		System.out.printf( " [%d,%d]", a[k], b[k] );
	  System.out.printf( "\n" );
	}
   }
}

