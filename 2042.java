import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n, s, t1, t2, t;
    while( sc.hasNext() )
    {
       n=sc.nextInt();
    if( n == 0 ) break;
    s = 0;
    for(int i=(int)Math.sqrt( n/4 ); i*i<=n; i++ )
    {
         t1=n-i*i;
      for(int j=(int)Math.sqrt( t1/3 ); j<=i && j*j<=t1; j++ )
      {
        t2=t1-j*j;
        for(int k=(int)Math.sqrt(t2/2) ; k<=j && k*k<=t2; k++ )
        {
        t = (int)Math.sqrt( t2 - k*k );
        if( t <= k && t*t == t2 - k*k )
           s++;
        }
      }
       }
    System.out.printf( "%d\n", s );
    }
   }
}

