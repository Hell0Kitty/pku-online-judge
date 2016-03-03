import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    private static String[] a = null;
    private static int max = -1;
    private static int n = 0;
    private static int m = 0;

    private static void dfs(int x, int y, char[] c, int current) {
        boolean find = false;
        for (int i = 0; i < current; i++) {
            if (c[i] == a[x].charAt(y)) {
                find = true;
                break;
            }
        }

        if (find) {
            max = Math.max(max, current);
            return;
        }

        c[current] = a[x].charAt(y);

        if (x - 1 >= 0) {
            dfs(x - 1, y, c, current + 1);
        }

        if (x + 1 < n) {
            dfs(x + 1, y, c, current + 1);
        }

        if (y - 1 >= 0) {
            dfs(x, y - 1, c, current + 1);
        }

        if (y + 1 < m) {
            dfs(x, y + 1, c, current + 1);
        }
    }

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        String[] temp = line.split("[ ]+");
        n = Integer.parseInt(temp[0]);
        m = Integer.parseInt(temp[1]);
        a = new String[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = stdin.readLine();
        }
        char[] c = new char[30];
        dfs(0, 0, c, 0);
        System.out.println(max);
    }
}
