import java.util.*;

public class Main {

    static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println("Scenario #" + (i + 1) + ":");
            solve();
            System.out.println();
        }
    }

    public static void solve() {
        int originRow, originCol, n;
        n = originRow = originCol = in.nextInt();
        char[][][] point = new char[n + 1][n + 1][2 * n + 1];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n + 1; j++) {
                for (int k = 0; k < 2 * n + 1; k++) {
                    point[i][j][k] = '.';
                }
            }
        }

        for (int i = 0; i < n + 1; i++) {
            for (int j = originRow - i; j <= originRow; j++) {
                int num = 0;
                for (int k = originCol - i + originRow - j; k <= originCol; k++) {
                    point[i][j][k] = (char) (n - num + '0');
                    num++;
                }
                num = 0;
                for (int k = originCol + i - originRow + j; k > originCol; k--) {
                    point[i][j][k] = (char) (n - num + '0');
                    num++;
                }
            }
        }
        print(point);
    }

    public static void print(char[][][] point) {
        int n = 0;
        for (int i = 0; i < point.length; i++) {
            n++;
            System.out.println("slice #" + n + ":");
            for (int j = 0; j < point[i].length; j++) {
                for (int k = 0; k < point[i][j].length; k++) {
                    System.out.print(point[i][j][k]);
                }
                System.out.println();
            }
            for (int j = point[i].length - 2; j >= 0; j--) {
                for (int k = 0; k < point[i][j].length; k++) {
                    System.out.print(point[i][j][k]);
                }
                System.out.println();
            }
        }
        for (int i = point.length - 2; i >= 0; i--) {
            n++;
            System.out.println("slice #" + n + ":");
            for (int j = 0; j < point[i].length; j++) {
                for (int k = 0; k < point[i][j].length; k++) {
                    System.out.print(point[i][j][k]);
                }
                System.out.println();
            }
            for (int j = point[i].length - 2; j >= 0; j--) {
                for (int k = 0; k < point[i][j].length; k++) {
                    System.out.print(point[i][j][k]);
                }
                System.out.println();
            }
        }
    }
}