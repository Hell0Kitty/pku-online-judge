import java.util.Scanner;
public class Main {
 static final double EPS =1e-7;

  //矩形x*y 能否放入 a*b 中
static  boolean canfit( double a, double b, double x, double y )
{
   double t;
   double l=Math.sqrt(x*x+y*y),ll=x*x+y*y;
   if(x*x+y*y - a*a-b*b > EPS)
    return false;

   if(x< y)
    {
    t=x;x=y;y=t;
    }
   if(a< b)
   {
    t=a;a=b;b=t;
   }
   if( x-b >EPS && y -b > EPS )return false;
    double s=(4*x*y*b+Math.sqrt(16*x*x*y*y*b*b-4*ll*(4*x*x*y*y-ll*ll+b*b*ll) ) )/ll/2;

   if(s-a > EPS)
    return false;
   else return true;
}

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);


    double a, b, c, d, e;
    a=sc.nextDouble();
    b=sc.nextDouble();
    c=sc.nextDouble();
    d=sc.nextDouble();
    e=sc.nextDouble();

    if( canfit( d, e, a, b ) || canfit( d, e, a, c ) || canfit( d, e, b, c ) )
    System.out.printf( "YES\n" );
    else
    System.out.printf( "NO\n" );

  }
}

