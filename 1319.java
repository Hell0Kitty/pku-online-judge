import java.util.*;
public class Main {
  static final double l = Math.sqrt(3)/2;

  static int calc( double x, double y )
{
	int a[]=new int[2], s, i;
	double h;
	if( x < 1 )
		return 0;
	a[0] = (int)x;
	a[1] = (int)(x-0.5);
	for( i=0, h=1, s=0; h<=y; h+=l, i++ )
		s += a[i%2];
	return s;
}

 public static void main(String[] args){

    Scanner in = new Scanner(System.in);
	int s1, s2, t;	
	double x, y;
	while(in.hasNext())
	{
              x=in.nextDouble();
              y=in.nextDouble();
		s1 = (int)x * (int)y;
		s2 = calc( x, y );
		if( ( t = calc( y, x ) ) > s2 )
			s2 = t;

		if( s1 >= s2 )
			System.out.printf( "%d grid\n", s1 );
		else
			System.out.printf( "%d skew\n", s2 );
	}
  }
}

