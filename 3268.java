import java.util.Arrays;
import java.util.Scanner;

public class Main {

 public static void main(String[] args) {

         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt();
         int m = sc.nextInt();
         int x = sc.nextInt();
         int[][] map1 = new int[n + 1][n + 1];
         int[][] map2 = new int[n + 1][n + 1];

         boolean[] visted = new boolean[n + 1];
         int[] dist1 = new int[n + 1];
         int[] dist2 = new int[n + 1];

         for (int i = 0; i < m; i++) {
             int a = sc.nextInt();
             int b = sc.nextInt();
             int t = sc.nextInt();
             map1[a][b] = t;
             map2[b][a] = t;
        }

        dijkstra(visted, dist1, map1, x);

        dijkstra(visted, dist2, map2, x);

        int max = Integer.MIN_VALUE;

        for (int i = 1; i <= n; i++) {
           if (dist1[i] + dist2[i] > max) {
               max = dist1[i] + dist2[i];
          }
       }

       System.out.println(max);
 }

 public static void dijkstra(boolean[] visted, int[] dist, int[][] map, int x) {
     Arrays.fill(visted, false);
     Arrays.fill(dist, Integer.MAX_VALUE);

     visted[x] = true;

     // 初始化dist数组
     for (int i = 1; i < dist.length; i++) {
            if (!visted[i] && map[x][i] != 0) {
                dist[i] = map[x][i];
          }
      }

     while (true) {

          int temp = 0;
          int min = Integer.MAX_VALUE;

          //找出花费最少时间的路径
          for (int i = 1; i < dist.length; i++) {
             if (dist[i] < min && !visted[i]) {
             min = dist[i];
              temp = i;
            }
         }
         // x = temp;
          if (temp == 0)
                break;
          visted[temp] = true;

         //更新目前x到其他田的最短路径
          for (int i = 1; i < dist.length; i++) {

          if (!visted[i] && map[temp][i] != 0
                && dist[i] > dist[temp] + map[temp][i]) {
                dist[i] = dist[temp] + map[temp][i];
           }
        }
     }
   }
}


