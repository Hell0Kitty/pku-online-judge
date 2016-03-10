/* @author: */
import java.math.BigInteger;
import java.util.*;


public class Main
{
    public static BigInteger get( BigInteger h ) {
        BigInteger s = h.shiftLeft(1);
        BigInteger a = BigInteger.ONE.shiftLeft( s.bitLength()/2-1 ).subtract( BigInteger.ONE );
        BigInteger b = BigInteger.ONE.shiftLeft( s.bitLength()/2+1 ), c;

        while( a.add(BigInteger.ONE).compareTo(b) < 0 ) {
            c = a.add( b ).shiftRight(1);
            if( c.multiply( c.add(BigInteger.ONE)).compareTo( s ) <=0 )
                a = c;
            else
                b = c;
        }

        return a;
    }
    public static BigInteger X, Y;
    public static void Get( BigInteger s ) {
        BigInteger t = get( s );
        Y = s.subtract( t.multiply(t.add(BigInteger.ONE)).shiftRight(1) );
        X = t.subtract( Y );
    }

    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        String s;
        while( true ) {
            s = cin.next();
            if( s.equals( "*" ) )
                break;
            BigInteger a = new BigInteger( s ), t = BigInteger.ONE, h = BigInteger.ONE, sum = BigInteger.ZERO,
                x =BigInteger.ONE,
                y=BigInteger.ONE, xt=BigInteger.ONE, yt=BigInteger.ONE, x0 = BigInteger.ONE, y0=BigInteger.ONE;
            Get( a );
            t = X; h = Y;
            //System.out.println( X+","+Y );
            //if(X==t)continue;
            int n = t.intValue();

            for( int i=0; i< n; i++ ) {
                a = h;
                if( i < n-1 ) {
                    Get( a );
                    t = X; h = Y;
                }
                else
                    t = a;

                Get( t );
                x = X; y = Y;
                if( i == 0 ) {
                    x0 = x; y0 = y;
                }
                else {
                    sum = sum.add( x.multiply(yt).subtract( y.multiply(xt) ));
                }
                xt = x; yt = y;
                //System.out.println( x + "," + y );
            }
            sum = sum.add( x0.multiply(yt).subtract( y0.multiply(xt) ));
            sum = sum.abs();

            System.out.print( sum.shiftRight(1) );
            if( sum.equals(sum.shiftRight(1).shiftLeft(1)))
                System.out.println( ".0" );
            else
                System.out.println( ".5");
        }
        return;
    }

}

