import java.io.BufferedInputStream;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
public class Main {

    static int[][] field = new int[1001][1001];
    static int y;
    static int n;
    static int x;

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        x = scan.nextInt();
        y = scan.nextInt();
        n = scan.nextInt();
        field[x + 500][y + 500] = 1;
        for (int i = 0; i < n; i++) {
            int a = scan.nextInt();
            int b = scan.nextInt();
            field[a + 500][b + 500] = -1;
        }
        solve();
    }

    public static void solve() {
        System.out.println(bsf(500, 500));
    }
    public static int bsf(int r, int c) {

        LinkedList< Point> queue = new LinkedList();
        queue.add(new Point(r, c, 0));
        field[r][c] = -1;

        while (!queue.isEmpty()) {
            Point current = queue.removeFirst();
            int ai = current.a;
            int bi = current.b;

            if (ai - 1 >= 0 && field[ai - 1][bi] == 0) {
                queue.addLast(new Point(ai - 1, bi, current.step + 1));
                field[ai - 1][bi] = -1;
            } else if (field[ai - 1][bi] == 1) {
                return current.step + 1;
            }

            if (ai + 1 <= 1000 && field[ai + 1][bi] == 0) {
                queue.addLast(new Point(ai + 1, bi, current.step + 1));
                field[ai + 1][bi] = -1;
            } else if (field[ai + 1][bi] == 1) {
                return current.step + 1;
            }
            if (bi - 1 >= 0 && field[ai][bi - 1] == 0) {
                queue.addLast(new Point(ai, bi - 1, current.step + 1));
                field[ai][bi - 1] = -1;
            } else if (field[ai][bi - 1] == 1) {
                return current.step + 1;
            }

            if (bi + 1 <= 1000 && field[ai][bi + 1] == 0) {
                queue.addLast(new Point(ai, bi + 1, current.step + 1));
                field[ai][bi + 1] = -1;
            } else if (field[ai][bi + 1] == 1) {
                return current.step + 1;
            }
        }
        return 0;
    }
}

class Point {

    int a = 0;
    int b = 0;
    int step = 0;

    public Point(int a, int b, int step) {
        this.a = a;
        this.b = b;
        this.step = step;
    }
}

