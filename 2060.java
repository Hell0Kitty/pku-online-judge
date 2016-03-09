import java.util.Arrays;
import java.util.Scanner;

public class Main{
    static int n = 0;//提前预定的taxi总数
    static final int MAX = 500;//最大容量
    static Booked[] booked = new Booked[MAX];//taxi对象数组
    static boolean[][] graph = new boolean[MAX * 2][MAX * 2];//建图
    static boolean[] visit = new boolean[MAX * 2];//访问标记
    static int[] link = new int[MAX * 2];//记录前节点
 public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   int t = cin.nextInt();
   while (t-- != 0) {
    n = cin.nextInt();
    for (int i = 0; i < n; i++) {
     String[] ss = cin.next().split(":");
     int time = Integer.parseInt(ss[0]) * 60 + Integer.parseInt(ss[1]);//计算出发时间
     booked[i] = new Booked(time, cin.nextInt(), cin.nextInt(), cin.nextInt(), cin.nextInt());//读入起始坐标
    }
    init();
    System.out.println(n - hungray());//节点数 - 最大二分匹配
   }
  }

  static void init() {//构建图
   for (int i = 0; i < MAX * 2; i++)
    Arrays.fill(graph[i], false);
    for (int i = 0; i < n; i++) {
     for (int j = 0; j < n; j++) {
      if (booked[i].reachable(booked[j]))
       graph[i][j + n] = true;
     }
    }
  }

  static boolean find(int x) {//寻找可增广路
   for (int i = 0; i < n * 2; i++) {
    if (graph[x][i] && !visit[i]) {
      visit[i] = true;
      if (link[i] == -1 || find(link[i])) {
        link[i] = x;
        return true;
      }
     }
   }
   return false;
  }

  static int hungray() {//匈牙利求最大匹配
    int ans = 0;
        Arrays.fill(link, -1);
        for (int i = 0; i < n; i++) {
            Arrays.fill(visit, false);
            if (find(i))
                ans++;
        }
        return ans;
    }
}
class Booked {//预计的taxi类
    int time, a, b, c, d;
    public Booked(int time, int a, int b, int c, int d) {
        this.time = time;//出发时间
        this.a = a;//起点坐标
        this.b = b;
        this.c = c;//终点坐标
        this.d = d;
    }
    boolean reachable(Booked bo) {//两条路线能否用一辆taxi来代替
        return this.time + Math.abs(this.a - this.c) + Math.abs(this.b - this.d)
        + Math.abs(bo.a - this.c) + Math.abs(bo.b - this.d) < bo.time;
    }
}


