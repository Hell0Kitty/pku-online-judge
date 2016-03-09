import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * Accepted. BigInteger is used here.
 *
 *
 */
public class Main {

     public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int n = cin.nextInt();

        int[][] a = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = 0;
            }
        }

        int[] depth = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            depth[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            while (true) {
                int k = cin.nextInt();

                if (k == 0) {
                    break;
                }

                a[i][k] = 1;
                depth[k]++;
            }
        }

        List list = new ArrayList();

        boolean[] picked = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            picked[i] = false;
        }

        while (list.size() < n) {

            for (int i = 1; i<= n; i++) {
                if (picked[i] == false && depth[i] == 0) {
                    list.add(i);
                    picked[i] = true;


                    for (int j = 1; j<= n; j++) {

                        if (picked[j] == false && a[i][j] == 1) {
                            depth[j]--;
                        }
                    }

                    break;
                }
            }
        }

        for (int i = 0; i < list.size(); i++) {

            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(list.get(i));
        }

        System.out.println();
    }


}

