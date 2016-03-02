/* @author: */
import java.util.*;
public class Main
{
  static String map[] = new String[50];
  static int q[] = new int[2000];
  static int n, m;
  static boolean inmap( int x, int y ) {
	return 0<=x&&x< n && 0<=y&&y< m;
  }

  static boolean sign[][] = new boolean[50][50];
  static final int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

 static int search( int x, int y, int towards, int key ) {
   int xx, yy;
   if( map[x].charAt(y) == 'E' )
	return 1;
    //	System.out.print( x + " " + y + "\n" );
   for( int i=towards+4-key; ;i+=key )
	if( inmap(xx=x+dx[i&3],yy=y+dy[i&3]) && map[xx].charAt(yy) != '#' )
         return search( xx, yy, i&3, key ) + 1;
  }

  static int shortest( int x, int y ) {
    int i, j, qh, qt, xx, yy;
    for( i=0; i< n; i++ )
	for( j=0; j< m; j++ )
	  sign[i][j] = false;
    qh = 0;
    qt = 2;
    q[0] = (x<< 8)+y;
    q[1] = -1;
    sign[x][y] = true;

    int count = 2;
    while( true ) {
	int c = q[qh++];
	if( c < 0 ) {
	  count++;
	  q[qt++] = c;
	  continue;
	}
      x = c>>8;
      y = ( c & ((1<<8)-1) );
     for( i=0; i< 4; i++ )
      if( inmap(xx=x+dx[i],yy=y+dy[i]) && map[xx].charAt(yy) != '#' && !sign[xx][yy] ) {
	  q[qt++] = (xx<<8) + yy;
	  if( map[xx].charAt(yy) == 'E' )
	    return count;
	  sign[xx][yy] = true;
	}
    }

  }

 public static void main(String args[])
 {
    int t, j, i;
    Scanner cin = new Scanner( System.in );
    t = cin.nextInt();
    while( t-- != 0 ) {
    	m = cin.nextInt();
    	n = cin.nextInt();
    	for( i=0; i< n; i++ )
        map[i] = cin.next();
      loop: for( i=0; i< n; i++ ) {
    	  for( j=0; j< m; j++ )
    	   if( map[i].charAt( j ) == 'S' ) {
    	     System.out.println( search( i, j, 0, -1 ) + " " + search( i, j, 0, 1 )
    			+ " " + shortest(i,j) );
    	     break loop;
    	   }
    	}
    }
       return;
   }
}

