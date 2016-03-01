import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final int MAXSIZE = 50001;
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        int caseI = 1;
        int max = 0;
        while (scan.hasNext()) {
            int n = scan.nextInt();
            int m = scan.nextInt();
            if (n == 0 && m == 0) {
                break;
            }
            DisjointSet dj = new DisjointSet(MAXSIZE);
            int count = 0;
            for (int i = 0; i < m; i++) {
                int a = scan.nextInt();
                int b = scan.nextInt();
                int ra = dj.find(a);
                int rb = dj.find(b);
                if (ra != rb) {
                    dj.union(ra, rb);
                    count++;
                }
            }
            max = n - count;
            String result = "Case " + caseI + ": " + max;
            System.out.println(result);
            caseI++;
        }
    }
}

class DisjointSet {

    protected int n;
    protected int[] parent;
    protected int[] rank;

    public DisjointSet(int n) {
        this.n = n;
        init(n);
    }

    protected void init(int n) {
        this.parent = new int[this.n + 1];
        this.rank = new int[this.n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    protected int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    protected void union(int ra, int rb) {
        if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        } else if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        } else {
            rank[rb]++;
            parent[ra] = rb;
        }
    }
}


