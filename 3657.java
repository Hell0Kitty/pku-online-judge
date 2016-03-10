import java.io.*;
import java.util.*;

public class Main {

    private static final int        MAX_N = 25000;

    private static BufferedReader   in =
            new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer  st;
    private static int[][]          que = new int[MAX_N][3];
    private static int[]            x = new int[2 * MAX_N];
    private static Integer[]        list = new Integer[MAX_N];
    private static int[]            r = new int[2 * MAX_N];
    private static boolean[]        used = new boolean[2 * MAX_N];
    private static int              N, xSize;

    public static void main(String[] argv) throws Exception {
        readIn();
        solve();
    }

    private static void readIn() throws Exception {
        int i, temp;
        nextInt();
        N = nextInt();
        for (xSize = 0, i = 0; i < N; i++) {
            que[i][0] = x[xSize++] = nextInt();
            que[i][1] = x[xSize++] = nextInt() + 1;
            que[i][2] = nextInt();
            list[i] = i;
        }
        Arrays.sort(x, 0, xSize);
        for (temp = xSize, xSize = i = 1; i < temp; i++) {
            if (x[i] != x[i - 1]) {
                x[xSize++] = x[i];
            }
        }
        for (i = 0; i < N; i++) {
            que[i][0] = Arrays.binarySearch(x, 0, xSize, que[i][0]);
            que[i][1] = Arrays.binarySearch(x, 0, xSize, que[i][1]);
        }
        Arrays.sort(list, 0, N, new Comparator(){
            public int compare(Integer a, Integer b) {
                return que[a][2] < que[b][2] ? 1 : -1;
            }
        });
    }

    private static void solve() {
        int min = 0, max = N - 1, mid;
        while (min < max) {
            mid = (min + max + 1) / 2;
            if (check(mid)) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        if (min == N - 1) {
            System.out.println(0);
        } else {
            System.out.println(min + 2);
        }
    }

    private static boolean check(int pos) {
        int     i, j, x, min, max;
        boolean found;
        for (i = 0; i < xSize - 1; i++) {
            r[i] = -1;
            used[i] = false;
        }
        for (i = 0; i < N; i++) {
            x = list[i];
            if (i == 0 || que[x][2] != que[list[i - 1]][2]) {
                min = Integer.MIN_VALUE;
                max = Integer.MAX_VALUE;
                for (j = i; j < N && que[list[j]][2] == que[x][2]; j++) {
                    if (list[j] <= pos) {
                        min = Math.max(min, que[list[j]][0]);
                        max = Math.min(max, que[list[j]][1]);
                    }
                }
                if (min != Integer.MIN_VALUE) {
                    for (found = false, j = min; j < max; j++) {
                        if (!used[j]) {
                            used[j] = found = true;
                            insert(j);
                        }
                        j = find(j);
                    }
                    if (!found) {
                        return false;
                    }
                }
            }
            if (x <= pos) {
                for (j = que[x][0]; j < que[x][1]; j++) {
                    if (!used[j]) {
                        used[j] = true;
                        insert(j);
                    }
                    j = find(j);
                }
            }
        }
        return true;
    }

    private static void insert(int pos) {
        if (pos > 0 && used[pos - 1]) {
            r[pos - 1] = pos;
        }
        if (pos < xSize - 2 && used[pos + 1]) {
            r[pos] = find(pos + 1);
        }
    }

    private static int find(int x) {
        int y = x, z;
        while (r[y] != -1) {
            y = r[y];
        }
        while (x != y) {
            z = x;
            x = r[x];
            r[z] = y;
        }
        return y;
    }

    private static int nextInt() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

}

