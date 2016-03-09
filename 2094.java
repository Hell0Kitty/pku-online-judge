import java.math.*;
import java.util.*;

public class Main {
 static BigInteger l, t;
 static int m, n, k;
 static BigInteger[] a = new BigInteger[15];
 static BigInteger[][] q = new BigInteger[15][15];
 static char[] c;
 static char[] cc;

 public static void main(String[] args) {
   Scanner in = new Scanner(System.in);
   n = in.nextInt();
   l = new BigInteger(in.next());
   k = in.nextInt();
   m = in.nextInt();
   BigInteger w = BigInteger.TEN.pow(m);
   for (int i = 0; i <= n; ++i)
    a[i] = new BigInteger(in.next());
    for (int i = 0; i < Math.min(k, n + 1); ++i) {
        t = a[0];
     for (int j = 1; j <= n; ++j) {
       t = t.multiply(l);
       t = t.add(a[j]);
      }
     t=t.mod(w);
     q[n][i] = t.mod(w);
     int ret = 0;
     c = t.toString().toCharArray();
     int ll = c.length;
     for (int j = 0; j < Math.min(m, ll); ++j) {
      ret += (c[ll - 1 - j] - '0') * (c[ll - 1 - j] - '0');
     }
     System.out.println(ret);
     l = l.add(BigInteger.ONE);
    }
    if (k > n) {
      for (int i = n - 1; i >= 0; --i) {
       for (int j = 0; j <= i; j++)
        q[i][j] = q[i + 1][j + 1].subtract(q[i + 1][j]).mod(w);
       }
      for(int i=1;i<=n;++i)
       q[0][i]=q[0][0];
       int po = 1;
       for (int i = n + 1; i < k; ++i) {
        for (int j = 1; j <= n; ++j)
        q[j][(po + j) % (n + 1)] = q[j - 1][(po + j - 1) % (n + 1)]
         .add(q[j][(po + j - 1) % (n + 1)]).mod(w);
        int ret = 0;
        c = q[n][(po + n) % (n + 1)].mod(w).toString().toCharArray();
        int ll = c.length;
        for (int j = 0; j < Math.min(m, ll); ++j) {
          ret += (c[ll - 1 - j] - '0') * (c[ll - 1 - j] - '0');
        }
        System.out.println(ret);
        l = l.add(BigInteger.ONE);
        ++po;
        }
     }
    }
}

