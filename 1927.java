import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

   int k = 1;
   double l1, l2, l3, s, c, p, R, ctg1, ctg2, ctg3, len, r, ls, area;

   while( sc.hasNext() )
   {
      l1=sc.nextDouble();
      l2=sc.nextDouble();
      l3=sc.nextDouble();
      len=sc.nextDouble();
      if( l1 == 0 && l2 == 0 && l3 == 0 && len == 0 )
	  break;

      c = l1 + l2 + l3;
      p = ( l1 + l2 + l3 ) / 2;
      s = Math.sqrt( p * (p-l1) * (p-l2) * (p-l3) );

      if( len >= c )
      {
	   System.out.printf( "Case %d: %.2f\n", k++, s );
	   continue;
	}
	R = s * 2 / c ;
	if( len <= R * 2 * Math.PI )
	{
           System.out.printf( "Case %d: %.2f\n", k++, len*len / (4*Math.PI) );
	    continue;
	}
	ctg1 = ( p - l1 ) / R;
	ctg2 = ( p - l2 ) / R;
	ctg3 = ( p - l3 ) / R;
	r = ( c - len ) / ( 2 * ( ctg1 + ctg2 + ctg3 ) - 2 * Math.PI );
	ls = c - 2 * ( ctg1 + ctg2 + ctg3 ) * r;
	l1 -= ( ctg2 + ctg3 ) * r;
	l2 -= ( ctg1 + ctg3 ) * r;
	l3 -= ( ctg1 + ctg2 ) * r;
	p = ( l1 + l2 + l3 ) / 2;
	area = ls * r + Math.sqrt( p * (p-l1) * (p-l2) * (p-l3) ) + r * r * Math.PI;
	System.out.printf( "Case %d: %.2f\n", k++, area );
   }
  }
}

