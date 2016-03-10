import java.io.*;
import java.util.*;

public class Main {

    private static final int        MAX_N = 100000;

    private static BufferedReader   in =new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer  st;
    private static int[]            height = new int[MAX_N];
    private static long[]           width = new long[MAX_N + 1];
    private static long[]           area = new long[MAX_N + 1];
    private static int[]            l = new int[MAX_N], r = new int[MAX_N];
    private static int[]            stack = new int[MAX_N + 1];
    private static int[]            min = new int[MAX_N], max = new int[MAX_N];
    private static long[]           base = new long[MAX_N];
    private static boolean[]        used = new boolean[MAX_N];
    private static long[]           result = new long[MAX_N];
    private static int              N, pos, root;

    public static void main(String[] argv) throws Exception {
        readIn();
        solve();
    }

    private static void readIn() throws Exception {
        int top = 0, minH = Integer.MAX_VALUE;
        int i, x;
        N = nextInt();
        width[0] = area[0] = 0;
        for (i = 0; i < N; i++) {
            x = nextInt();
            height[i] = nextInt();
            width[i + 1] = width[i] + x;
            area[i + 1] = area[i] + (long) x * height[i];
            if (height[i] < minH) {
                minH = height[i];
                pos = i;
            }
            for (stack[top] = -1; top > 0 && height[stack[top - 1]] < height[i]; top--);
            if (top > 0) {
                r[stack[top - 1]] = i;
            }
            l[i] = stack[top] != -1 ? stack[top] : -1;
            r[i] = -1;
            stack[top++] = i;
        }
        root = stack[0];
    }

    private static void solve() {
        int top = 0;
        int i, x, y;
        stack[top++] = root;
        min[root] = 0; max[root] = N;
        base[root] = 0;
        while (top > 0) {
            x = stack[top - 1];
            if (!used[x]) {
                result[x] = base[x] + (width[max[x]] - width[min[x]]) * (height[x] + 1) -
                       area[max[x]] + area[min[x]];
                used[stack[top - 1]] = true;
            }
            if ((y = getChild(x)) == 0) {
                top--;
            } else if (y < 0) {
                stack[top++] = l[x];
                min[l[x]] = min[x]; max[l[x]] = x;
                base[l[x]] = base[x] + (pos > x ? (width[max[x]] - width[x + 1]) * height[x] -
                        area[max[x]] + area[x + 1] : 0);
            } else {
                stack[top++] = r[x];
                min[r[x]] = x + 1; max[r[x]] = max[x];
                base[r[x]] = base[x] + (pos < x ? (width[x] - width[min[x]]) * height[x] -
                        area[x] + area[min[x]] : 0);
            }
        }
        for (i = 0; i < N; i++) {
            System.out.println(result[i]);
        }
    }

    private static int getChild(int x) {
        if (l[x] != -1 && !used[l[x]]) {
            return -1;
        } else if (r[x] != -1 && !used[r[x]]) {
            return 1;
        }
        return 0;
    }

    private static int nextInt() throws Exception {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(in.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

}

