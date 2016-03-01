import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * poj2413
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            BigInteger a = scan.nextBigInteger();
            BigInteger b = scan.nextBigInteger();
            if (a.compareTo(BigInteger.ONE) == -1 && b.compareTo(BigInteger.ONE) == -1) {
                break;
            }
            int count = 0;
            BigInteger[] f = new BigInteger[1000000];
            f[0] = BigInteger.ONE;
            f[1] = BigInteger.ONE.add(BigInteger.ONE);
            for (int i = 0; i < f.length; i++) {
                if (i >= 2) {
                    f[i] = f[i - 1].add(f[i - 2]);
                }
                if (f[i].compareTo(b)==1) {
                    break;
                }
                if (!(f[i].compareTo(a)==-1)) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}

