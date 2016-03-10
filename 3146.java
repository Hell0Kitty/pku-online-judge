/* @author: */
import java.util.Scanner;
public class Main {

 static int clac( int s, int p, int n ) {
    if( s < p ) return 0;
    return (s-n%s-1)*(n/s) + clac( s/p, p, n%s )*((n+s-1)/s);
}

 public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

   int n, p, s, k=0, t;
   while(sc.hasNext()) {
     p=sc.nextInt();
     n=sc.nextInt();
    if(p==00&&n==0) break;
    s = 1;
    while( s <= n/p )
    s *= p;
    t = clac( s, p, n );
    System.out.printf( "Case %d: %04d\n", ++k, (n+1-t)%10000 );
   }
  }
}

