//* @author:
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;
public class Main {

   public static void main(String args[]){
       Scanner in=new Scanner(System.in);
       String op=null;
       while(in.hasNext()){
        String line=in.nextLine();
        StringTokenizer token=new StringTokenizer(line,"/+-",true);
         int i=0;
        String data[]=new String[token.countTokens()];
        while(token.hasMoreTokens())
         {
           data[i]=token.nextToken();
           i++;
         }
       Fraction a=new Fraction();
       Fraction b=new Fraction();
       Fraction c=new Fraction();
       Fraction d=new Fraction();

       a.set(data[0],data[2]);
       b.set(data[4],data[6]);
       if(data[3].equals("+"))
         a.add(b).print();
       else
        a.subtract(b).print();
      }
  }
}
class Fraction{//一个用JAVA写的分数类
    BigInteger numerator, denominator, gcd;

    void set(String n, String d) {
        numerator = new BigInteger(n);
        denominator = new BigInteger(d);
    }

    void simplify() {
        gcd = numerator.gcd(denominator);
        numerator = numerator.divide(gcd);
        denominator = denominator.divide(gcd);
        if (denominator.compareTo(BigInteger.ZERO) < 0) {
            numerator = numerator.negate();
            denominator = denominator.negate();
        }
    }

    int compareTo(Fraction y) {
        Fraction z = this.subtract(y);
        return z.numerator.compareTo(BigInteger.ZERO);
    }

    Fraction abs() {
        Fraction z = new Fraction();
        if (numerator.compareTo(BigInteger.ZERO) < 0) {
            z.numerator = numerator.negate();
        } else {
            z.numerator = numerator;
        }
        if (denominator.compareTo(BigInteger.ZERO) < 0) {
            z.denominator = denominator.negate();
        } else {
            z.denominator = denominator;
        }
        return z;
    }

    Fraction negate() {
        Fraction z = this;
        z.numerator = z.numerator.negate();
        return z;
    }

    boolean zero() {
        return numerator.compareTo(BigInteger.ZERO) == 0;
    }

    Fraction add(Fraction y) {
        Fraction z = new Fraction();
        gcd = denominator.gcd(y.denominator);
        z.denominator = denominator.multiply(y.denominator).divide(gcd);
        z.numerator = numerator.multiply(z.denominator.divide(denominator))
          .add(y.numerator.multiply(z.denominator.divide(y.denominator)));
        z.simplify();
        return z;
    }

    Fraction subtract(Fraction y) {
        Fraction z = new Fraction();
        gcd = denominator.gcd(y.denominator);
        z.denominator = denominator.multiply(y.denominator).divide(gcd);
        z.numerator = numerator.multiply(z.denominator.divide(denominator))
           .subtract(y.numerator.multiply(z.denominator.divide(y.denominator)));
        z.simplify();
        return z;
    }

    Fraction multiply(Fraction y) {
        Fraction z = new Fraction();
        z.numerator = numerator.multiply(y.numerator);
        z.denominator = denominator.multiply(y.denominator);
        z.simplify();
        return z;
    }

    Fraction divide(Fraction y) {
        Fraction z = new Fraction();
        z.numerator = numerator.multiply(y.denominator);
        z.denominator = denominator.multiply(y.numerator);
        z.simplify();
        return z;
    }

    void print() {
        if (denominator.compareTo(BigInteger.ONE) != 0) {
            System.out.printf("%s/%s", numerator.toString(), denominator.toString());
        } else {
            System.out.printf("%s", numerator.toString());
        }
        System.out.println();
    }
  }

  解法二：//@author:geshenghua@live.com.sg

  import java.util.*;

public class Main {

    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        String str;
        int n1, n2, n3, d1, d2, d3, op, x, y, z;
        boolean neg = false;
        while (in.hasNext()) {
            neg = false;
            str = in.next();
            op = 1;
            n1 = str.charAt(0) - '0';
            d1 = str.charAt(2) - '0';
            if (str.charAt(3) == '-') {
                op = -1;
            }
            n2 = str.charAt(4) - '0';
            d2 = str.charAt(6) - '0';
            n3 = n1 * d2 + op * n2 * d1;
            d3 = d1 * d2;
            if (n3 == 0) {
                System.out.println("0");
                continue;
            }
            if (n3 < 0) {
                neg = true;
            }
            n3 = Math.abs(n3);
            d3 = Math.abs(d3);
            x = n3 > d3 ? n3 : d3;
            y = n3 < d3 ? n3 : d3;
            while (y > 0) {
                z = x % y;
                x = y;
                y = z;
            }
            n3 /= x;
            d3 /= x;

            if (neg) {
                System.out.print("-");
            }
            if (d3 == 1) {
                System.out.println(n3);
            } else {
                System.out.println(n3 + "/" + d3);
            }
        }
    }
}


