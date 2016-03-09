import java.util.*;
public class Main {
  static int ans[][], xf[][], yf[][];
  static int as[][], len[];
  static public void main( String [] str ) throws Exception{
    Scanner cin = new Scanner(System.in);
    int n = cin.nextInt(), m;
    int [] a, b;
    a = new int[n];
    for( int i=0; i< n; i++ )
    a[i] = cin.nextInt();
    m = cin.nextInt();
    b = new int[m];
    for( int i=0; i< m; i++ )
    b[i] = cin.nextInt();

    ans = new int[n][m];
    xf = new int[n][m];
    yf = new int[n][m];
    as = new int[n][m];
    len = new int[n];

    for( int i=0; i< n; i++ ) {
    for( int j=0; j< m; j++ )
      if( a[i] == b[j] )
         as[i][len[i]++] = j;

       int [] t = new int[len[i]];
       System.arraycopy( as[i], 0, t, 0, len[i] );
       as[i] = t;
    }

    int bx = -1, by = -1;
    for( int i=n-1; i>=0; i-- )
    for( int j=m-1; j>=0; j-- )
      if( a[i] == b[j] ){
        int t, best = 0;
        xf[i][j] = yf[i][j] = -1;
           for( int k=i+1; k< n; k++ )
          if( a[k] > a[i]) {
         t = Arrays.binarySearch( as[k], j+1 );
         if( t < 0 )
           t = -t-1;
         if( t != as[k].length ) {
           t = as[k][t];
           if( ans[k][t] > best ) {
             best = ans[k][t];
             xf[i][j] = k;
             yf[i][j] = t;
            }
          }
          }
       ans[i][j] = best+1;
       if( bx < 0 || ans[i][j] > ans[bx][by] ) {
        bx = i;
        by = j;
       }
     }

    if( bx < 0 )
      System.out.println( 0 + "\n" );
    else {
      System.out.println( ans[bx][by] );
    while( bx != -1 ) {
      System.out.print( a[bx] );
      int x = xf[bx][by], y = yf[bx][by];
      bx = x;
      by = y;
      if( bx != -1 )
        System.out.print( " " );
    }
    System.out.println();
    }
    return;
   }
}

