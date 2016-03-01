//* @author:
import java.util.*;
public class Main {

static public void main( String [] str ){
   Scanner sc = new Scanner(System.in);
   while( sc.hasNext())
   {
     double s=1,answer;
     int k=sc.nextInt();
     int n=sc.nextInt();
     double ans[][]=new double[n][k+1];
     for( int i=0; i< n; i++ )
	s *= (k+1);

     for(int  j=0; j<=k; j++ )
	ans[0][j] = 1/s;

     for(int  i=1; i< n; i++ )
	for(int j=0; j<=k; j++ )
	{
	   ans[i][j] = ans[i-1][j];
	   if( j!=0) ans[i][j] += ans[i-1][j-1];
	   if( j< k ) ans[i][j] += ans[i-1][j+1];
	}

     answer = 0;
     for( int j=0; j<=k; j++ )
	answer += ans[n-1][j];
     System.out.printf( "%.5f\n", answer*100 );
    }

   }
}

