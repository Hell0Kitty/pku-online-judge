import java.util.*;
public class Main {
  static double t=0;
  static double e( double s, int k) {
   if( k == 0 )
	return s;
   else {
     double temp = e( 2*s, k-1 );
     double h = s/temp;
     if( t > h )
	return temp*(1-t*t)/2/(1-t);
     else
	return (s*(h-t)+temp*(1-h*h)/2)/(1-t);
    }
}

 static public void main( String [] str ){
   Scanner sc = new Scanner(System.in);
   while(sc.hasNext()) {
       int n=sc.nextInt();
       t=sc.nextDouble();
       if(n==0) break;
       System.out.printf( "%.3f\n", e( 1, n) );
   }
 }
}

