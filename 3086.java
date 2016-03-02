import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 * @author NC
 * Poj3086
 */
public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        int n = scan.nextInt();
        for (int i = 1; i <= n; i++) {
            int kk = scan.nextInt();
            if (kk == 1) {
                System.out.println(i + " 1 3");
                continue;
            }
            int sum = 0;
            int t = 1;
            for (int j = 2; j <= kk + 1; j++) {
                t += j;
                sum += (j - 1) * t;
            }
            System.out.println(i + " " + kk + " " + sum);
        }
    }
}

