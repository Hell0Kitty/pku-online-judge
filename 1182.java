import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Main poj = new Main();

        BufferedReader read = new BufferedReader(new InputStreamReader(
                System.in));
        String[] tm = read.readLine().split(" ");

        int N = new Integer(tm[0]);
        int K = new Integer(tm[1]);
        poj.initial(N);
        int i = 0;
        int count = 0;
        if (K == 0)
            System.out.println(count);
        while (++i <= K) {
            String[] tmp = read.readLine().split(" ");
            int kind = new Integer(tmp[0]);
            int animalA = new Integer(tmp[1]);
            int animalB = new Integer(tmp[2]);

            if (animalA > N || animalB > N) {
                count++;
                continue;
            }
            if (animalA == animalB) {
                if (kind == 2)
                    count++;
                continue;
            }
            int fa = poj.find(animalA);
            int fb = poj.find(animalB);

            if (fa == fb) {
                if (kind == 1) {
                    if (poj.mod[animalA] != poj.mod[animalB])
                        count++;
                } else {
                    if ((poj.mod[animalA] + 1) % 3 != poj.mod[animalB] % 3)
                        count++;
                }
            } else
                poj.union(animalA, animalB, kind);
        }
        read.close();
        System.out.println(count);
    }

    int[] parent;
    int[] mod;

    void union(int x, int y, int kind) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            if (mod[x] < mod[y]) {
                parent[fx] = fy;
                if (kind == 2)
                    mod[fx] = (mod[y] - mod[x] - 1 + 3) % 3;
                else
                    mod[fx] = (mod[y] - mod[x]) % 3;
            } else {
                parent[fy] = fx;
                if (kind == 2)
                    mod[fy] = (mod[x] - mod[y] + 1) % 3;
                else
                    mod[fy] = (mod[x] - mod[y]) % 3;
            }
        }

    }

    int find(int x) {
        if (x == parent[x])
            return parent[x];
        else {
            int t = parent[x];
            parent[x] = find(parent[x]);
            mod[x] = (mod[x] + mod[t]) % 3;
        }
        return parent[x];
    }

    void initial(int n) {
        parent = new int[n + 1];
        mod = new int[n + 1];
        for (int i = 1; i < n + 1; i++)
            parent[i] = i;
    }
}