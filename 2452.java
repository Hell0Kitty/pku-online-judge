//* @author:
import java.util.*;
public class Main {

static public void main( String [] str ) throws Exception{
   Scanner sc = new Scanner(System.in);
   int i, j, h, ans;

   while(sc.hasNext())
   {
      int n=sc.nextInt();
      int s[]=new int[n];
      for( i=0; i< n; i++ )
	 s[i]=sc.nextInt();
      ans = 0;
      for( i=0; i< n && i+ans< n; i++ )
	 if( i==0 || s[i-1]>s[i] )
	   for( h=s[i], j=i+1; j< n; j++ )
	   {
	     if( s[i] > s[j] ) break;
		if( s[j] > h )
		{
		   h = s[j];
		   if( j-i > ans ) ans = j-i;
		}
	    }

	if( ans == 0 ) ans = -1;
	System.out.printf( "%d\n", ans );
     }

   }
}


