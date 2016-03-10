/* @author: */
import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
  static public void main( String [] string ) throws Exception{
    Scanner cin = new Scanner( System.in );
    int m = cin.nextInt();
    int n, i, p1, p0, s;
    double v;
    while( (m--) > 0 ) {
    s = n = cin.nextInt();
    v = 0;
    for( i=1; i< n; i<<=1 ) {
      if( (s&1) == 1 ) {
        p0 = (s/2+1)*i;
        p1 = n-p0;
      }
      else {
        p1 = s/2*i;
        p0 = n-p1;
      }
      v += i*(2.0*p1/n*p0/n);
      s >>= 1;
    }
    System.out.printf( "%.2f\n", new Object[]{ Double.valueOf(v) } );
    }
    return;
   }
}

