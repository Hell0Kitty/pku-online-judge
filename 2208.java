//* @author:
import java.util.*;

public class Main {
 static double area( double l1, double l2, double l3 )
{
    double p = ( l1 + l2 + l3 ) / 2;
    return Math.sqrt( p * (p-l1) * (p-l2) * (p-l3) );
}

static double sq( double a )
{
    return a * a;
}

static public void main( String [] str ) throws Exception{
       Scanner sc = new Scanner(System.in);
    double ab,ad,ac,bc,bd,cd,ah,dh,af,sabc,sbcd, hi, v, bh1, bh2;
       ab=sc.nextDouble();
       ac=sc.nextDouble();
       ad=sc.nextDouble();
       bc=sc.nextDouble();
       bd=sc.nextDouble();
       cd=sc.nextDouble();


    sabc = area( ab, bc, ac );
    sbcd = area( bc, cd, bd );

    ah = sabc * 2 / bc;
    dh = sbcd * 2 / bc;


    bh1 = Math.sqrt( bd*bd - dh*dh );
    if( cd*cd > bd*bd + bc*bc ) bh1 = -bh1;

    bh2 = Math.sqrt( ab*ab - ah*ah );
    if( ac*ac > ab*ab + bc*bc ) bh2 = -bh2;

    af = Math.sqrt( ad*ad - sq( bh1 - bh2 ) );
    hi = area( af, dh, ah ) * 2 / ah;
    v = sabc * hi / 3;

    System.out.printf( "%.4f\n", v );

  }
}

