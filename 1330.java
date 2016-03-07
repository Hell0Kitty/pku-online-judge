import java.util.*;

@SuppressWarnings("unchecked")
public class Main {
    int MAX = 10001;
    Vector<Integer> tree[] = new Vector[MAX + 1];; // 树结构
    byte[] flag = new byte[MAX]; // 入度标志，用于寻找根节点
    int parent[] = new int[MAX];;
    int rank[] = new int[MAX];;
    int ancestor[] = new int[MAX];
    int visited[] = new int[MAX];
    StringBuilder sb = new StringBuilder();
    byte ret;
    {
        for (int i = 1; i < MAX; i++)
            tree[i] = new Vector<Integer>();
    }

    public static void main(String[] args) {
        Main poj = new Main();
        java.util.Scanner s = new java.util.Scanner(System.in);
        int test = s.nextInt();
        int i = 0;
        while (++i <= test) {
            int length = s.nextInt();
            poj.initial(length);
            int a;
            int b;
            for (int j = 1; j < length; j++) {
                a = s.nextInt();
                b = s.nextInt();
                poj.flag[b] = -1;
                poj.tree[a].add(b);
            }
            int root;
            for (root = 1; root <= length; root++)
                if (poj.flag[root] != -1)
                    break;
            a = s.nextInt();
            b = s.nextInt();
            poj.LCA(root, a, b);
        }
        System.out.print(poj.sb.toString());
    }

    void initial(int n) {
        ret = 1;

        for (int i = 1; i <= n; i++) {
            flag[i] = 0;
            parent[i] = i;
            rank[i] = 0;
            ancestor[i] = 0;
            visited[i] = 0;
            tree[i].clear();

        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        else
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b)
            return;
        if (rank[a] < rank[b])
            parent[a] = b;
        else if (rank[a] > rank[b])
            parent[b] = a;
        else {
            parent[a] = b;
            rank[b]++;
        }
    }

    void LCA(int u, int x, int y) {
        ancestor[u] = u;
        for (int i = 0; i < tree[u].size(); i++) {
            LCA(tree[u].get(i), x, y);
            if (ret == 0)
                return;
            union(u, tree[u].get(i));
            ancestor[find(u)] = u;
        }
        visited[u] = 1;

        if (u == x && visited[y] == 1 && ret == 1) {

            sb.append(ancestor[find(y)]);
            sb.append('\n');
            ret = 0;
            return;
        }
        if (u == y && visited[x] == 1 && ret == 1) {
            {

                sb.append(ancestor[find(x)]);
                sb.append('\n');
                ret = 0;
                return;
            }
        }
    }
}