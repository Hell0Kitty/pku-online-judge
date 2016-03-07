import java.util.*;
public class Main {

static int dis[][][][]=new int[8][8][8][8];
static int x[]=new int[64],y[]=new int[64], n;

static void floyd()
{
    int i1, i2, i3, j1, j2, j3, t;
    
    for( i1=0; i1<8; i1++ )
    for( j1=0; j1<8; j1++ )
    for( i2=0; i2<8; i2++ )
    for( j2=0; j2<8; j2++ )
    for( i3=0; i3<8; i3++ )
    for( j3=0; j3<8; j3++ )
    	if( ( t = dis[i2][j2][i1][j1] + dis[i1][j1][i3][j3] ) < dis[i2][j2][i3][j3] )
    		dis[i2][j2][i3][j3] = t;
}


static void init()
{
    char w[]=new char[200];
    int i,i1,i2,j1,j2;
    Scanner in = new Scanner(System.in);
     w=in.next().toCharArray();
	
	for( i=0; i<w.length-1; i+= 2 ){
		x[i/2] = w[i] - 'A';
         y[i/2] = w[i+1] - '1';
       }
	
 	n = i / 2;
		
	for( i1=0; i1<8; i1++ )
    for( j1=0; j1<8; j1++ )
    for( i2=0; i2<8; i2++ )
    for( j2=0; j2<8; j2++ )
    	if( ( Math.abs( i1 - i2 ) == 2 && Math.abs( j1 - j2 ) == 1  ) || ( Math.abs( i1 - i2 ) == 1 && Math.abs( j1 - j2 ) == 2 ) )
     		dis[i1][j1][i2][j2] = 1;
       	else if( i1 == i2 && j1 == j2 ) dis[i1][j1][i2][j2] = 0;
        else dis[i1][j1][i2][j2] = 999; 
	
 	floyd();
}

static void doit()
{
    int i1, i2, j1, j2, k, ans, t, temp, h;	
    
    ans = 99999;
    for( i1=0; i1<8; i1++ )
    for( j1=0; j1<8; j1++ )
    {
        temp = 0;
        for( k=1; k<n; k++ )
        	temp += dis[x[k]][y[k]][i1][j1];
    	
    	for( k=1; k<n; k++ )
    	{
    	    t = temp - dis[x[k]][y[k]][i1][j1];
    	    
    	    for( i2=0; i2<8; i2++ )
    		for( j2=0; j2<8; j2++ )
    		{
          		h = t + dis[x[k]][y[k]][i2][j2] + dis[i2][j2][i1][j1] + 
            		 ( Math.abs( x[0]-i2 ) > Math.abs( y[0]-j2 ) ? Math.abs( x[0]-i2 ) : Math.abs( y[0]-j2 ) );
            	
             	if( h < ans ) ans = h;
         	}
         	
      	}
   	}
    
    System.out.printf( "%d\n", ans );
}

 public static void main(String[] args){

    init();
    doit();
 }           	
}