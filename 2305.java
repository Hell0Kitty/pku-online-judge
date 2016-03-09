import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            int b = scan.nextInt();
            if (b == 0) {
                break;
            }
            BigInteger p = scan.nextBigInteger(b);
            BigInteger m = scan.nextBigInteger(b);
            System.out.println(p.mod(m).toString(b));
        }
    }
}


