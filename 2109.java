
import java.math.BigInteger;
import java.util.Scanner;

public class Main {

  static final BigInteger TWO = new BigInteger("2");
  static final BigInteger ONE = BigInteger.ONE;

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    // k^n=p findK;
    BigInteger p;
    int n;
    BigInteger ks, kl;
    while (in.hasNextInt()) {
      boolean find = false;
      n = in.nextInt();
      p = in.nextBigInteger();
      ks = ONE;
      kl = p;
      while (ks.compareTo(kl) <= 0) {
        BigInteger mid = ks.add(kl).divide(TWO);
        int ret = mid.pow(n).compareTo(p);
        if (ret == 0) {
          find = true;
          System.out.println(mid);
          break;
        } else if (ret == -1) {
          ks = mid.add(ONE);
        } else {
          kl = mid.subtract(ONE);
        }
      }
      if (!find) {
        System.out.println(ks.subtract(ONE));
      }
    }
  }
}