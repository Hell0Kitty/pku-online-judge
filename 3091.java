import java.util.*;
import java.io.*;
import java.lang.reflect.Array;

public class Main {
  static public void main( String [] str ) throws Exception{
   int n;
   int m;
   Scanner cin = new Scanner( System.in );
   n = cin.nextInt();
   for( int k=1; k<=n; k++ ) {
     m = cin.nextInt();
     System.out.println( k+" "+m+" "+(m*2+1)/3 );
     int j = 1;
     int count = -1;
     for( int i=(m+4)/3; i<=m; i+=2 ) {
	System.out.print( "["+i+","+j+"] " );
	j++;
	count++;
	if( count % 8 == 7 )
	  System.out.println();
     }
     j = (m+4)/3+1;

     for( int i=(m+4)/3+1; i<=m; i+=2 ) {
	System.out.print( "["+i+","+j+"] " );
	j++;
       count++;
	if( count % 8 == 7 )
	  System.out.println();
     }
     if( count % 8 != 7 )
	System.out.println();
     System.out.println();
   }

  return;
 }
}

