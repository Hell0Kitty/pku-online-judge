import java.util.*;
import static java.lang.Math.*;
public class Main {
 static double  a, b, c;
 static double[] change( double th,double fi, double l)
{
	double z = l * sin( th/180*PI );
	double y = l * cos( th/180*PI ) * sin( fi/180*PI );
	double x = l * cos( th/180*PI ) * cos( fi/180*PI );
      return new double[]{z,y,x};
 }

static public void main( String [] str ){
   Scanner sc = new Scanner(System.in);

 double th, fi, l;
 int n,i,cas=1;
 char name[]=new char[100];
 while( true )
 {
   n=sc.nextInt();
   if( n == 0 ) break;
   System.out.printf( "Test case %d:\n", cas++ );
   th=sc.nextDouble();
   fi=sc.nextDouble();
   l=sc.nextDouble();
   l += 6378;
   double x[]=change( th, fi, l);
   for( i=0; i< n; i++ )
   {
      name=sc.next().toCharArray();
      th=sc.nextDouble();
      fi=sc.nextDouble();
      double a[]=change( th, fi, 6378);
      if( (x[2]-a[2])*a[2] + (x[1]-a[1])*a[1] + (x[0]-a[0])*a[0] >= 0 )
 	System.out.printf( "%s\n", String.valueOf(name) );
    }
	System.out.println();
  }
 }
}

