 import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 *poj3752
 * 模拟
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            int m = scan.nextInt();
            int n = scan.nextInt();
            int num = m * n;
            int[][] letter = new int[m][n];
            for (int i = 0; i < letter.length; i++) {
                for (int j = 0; j < letter[i].length; j++) {
                    letter[i][j] = -1;
                }
            }
            int i = 0, j = 0;
            int count = 0;
            if (m != 1 && n != 1) {
                while (true) {
                    if (letter[i][j] != -1) {
                        break;
                    }
                    for (int k = 0; k < n; k++) {
                        letter[i][j + k] = count;
                        count++;
                    }
                    j = j + n - 1;
                    if (m != 1) {
                        for (int k = 1; k < m - 1; k++) {
                            letter[i + k][j] = count;
                            count++;
                        }
                        i = i + m - 1;

                        for (int k = 0, c = 0; c < n; k--, c++) {
                            letter[i][j + k] = count;
                            count++;
                        }
                        j = j - n + 1;
                        for (int k = -1, c = 1; c < m - 1; c++, k--) {
                            letter[i + k][j] = count;
                            count++;
                        }
                        i = i - m + 2;//这里不一样
                    }
                    j = j + 1;
                    m = m - 2;
                    n = n - 2;
                }
            } else if (m == 1 && n == 1) {
                letter[0][0] = 0;
            } else if (m == 1) {
                for (int k = 0; k < n; k++) {
                    letter[0][k] = k;
                }
            } else {
                for (int k = 0; k < m; k++) {
                    letter[k][0] = k;
                }
            }
            for (int k = 0; k < letter.length; k++) {
                for (int v = 0; v < letter[k].length; v++) {
                    char ch = (char) (letter[k][v] % 26 + 'A');
                    System.out.print("   " + ch);
                }
                System.out.println();
            }
        }

    }
}

