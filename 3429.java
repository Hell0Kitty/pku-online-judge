//* @author:alpc12
import java.util.*;
import java.math.*;


public class Main {

 int n;

 BigInteger[] x = new BigInteger[115];
 BigInteger[] y = new BigInteger[115];

 public class Line {
    BigInteger a, b, c;
 }


 void run() {
   Scanner cin = new Scanner(System.in);
   BigInteger Zero = BigInteger.ZERO;
   n = cin.nextInt();
   int i;
   for(i = 0; i < n; ++i) {
    x[i] = cin.nextBigInteger();
    y[i] = cin.nextBigInteger();
   }

   int m = cin.nextInt(), ok = 0;
   for(i = 0; i < m; ++i) {
    int a, b, c, d;
    a = cin.nextInt();
    b = cin.nextInt();
    c = cin.nextInt();
    d = cin.nextInt();
    --a; --b; --c; --d;
    Line l1 = new Line(), l2 = new Line();
    l1.a = y[b].subtract(y[a]);
    l1.b = x[a].subtract(x[b]);
    l1.c = (l1.a.multiply(x[a])).add(l1.b.multiply(y[a]));

    l2.a = y[d].subtract(y[c]);
    l2.b = x[c].subtract(x[d]);
    l2.c = (l2.a.multiply(x[c])).add(l2.b.multiply(y[c]));

    BigInteger det = (l1.a.multiply(l2.b)).subtract((l2.a.multiply(l1.b)));
    BigInteger sx = (l2.b.multiply(l1.c)).subtract((l1.b.multiply(l2.c)));
    BigInteger sy = (l1.a.multiply(l2.c)).subtract((l2.a.multiply(l1.c)));
    int j;
    for(j = 0; j < n; ++j) {
        x[j] = x[j].multiply(det);
        y[j] = y[j].multiply(det);
    }
    if(sx.compareTo(Zero) == 0 && sy.compareTo(Zero) == 0) {
        if(ok == 0)
            ok = i+1;
    }
    x[n] = sx;
    y[n] = sy;
    n++;
    }
    System.out.println(ok);
   }

    public static void main(String[] args) {
        new Main().run();

    }

}

