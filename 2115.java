import java.io.*;
import java.util.*;
import java.math.*;

 public class Main {

  static long x, y;

  long exGCD(long a, long b) {
   if (b == 0) {
    x = 1;
    y = 0;
    return a;
   }
   long r = exGCD(b, a % b);
   long t = x;
   x = y;
   y = t - a / b * y;
   return r;
  }

  long moduler_linear(long a, long b, long n) {
    long d = exGCD(a, n);
    if (b % d != 0) return -1;
    long e = x * (b / d) % n + n;
    return e % (n / d);
   }

  void run() {
   long a, b, c, k;
   while (true) {
    a = cin.nextInt();
    b = cin.nextInt();
    c = cin.nextInt();
    k = cin.nextInt();
    if (a == 0 && b == 0 && c == 0 && k == 0)
      break;

    long t = moduler_linear(c, b - a, 1L < <  k);
    if (t == -1) System.out.println("FOREVER");
    else System.out.println(t);
  }
 }

  public static void main(String[] args) {
   Main solved = new Main();
   solved.run();
  }

  // static InputStream inputStream = System.in;
  // static InputReader cin = new InputReader(inputStream);

  Scanner cin = new Scanner(new BufferedInputStream(System.in));
 }

