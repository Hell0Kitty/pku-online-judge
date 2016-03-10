 import java.io.BufferedReader;
 import java.io.InputStreamReader;
 import java.math.BigInteger;

 public class Main {

     static long[] arr = new long[] { 0, 0, 1, 2, 6, 11, 27, 49, 113, 206, 462,
             848, 1872, 3458, 7554, 14030, 30414, 56747, 122283, 229045, 491189,
             923099, 1971675, 3716111, 7910415, 14946945, 31724161, 60078293,
             127187157, 241346585, 509782041, 969094193, 2042836017 };

     public static void main(String[] args) throws Exception {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String[] s = read.readLine().split(" ");
         int a = Integer.parseInt(s[0]);
         int b = Integer.parseInt(s[1]);
         System.out.println(jisuan(b) - jisuan(a - 1));
     }

     public static long jisuan(int a) {
         String bi = Integer.toBinaryString(a);
         long sum = arr[bi.length() - 1];
         char[] ci = bi.toCharArray();
         int c0 = 0;
         int c1 = 1;
         int temp, top, mid;
         if (ci.length % 2 == 0) {
             mid = ci.length / 2;
         } else {
             mid = ci.length / 2 + 1;
         }
         for (int i = 1; i < ci.length; i++) {
             if (ci[i] == '0') {
                 c0++;
             } else {
                 temp = mid - (c0 + 1);
                 if (temp < 0) {
                     temp = 0;
                 }
                 top = ci.length - i - 1;
                 for (int j = temp; j <= top; j++) {
                     sum += c(top, j);
                 }
                 c1++;
             }
         }
         if (c0 >= c1) {
             sum++;
         }
         return sum;
     }

     public static long c(int m, int n) {
         BigInteger sub = new BigInteger("1");
         BigInteger div = new BigInteger("1");
         for (int i = 1; i <= n; i++) {
             sub = sub.multiply(new BigInteger(i + ""));
         }
         for (int i = m; i >= m - n + 1; i--) {
             div = div.multiply(new BigInteger(i + ""));
         }
         return div.divide(sub).longValue();
     }
}

