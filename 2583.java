import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *poj2583 easy
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            int f0 = scan.nextInt();
            int f1 = scan.nextInt();
            int f2 = scan.nextInt();
            int c = f0;
            int a = (f2 - 2 * f1 + f0) / 2;
            int b = f1 - c - a;
            int f3 = a * 9 + b * 3 + c;
            int f4 = a * 16 + b * 4 + c;
            int f5 = a * 25 + b * 5 + c;
            System.out.println(f3 + " " + f4 + " " + f5);
        }

    }
}


