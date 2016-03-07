import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.lang.Integer;

class Node {
    int x, mask;

    int s;

    int f;

    int action;

    public Node(int x, int mask, int s, int f, int aa) {
        this.x = x;
        this.mask = mask;
        this.s = s;
        this.f = f;
        this.action = aa;
    }
};

public class Main {

    int r, d, s;

    boolean[][] adj;

    boolean[][] ctr;

    int[][] dp;

    void run() throws Exception {
        Scanner cin = new Scanner(System.in);
        int tc = 0;
        while (true) {

            r = cin.nextInt();
            d = cin.nextInt();
            s = cin.nextInt();

            if (r == 0 && d == 0 && s == 0)
                break;
            System.out.printf("Villa #%d\n", ++tc);

            int i;
            adj = new boolean[r][r];
            ctr = new boolean[r][r];
            dp = new int[r][1 << r];

            for (i = 0; i < r; ++i) {
                Arrays.fill(dp[i], -1);
            }

            for (i = 0; i < d; ++i) {
                int x = cin.nextInt();
                int y = cin.nextInt();
                adj[x - 1][y - 1] = adj[y - 1][x - 1] = true;
            }

            for (i = 0; i < s; ++i) {
                int x = cin.nextInt();
                int y = cin.nextInt();
                ctr[x - 1][y - 1] = true;
            }

            List<Node> Q = new ArrayList<Node>();

            Q.add(new Node(0, 1, 0, -1, 0));
            Node now = new Node(0, 1, 0, -1, 0);
            dp[0][1] = 0;
            int lo = 0;
            while (lo < Q.size()) {
                now = Q.get(lo);
                int x = now.x, mask = now.mask, s = now.s;
//                System.out.println("" + now.x + " " + toBinary(now.mask) + " " + now.s);

                if (x == r - 1 && mask == (1 << (r - 1))) {
//                    System.out.println("Fitting Answer!");
                    break;
                }

                for (i = 0; i < r; ++i)
                    if (adj[x][i] && (mask & (1 << i)) != 0) {
                        if (dp[i][mask] == -1) {
                            dp[i][mask] = s + 1;
                            Q.add(new Node(i, mask, s + 1, lo, 0));
//                            System.out.println("Add " + i + " " + toBinary(now.mask) + " " + (now.s + 1));
                        }
                    }

                for (i = 0; i < r; ++i)
                    if (ctr[x][i]) {
                        if ((mask & (1 << i)) != 0 && i != x) {
                            if (dp[x][mask ^ (1 << i)] == -1) {
                                dp[x][mask ^ (1 << i)] = s + 1;
                                Q.add(new Node(x, mask ^ (1 << i), s + 1, lo, -i - 1));
//                                System.out.println("Add " + x + " " + toBinary(now.mask ^ (1 << i)) + " " + (now.s + 1));
                            }
                        } else {
                            if (dp[x][mask | (1 << i)] == -1) {
                                dp[x][mask | (1 << i)] = s + 1;
                                Q.add(new Node(x, mask | (1 << i), s + 1, lo, i + 1));
//                                System.out.println("Add " + x + " " + toBinary(now.mask | (1 << i)) + " " + (now.s + 1));
                            }
                        }
                    }
                lo++;
            }

            if (lo == Q.size()) {
                System.out.printf("The problem cannot be solved.\n");
            } else {
                System.out.printf("The problem can be solved in %d steps:\n", now.s);
                ArrayList<Integer> idxes = new ArrayList<Integer>();
                while (lo != -1) {
                    // System.out.println(lo);
                    idxes.add(lo);
                    lo = Q.get(lo).f;
                }
                for (i = idxes.size() - 2; i >= 0; --i) {
                    if (Q.get(idxes.get(i)).action == 0) {
                        System.out.printf("- Move to room %d.\n", Q.get(idxes.get(i)).x + 1);
                    } else if (Q.get(idxes.get(i)).action > 0) {
                        System.out.printf("- Switch on light in room %d.\n", Q.get(idxes.get(i)).action);
                    } else {
                        System.out.printf("- Switch off light in room %d.\n", -Q.get(idxes.get(i)).action);
                    }
                }
            }
            System.out.println();

        }
    }

    public static void main(String[] args) throws Exception {
        new Main().run();

    }

    private String toBinary(int x) {
        String now = Integer.toBinaryString(x);
        for (int i = 0; i < r - now.length(); ++i) {
            now = "0" + now;
        }
        return now;
    }

}
