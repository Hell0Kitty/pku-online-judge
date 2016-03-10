import java.io.BufferedInputStream;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static final int MAX = 200000;

    public static void main(String[] args) {

        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            int n = scan.nextInt();
            int k = scan.nextInt();
            System.out.println(catchTheCow(n, k));
        }
    }

    public static int catchTheCow(int n, int k) {
        if (n == k) {
            return 0;
        }
        LinkedList queue = new LinkedList();
        boolean[] visited = new boolean[MAX + 5];
        int[] minutes = new int[MAX + 5];
        visited[n] = true;
        queue.add(n);
        while (!queue.isEmpty()) {
            int current = queue.removeFirst();
            for (int i = 0; i < 3; i++) {
                int next = current;
                if (i == 0) {
                    next++;
                } else if (i == 1) {
                    next--;
                } else if (i == 2) {
                    next <<= 1;
                }
                if (next < 0 || next > MAX) {
                    continue;
                }
                if (!visited[next]) {
                    queue.add(next);
                    visited[next] = true;
                    minutes[next] = minutes[current] + 1;
                }
                if (next == k) {
                    return minutes[k];
                }
            }
        }

        return 0;
    }
}

