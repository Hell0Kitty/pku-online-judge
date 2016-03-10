import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader   in = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer  st;
    private static int[] matrix = new int[300];

    public static void main(String[] argv) throws Exception {
        int  N, M;
        int  i, j, x;
        boolean found;
        while (in.ready()) {
            N = nextInt();
            M = nextInt();
            Arrays.fill(matrix, 0);
            for (i = 0; i < N; i++)
                for (j = 0; j < M; j++)
                    if (nextInt() == 1)
                        matrix[j] |= 1 <<  i;
            for (found = false, i = (1 <<  N) - 1; !found && i >= 0; i--) {
                for (j = 0; j < M; j++) {
                    x = i & matrix[j];
                    if (x == 0 || x - (x & (-x)) != 0) break;
                }
                if (j == M) {
                    found = true;
                    System.out.println("Yes, I found it");
                }
            }
            if (!found) System.out.println("It is impossible");
        }
    }

    private static int nextInt() throws Exception {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return Integer.parseInt(st.nextToken());
    }

}

