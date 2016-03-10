//* @author:
import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static ArrayList< Integer> primes = Prime.getPrimes(1120);

    public static void main(String[] args) {
        int[][] f = new int[1140][1140];
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        f[0][0] = 1;
        for (int j = 0; j < primes.size(); j++) {
        for (int i = 14; i >= 1; i--) {
               for (int v = 1120; v > 0; v--) {
                    if (v - primes.get(j) >= 0) {
                        f[i][v] += f[i - 1][v - primes.get(j)];
                    }
                }
            }
        }
        while (scan.hasNext()) {
            int n = scan.nextInt();
            int k = scan.nextInt();
            if (n == 0 && k == 0) {
                break;
            }
            System.out.println(f[k][n]);
        }
    }
}

class Prime {

    public static ArrayList getPrimes(int n) {
        int i, j, k, x, num;
        n++;
        n /= 2;
        int[] b = new int[(n + 1) * 2];
        ArrayList a = new ArrayList();
        a.add(0, 2);
        a.add(1, 3);
        num = 2;
        for (i = 1; i <= 2 * n; i++) {
            b[i] = 0;
        }
        for (i = 3; i <= n; i += 3) {
            for (j = 0; j < 2; j++) {
                x = 2 * (i + j) - 1;
                while (b[x] == 0) {
                    a.add(num++, x);
                    for (k = x; k <= 2 * n; k += x) {
                        b[k] = 1;
                    }
                }
            }
        }
        return a;
    }
}

