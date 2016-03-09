import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main{

    private static final int MAXLEN = 101;
    private static int[][] c = new int[MAXLEN][MAXLEN];
    private static int[][] b = new int[MAXLEN][MAXLEN];

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));


        while (scan.hasNext()) {
            String s1 = "", s2 = "";
            while (scan.hasNext()) {
                String s = scan.nextLine();
                if (s.startsWith("#")) {
                    break;
                }
                s.trim();
                s1 = s1 + s + " ";
            }
            while (scan.hasNext()) {
                String s = scan.nextLine();
                if (s.startsWith("#")) {
                    break;
                }
                s.trim();
                s2 = s2 + s + " ";
            }
            String[] ss1 = s1.trim().split(" ");
            String[] ss2 = s2.trim().split(" ");
            lcsLength(ss1, ss2);
            printLCS(ss1, ss1.length, ss2.length);
        }
    }

    public static void lcsLength(String[] x, String[] y) {
        for (int i = 0; i <= x.length; i++) {
            c[i][0] = 0;
        }
        for (int i = 0; i <= y.length; i++) {
            c[0][i] = 0;
        }
        for (int i = 1; i <= x.length; i++) {
            for (int j = 1; j <= y.length; j++) {
                if (x[i - 1].equals(y[j - 1])) {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = 0;
                } else if (c[i - 1][j] >= c[i][j - 1]) {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 1;
                } else {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = -1;
                }
            }
        }
    }

    public static void printLCS(String[] x, int m, int n) {
        int i = m;
        int j = n;
        if (i == 0 || j == 0) {
            return;
        }
        if (b[i][j] == 0) {
            printLCS(x, i - 1, j - 1);
            System.out.print(x[i - 1] + " ");
        } else if (b[i][j] == 1) {
            printLCS(x, i - 1, j);
        } else {
            printLCS(x, i, j - 1);
        }
    }
}

