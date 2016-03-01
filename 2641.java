//* @author:
import java.util.*;
public class Main {
 static public void main( String [] str ){
   Scanner sc = new Scanner(System.in);
   while( sc.hasNext())
   {
     int a=sc.nextInt();
     int b=sc.nextInt();
     int s=sc.nextInt();
     int m=sc.nextInt();
     int n=sc.nextInt();
     if( a == 0 )
	break;
     double x = b*n;
     double y = a*m;
     System.out.printf( "%.2f %.2f\n", Math.atan2( x, y )/Math.acos(-1)*180, Math.sqrt( x*x + y*y ) / s );
     }

    }
}


