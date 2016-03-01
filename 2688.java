import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;


class P {
    int x, y, id;
    P(){}
    P(int x, int y, int id) {
        this.x = x;
        this.y = y;
        this.id = id;
    }
}


class A implements Comparable< A> {// 优先级队列要用comparable接口
    int x, y, step, score;
    A(){};
    A(int x, int y, int step, int score) {// 方便直接赋值
        this.x = x;
        this.y = y;
        this.step = step;
        this.score = score;
    }
    public int compareTo(A arg0) {
        return (score - arg0.score);
    }
}


public class Main {
    char[][] g = new char[25][25];//地图
    int[][] mat = new int[12][12];//机器人、垃圾点每两个点之间最短距离(步数）
    int[][] dp = new int[11][1<< 11];
    int w, h, n ;
    int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
    boolean[][] mark = new boolean[25][25];
    boolean[][] ok = new boolean[11][1<<11];


    int dis(int x1, int y1, int x2, int y2) {
        return (int) Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }


    int min(int a, int b) {return a > b ? b : a;}


    int bfs(int x1, int y1, int x2, int y2) {//求点(x1,y1)到(x2,y2)之间的最少步
        PriorityQueue< A> q = new PriorityQueue< A>();
        A cur;
        for (int i = 0; i < 25; i++)
            Arrays.fill(mark[i], false);
        mark[x1][y1] = true;
        q.offer(new A(x1, y1, 0, 0));
        while (!q.isEmpty()) {
            cur = q.poll();
            for (int i = 0; i < 4; i++) {//往四个方向
                int dx = dir[i][0] + cur.x;
                int dy = dir[i][1] + cur.y;
                if (dx == x2 && dy == y2)
                    return cur.step + 1;
                if (!mark[dx][dy] && g[dx][dy] != 'x' && dx >= 1 && dx <= h
                        && dy >= 1 && dy <= w) {
                    q.offer(new A(dx, dy, cur.step + 1,
                            cur.step + 1 + dis(dx, dy, x2, y2)));
                    mark[dx][dy] = true;
                }
            }
        }
        return -1;
    }


    int dfs(int now, int s, int len) {//求最后一个到达的点为now，已经到达的点集为s的最短距离
        if (len == 1 && now == 0)//如果只有一个点机器人，则返回0
            return 0;
        if (ok[now][s])
            return dp[now][s];
        for (int i = 0; i < n; i++) {
            if (len > 2 && i == 0)//如果除机器人之外有垃圾点，跳过第一个点机器人
                continue;
            if (i != now && (s & (1 << i)) != 0 && mat[i][now] != -1) {
           //从i到now，几个条件是：i 和now不相等 i必须在已到点集中，i必须能够到达now
                dp[now][s] = min(dp[now][s],
                        dfs(i, s ^ (1 << now), len - 1) + mat[i][now]);
                //flag = 0;
            }
        }
        ok[now][s] = true;
        return dp[now][s];
    }


    void solve() throws IOException {
         BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
       // BufferedReader cin = new BufferedReader(new FileReader(new File("in")));
        while (true) {
            String read[] = cin.readLine().split(" ");//输入地图的宽和高
            w = Integer.parseInt(read[0]);
            h = Integer.parseInt(read[1]);
            if (w + h == 0)//结束循环
                break;
            ArrayList< P> v = new ArrayList< P>();//存放机器人位置和垃圾位置列表
            int num = 1;
            for (int i = 1; i <= h; i++) {//扫描地图
                read = cin.readLine().split(" ");
                for (int j = 1; j <= w; j++) {
                    g[i][j] = read[0].charAt(j - 1);
                    if (g[i][j] == 'o')//如果这个点是机器人，放入列表的第一个位置
                        v.add(new P(i, j, 0));
                    if (g[i][j] == '*')//如果这个点是垃圾,放入列表
                        v.add(new P(i, j, num++));
                }
            }

           /*输出地图
              for(int i=1;i<=h;i++){
                for(int j=1;j<=w;j++)
                    System.out.print(g[i][j]);
                System.out.println();
            }
             */

            n = v.size();//机器人与垃圾点总的个数
            //System.out.println("n="+n);

            //机器人与垃圾点每两个点之间A*算法算出最短距离(步数）
           for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int x = v.get(i).id;
                    int y = v.get(j).id;
                    mat[x][y] = mat[y][x] = bfs(v.get(i).x, v.get(i).y,
                            v.get(j).x, v.get(j).y);
                }
            }
            /*
            for(int i=0;i< n;i++){
                for(int j=0;j< n;j++)
                    System.out.print(mat[i][j]);
                System.out.println();
            }
            */
           // flag = 1;
            int ans = 1 << 29;//存放最后结果
            if (n == 1) {
                System.out.println("0");
                continue;
            }

           //最后一个到达的点分别设置为n-1,n-2,...2,1,0,已经到达的点集设置为2^n-1,比较求出最小步数
            for (int i = n - 1; i >= 0; i--) {
                for (int j = 0; j < 11; j++) {
                    Arrays.fill(ok[j], false);//初始化
                    Arrays.fill(dp[j], 1 << 29);//初始化
                }
                ans = min(ans, dfs(i, (1 << n) - 1, n));//
            }
            if (ans == 1 << 29)
                System.out.println("-1");
            else
                Syst
ut.println(ans);
        }
    }


    static public void main(String args[]) throws IOException {
        Main test = new Main();
        test.solve();
    }
}

