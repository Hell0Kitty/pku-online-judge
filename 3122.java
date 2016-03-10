/* @author: */
import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int r[]=new int[10000], t, i, n, f, count;
    double a, b, c;
    t=sc.nextInt();
    while(( t--)!=0 ) {
      n=sc.nextInt();
      f=sc.nextInt();
      f++;
      b = 0;
      for( i=0; i< n; i++ ) {
    r[i]=sc.nextInt();
    r[i] *= r[i];
    b += r[i];
      }

      a = 0;
      while( b-a> 1e-5 ) {
    c = (b+a)/2;
    count = 0;
    for( i=0; i< n; i++ )
       count += (int)(r[i]/c);
    if( count >= f )
       a = c;
    else
       b = c;
    }
    System.out.printf( "%.4f\n", a*3.14159265358979324 );
    }
   }
}

