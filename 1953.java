import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            long[] f = new long[46];
            f[0] = 0;
            f[1] = 2;
            f[2] = 3;
            for (int i = 3; i <= 45; i++) {
                f[i] = f[i - 1] + f[i - 2];
            }
            int n = scan.nextInt();
            for (int i = 1; i <= n; i++) {
                int a = scan.nextInt();
                System.out.println("Scenario #"+i+":");
                System.out.println(f[a]);
                System.out.println();
            }

        }
    }
}

