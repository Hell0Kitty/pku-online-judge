/* @author: */
import java.util.*;
class point
{
  int x,y;
  point(){x=y=0;}
};

public class Main
{
  static int cheng(point a,point b,point c)
  {
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
  }

  static int dcheng(point a,point b,point c)
  {
	return (b.x-a.x)*(c.x-a.x)+(c.y-a.y)*(b.y-a.y);
  }

  static int in(point []p,int n,point judge)
  {
   int c,j,k;point up,low,temp;
   c=0;j=0;
   while(p[j].y==judge.y)j++;
   for(;j< n;j=k)
   {
	k=j+1;
	while(p[k%n].y==judge.y&&p[k%n].x>judge.x) k++;
	up=p[j];
	low=p[k%n];
	if(up.y< low.y){	temp=up;up=low;low=temp; }
	if(up.y< judge.y||low.y>judge.y)continue;
	if(cheng(low,up,judge)<=0&&k==j+1)continue;
	c++;
    }

    return c%2;
   }

   static point p[][] = new point[30][];
   static int len[] = new int[50];

static boolean judge( int a, int b ) {
  point p1[] = p[a], p2[] = p[b];
  int i, j;
  for( i=0; i< len[a]; i++ )
   for( j=0; j< len[b]; j++ ) {
     if( cheng( p1[i], p2[j], p2[(j+1)%len[b]] ) == 0 &&
	dcheng( p1[i], p2[j], p2[(j+1)%len[b]] ) <= 0 )
	return true;
    }

  for( i=0; i< len[b]; i++ )
   for( j=0; j< len[a]; j++ )
     if( cheng( p2[i], p1[j], p1[(j+1)%len[a]] ) == 0 &&
	 dcheng( p2[i], p1[j], p1[(j+1)%len[a]] ) <= 0 )
	 return true;

  for( i=0; i< len[a]; i++ )
    if( in( p2, len[b], p1[i] ) > 0 )
	return true;
  for( i=0; i< len[b]; i++ )
    if( in( p1, len[a], p2[i] ) > 0 )
	return true;
  return false;
 }

 public static void main(String args[]) throws Exception
 {
   int t, n, j, i, k=1, g;
   int ans[] = new int[500];
   int answer;
   String w;

   Scanner cin = new Scanner( System.in );
   t = cin.nextInt();
   while( t-- != 0 ) {
      n = cin.nextInt();
     for( i=0; i< n; i++ ) {
    	len[i] = cin.nextInt();
    	p[i] = new point[len[i]];
    	for( j=0; j< len[i]; j++ ) {
         w = cin.next();
    	  g = w.indexOf( ',' );
    	  p[i][j] = new point();
    	  p[i][j].x = Integer.parseInt( w.substring(0,g) );
    	  p[i][j].y = Integer.parseInt( w.substring(g+1) );
    	}
    }
    answer = 0;
    for( i=0; i< n; i++ )
	for( j=i+1; j< n; j++ )
	  if( judge( i, j ) )
	   ans[ answer++ ] = (i+1)*100+j+1;
    System.out.println( "Data Set #" + k );
    k++;
    if( answer == 0 )
	System.out.println( "no collisions" );
    else {
	for( i=0; i< answer; i++ )
	   System.out.println( ans[i]/100 + " " + ans[i]%100 );
    }

  }
  return;
 }
}

