//* @author:alpc12
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        new Main().run();
    }

    int[] f;
    int[] dp;

    int Root(int x) {
        if(f[x] == x)
            return x;
        return f[x] = Root(f[x]);
    }

    private class Node implements Comparable {
        int p, d;

        public Node() {
            super();
        }

        public Node(int p, int d) {
            super();
            this.p = p;
            this.d = d;
        }

        public int compareTo(Object arg0) {
            return -(p-((Node)arg0).p);
        }
    }

    private void run() throws FileNotFoundException {
         Scanner cin = new Scanner(System.in);

        while(cin.hasNextInt()) {
            int n = cin.nextInt();
            int l = cin.nextInt();

            Node p[] = new Node[n];
            int max = 0;
            for(int i = 0; i < n; ++i) {
                p[i] = new Node(cin.nextInt(), cin.nextInt());
                p[i].d++;
                p[i].d *= l;
                max = Math.max(max, p[i].d);
            }
            max++;
            Arrays.sort(p);

            f = new int[max];
            for(int i = 0; i < max; ++i) f[i] = i;

            int sum = 0;
            for(int i = 0; i < n; ++i) {
                int x = p[i].d;

                int r = Root(x);
                if(r != 0) {
                    f[r] = r-1;
                    sum += p[i].p;

                }
            }
            System.out.println(sum);

        }

    }

}

