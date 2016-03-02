/* @author: */
import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
  static int a[][] = new int[12][12];
  static long ans[] = new long[12];

  static public void main( String [] str ) throws Exception{
    int n;
    int m;
    Scanner cin = new Scanner( System.in );
    n = cin.nextInt();

    a[1][1] = 1;
    a[1][0] = 1;
    for( int i=2; i<=11; i++ ) {
     for( int j=1; j<=i; j++ )
	for( int k=1; k< i; k++ )
	  a[i][j] += a[k][j]*j+a[k][j-1]*j;
    }

    for( int i=1; i<=11; i++ ) {
      ans[i] = ans[i-1];
      for( int j=1; j<=i; j++ )
	 ans[i] += a[i][j];
    }

    for( int k=1; k<=n; k++ ) {
	m = cin.nextInt();
	System.out.println( k+" "+m+" "+ans[m] );
    }
    return;
   }
}

