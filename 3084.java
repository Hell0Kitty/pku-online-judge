/* @author: */
import java.util.*;
class ff
{
  static int min( int a, int b ) {
    return a< b?a:b;
  }

  class edge
 {
  int to;
  int c, f;
  int rev_i;
  edge( int pa, int pb, int pc ) {
	to = pa; c = pb; f = 0;
	rev_i = pc;
   }
  }

  edge e[][] = new edge[30][1000];
  int en[] = new int[30];
  boolean sign[] = new boolean[30];

  void insert_edge( int from, int to, int limit )
  {
	e[from][en[from]] = new edge( to, limit, en[to] );
	e[to][en[to]] = new edge( from, 0, en[from] );
	en[from]++;
	en[to]++;
   }

   void add_flow( edge ee, int d )
  {
	ee.f += d;
	e[ ee.to ][ ee.rev_i ].f -= d;
   }

   int search( int k, int t, int best )
   {
	int i, m = en[k];
	int temp;
	edge ep;
	sign[k] = true;
	if( k == t )
         return best;
	for( i=0; i< m; i++ )
	{
	  ep = e[k][i];
	  if( ep.f < ep.c && !sign[ ep.to ] )
	  {
	   if( ( temp = search( ep.to, t, min( best, ep.c - ep.f ) ) ) > 0 )
	   {
		ep.f += temp;
		e[ ep.to ][ ep.rev_i ].f -= temp;
		return temp;
	    }
	   }
	  }
	 return 0;
     }

   int maxflow( int n, int s, int t )
   {
     int total = 0, add = 0;
     do
     {
	total += add;
	for( int i=0; i< 30; i++ )
	  sign[i] = false;
      }
     while( ( add = search( s, t, (1<< 30) ) ) > 0 );
	return total;
    }
 }

class Main {
 public static void main(String args[]) throws Exception
 {
   Scanner cin = new Scanner( System.in );
   int t, n, m, i, j, ans, b = 0;
   int h, g;
   String w;
   t = cin.nextInt();
   while( t-- != 0 ) {
     ff f = new ff();
     n = cin.nextInt();
     m = cin.nextInt();
     for( i=0; i< n; i++ ) {
    	w = cin.next();
    	if( w.equals( "I" ) ) {
         b = i;
    	  f.insert_edge( n, i, 1000000 );
    	}
    	h = cin.nextInt();
    	for( j=0; j< h; j++ ) {
    	  g = cin.nextInt();
    	  f.insert_edge( g, i, 1 );
    	  f.insert_edge( i, g, 1000000 );
    	}
      }

     ans = f.maxflow( n+1, n, m );
     if( ans >= 1000000 )
    	System.out.println( "PANIC ROOM BREACH" );
     else
    	System.out.println( ans );
   }
   return;
  }
}


