import java.io.*;
import java.util.*;

public class Main {

    private static BufferedReader   in =new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer  st;
    private static double[] x = new double[10], y = new double[10];
    private static double[] d = new double[20];
    private static double   x0, y0;
    private static int      N;
    private static double   R;

    public static void main(String[] argv) throws Exception {
        while (in.ready()) {
            N = nextInt();
            R = nextDouble();
            x0 = nextDouble();
            y0 = nextDouble();
            for (int i = 0; i < N; i++) {
                x[i] = nextDouble();
                y[i] = nextDouble();
            }
            solve();
        }
    }

    private static void solve() {
        double  a, b, c, delta, t1, t2, a0, a1, b0, b1, x1, y1;
        for (int i = 0; i < N; i++) {
            if (doubleCmp(x[i], x0) == 0 && doubleCmp(y[i], y0) == 0) {
                System.out.println("No");
                return;
            }
            a0 = x[i] - x0;
            b0 = y[i] - y0;
            x1 = x0 + a0 / 2;
            y1 = y0 + b0 / 2;
            a1 = -b0;
            b1 = a0;
            a = sqr(a1) + sqr(b1);
            b = 2 * a1 * x1 + 2 * b1 * y1;
            c = sqr(x1) + sqr(y1) - sqr(R);
            delta = Math.sqrt(sqr(b) - 4 * a * c);
            t1 = (-b + delta) / 2 / a;
            t2 = (-b - delta) / 2 / a;
            d[2 * i] = Math.atan2(y1 + t1 * b1, x1 + t1 * a1);
            d[2 * i + 1] = Math.atan2(y1 + t2 * b1, x1 + t2 * a1);
        }
        Arrays.sort(d, 0, 2 * N);
        for (int i = 0; i < 2 * N; i++)
            if (check(d[i], d[(i + 1) % (2 * N)])) {
                System.out.println("Yes");
                return;
            }
        System.out.println("No");
    }

    private static boolean check(double xt, double yt) {
        if (yt < xt) yt += 2 * Math.PI;
        xt = (xt + yt) / 2;
        yt = R * Math.sin(xt);
        xt = R * Math.cos(xt);
        for (int i = 0; i < N; i++)
            if (doubleCmp(dist(x[i], y[i], xt, yt), dist(x0, y0, xt, yt)) < 0) return false;
        return true;
    }

    private static double dist(double x1, double y1, double x2, double y2) {
        return Math.sqrt(sqr(x1 - x2) + sqr(y1 - y2));
    }

    private static int doubleCmp(double a, double b) {
        if (Math.abs(a - b) < 1e-6) return 0;
        return a < b ? -1 : 1;
    }

    private static double sqr(double x) {
        return x * x;
    }

    private static int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    private static double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }

    private static String next() throws Exception {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(in.readLine());
        return st.nextToken();
    }

}

