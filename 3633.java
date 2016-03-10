import java.io.*;
import java.util.*;

public class Main {

    private static final int        MAX_N = 18;

    private static BufferedReader   in =
        new BufferedReader(new InputStreamReader(System.in));
    private static char[]           s, t, sr;
    private static int[]            matchs, matchsr;
    private static int[]            hash = new int[1 <<  MAX_N];

    public static void main(String[] argv) throws Exception {
        for(int caseSize = Integer.parseInt(in.readLine()); caseSize > 0; caseSize--){
            if (!readIn()) {
                System.out.println("impossible");
            } else {
                System.out.println(solve(0));
            }
        }
    }

    private static boolean readIn() throws Exception {
        String  S = in.readLine(), T = in.readLine();
        int     i;
        if ((!S.contains("A") && T.contains("A")) || (!S.contains("C") && T.contains("C")) ||
                (!S.contains("G") && T.contains("G")) || (!S.contains("T") && T.contains("T"))) {
            return false;
        }
        s = S.toCharArray();
        t = T.toCharArray();
        sr = new char[s.length];
        matchs = new int[t.length];
        matchsr = new int[t.length];
        Arrays.fill(hash, Integer.MAX_VALUE);
        hash[(1 <<  t.length) - 1] = 0;
        reverse(s, sr);
        for (i = 0; i <  t.length; i++) {
            matchs[i] = longestMatch(i, t.length, s);
            matchsr[i] = longestMatch(i, t.length, sr);
        }
        return true;
    }

    private static void reverse(char[] a, char[] ar) {
        for (int i = 0; i < a.length; i++) {
            ar[i] = a[a.length - i - 1];
        }
    }

    private static int longestMatch(int from, int to, char[] a) {
        int i, len, max = 0;
        for (i = 0, len = 0; i < a.length; i++, len = 0) {
            while (len < to - from && i + len < a.length && a[i + len] == t[from + len]) {
                len++;
            }
            max = Math.max(max, len);
        }
        return max;
    }

    private static int solve(int state) {
        if (hash[state] != Integer.MAX_VALUE) {
            return hash[state];
        }
        char[] done = new char[t.length];
        char[] doner = new char[t.length];
        int i, m = 0, len, g;
        for (i = 0; i < done.length; i++) {
            done[i] = (state & (1 << i)) != 0 ? t[i] : '0';
        }
        reverse(done, doner);
        for(i = 0; i < t.length; i++) {
            if ((state & (1 << i)) != 0) {
                m = 0;
                continue;
            }
            len = 1;
            while (i + len < t.length && (state & (1 << (i + len))) == 0) {
                len++;
            }
            g = Math.min(len, Math.max(matchs[i], matchsr[i]));
            g = Math.max(g, longestMatch(i, i + len, done));
            g = Math.max(g, longestMatch(i, i + len, doner));
            if(g > m - 1) {
                hash[state] = Math.min(hash[state], 1 + solve(state | ((1 << (i + g)) - (1 << i))));
            }
            m = g;
        }
        return hash[state];
    }

}

