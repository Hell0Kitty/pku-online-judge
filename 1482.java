import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

class Node implements Comparable<Node> {
    int t;
    int sb, sp;
    int eb, ep;
    public int compareTo(Node arg0) {
        return (t - arg0.t);
    }
}

class QNode implements Comparable<QNode> {
    int state;
    int t;
    public QNode() {}
    public QNode(QNode tt) {
        t = tt.t;
        state = tt.state;
    }
    public int compareTo(QNode arg0) {
        return (t - arg0.t);
    }
}

public class Main {
    int m, n;
    int hash[] = new int[1 << 20];
    Node bug[];
    
    int bfs() {
        PriorityQueue<QNode> q = new PriorityQueue<QNode>(1 << 10);
        int ans = -1;
        QNode cur, now;
        cur = new QNode();
        cur.t = 0;
        cur.state = 0;
        cur.state = (1<<n)-1;
        hash[cur.state] = 0;
        q.offer(cur);
        while (!q.isEmpty()) {
            cur = q.poll();
            if (cur.state == 0) {
                ans = cur.t;
                break;
            }
            for (int i = 0; i < m; i++) {
                if ((~cur.state & bug[i].sp) == 0
                        && (cur.state & bug[i].sb) == 0) {
                    now = new QNode(cur);
                    now.state |= bug[i].ep;
                    now.state &= (~bug[i].eb);
                    now.t += bug[i].t;
                    if ((hash[now.state] == -1) || (hash[now.state] > now.t)) {
                        hash[now.state] = now.t;
                        q.offer(now);
                    }
                }
            }
        }
        while (!q.isEmpty())
            q.poll();
        return ans;
    }

    void solve() throws IOException {
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
       // BufferedReader cin = new BufferedReader(new FileReader(new File("in")));
        String read;
        int k = 0;
        while ((read = cin.readLine()) != null) {
            n = Integer.parseInt(read.split(" ")[0]);
            m = Integer.parseInt(read.split(" ")[1]);
            if (m + n == 0)
                break;
            bug = new Node[m];
            for (int i = 0; i < m; i++) {
                read = cin.readLine();
                bug[i] = new Node();
                bug[i].t = Integer.parseInt(read.split(" ")[0]);
                String tmp = read.split(" ")[1];
                for (int j = 0; j < n; j++) {
                    if (tmp.charAt(j) == '-')
                        bug[i].sb |= 1 << (n - j - 1);
                    if (tmp.charAt(j) == '+')
                        bug[i].sp |= 1 << (n - j - 1);
                }
                tmp = read.split(" ")[2];
                for (int j = 0; j < n; j++) {
                    if (tmp.charAt(j) == '-')
                        bug[i].eb |= 1 << (n - j - 1);
                    if (tmp.charAt(j) == '+')
                        bug[i].ep |= 1 << (n - j - 1);
                }
                //System.out.println(bug[i].sb+" "+bug[i].sp+" "+bug[i].eb + " "+bug[i].ep);
            }
            Arrays.sort(bug);
            Arrays.fill(hash, -1);
            int ans = bfs();
            System.out.println("Product " + ++k);
            if (ans == -1)
                System.out.println("Bugs cannot be fixed.");
            else
                System.out.println("Fastest sequence takes " + ans + " seconds.");
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        Main test = new Main();
        test.solve();
    }
}