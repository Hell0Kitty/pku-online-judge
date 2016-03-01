import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * poj2389
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            BigInteger a = scan.nextBigInteger();
            BigInteger b = scan.nextBigInteger();
            System.out.println(a.multiply(b));
        }
    }
}

