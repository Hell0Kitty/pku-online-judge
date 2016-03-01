import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * Poj2390
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
        int r = scan.nextInt();
        long m = scan.nextLong();
        int y = scan.nextInt();
        double s = m;
        for(int i = 1;i<=y;i++){
            s=s*(r/100.0+1);
        }
            System.out.println((long)(Math.floor(s)));
    }
    }
}

