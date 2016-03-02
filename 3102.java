import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
 static double dis[][];
 static int e[][];
 static int [] x, y, en;

 static double distance( int a, int b ) {
	return Math.sqrt( (x[a]-x[b])*(x[a]-x[b]) +
		(y[a]-y[b])*(y[a]-y[b]) );
 }

static void dfs( int k, int f, double [] dis, double s ){
  dis[k] = s;
  int j;
  for( int i=0; i< en[k]; i++ ) {
   if( e[k][i] != f ) {
	j = e[k][i];
	dfs( j, k, dis, s+distance( k, j ) );
   }
  }
 }

 static public void main( String [] str ) throws Exception{
  Scanner cin = new Scanner( System.in );
  int n = cin.nextInt();
  x = new int[n+1];
  y = new int[n+1];
  en = new int[n+1];
  dis = new double[n+1][n+1];
  e = new int[n+1][n+1];

  for( int i=1; i<=n; i++ ) {
    x[i] = cin.nextInt();
    y[i] = cin.nextInt();
  }

  int a, b;
  double t, ans = 0;
  for( int i=1; i<=n; i++ ) {
    a = cin.nextInt();
    b = cin.nextInt();
    e[a][en[a]++] = b;
    e[b][en[b]++] = a;
   }

   for( int i=0; i<=n; i++ )
	dfs( i, -1, dis[i], 0 );

   a = -1;
   b = -1;
   for( int i=0; i<=n; i++ )
    for( int j=i+1; j<=n; j++ ) {
	int k;
	for( k =0; k<=n; k++ )
	  if( k!= i && k!=j &&
	   (x[i]-x[k])*(y[j]-y[k])-(y[i]-y[k])*(x[j]-x[k]) == 0 &&
	   (x[i]-x[k])*(x[j]-x[k])+(y[i]-y[k])*(y[j]-y[k]) <= 0 )
		break;
	  if( k <= n )
	   continue;
	  t = - dis[i][j] + distance( i, j );
	  if( t < ans ) {
	    ans = t;
	    a = i;
	    b = j;
	  }
    }
    System.out.println();

    if( a < 0 )
	System.out.println( -1 );
    else
	System.out.println( a+" "+b );
   }
}

