import java.io.BufferedInputStream;
import java.util.Scanner;


/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * 求最短路径
 * 有两种方法。用弗洛德相对简单点
 * 这道题理解题意后就不难了。代码的编写也比较容易。
 * 只是初始化和单个顶点的环注意下就行了
 * poj1125
 * @author NC
 */
public class Main {

    final static int disjoint = 1000;//最多100个人，每个人最多花费10分钟

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            int n = scan.nextInt();
            if (n == 0) {
                break;
            }
            //初始化矩阵,默认不可达,stockbroker的编号是从1开始的
            int[][] times = new int[n + 1][n + 1];
            for (int i = 0; i < n + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    times[i][j] = disjoint;
                }
            }
            for (int i = 1; i <= n; i++) {
                int stockbroker = i;
                int number = scan.nextInt();
                for (int j = 1; j <= number; j++) {
                    int contact = scan.nextInt();
                    int time = scan.nextInt();
                    times[stockbroker][contact] = time;
                }
            }
            //弗洛依德算法，顶点i到j经过k点
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (i != j && times[i][k] + times[k][j] < times[i][j]) {
                            times[i][j] = times[i][k] + times[k][j];
                        }
                    }
                }
            }
            //注意，单个顶点本身不应该有环,这里是无穷大
            //求每个经纪人将信息传递给所有人知道所要花费的时间,存储在第0列
            for (int i = 1; i <= n; i++) {
                times[i][0] = 0;//赋0方便比较大小
                for (int j = 1; j <= n; j++) {
                    if (times[i][j] > times[i][0] && i != j) {//求max
                        times[i][0] = times[i][j];
                    }
                }
            }
            //找出最小耗时,存在第0行第0列
            int index = 0;
            for (int i = 1; i <= n; i++) {
                if (times[i][0] < times[0][0] && times[i][0] != disjoint) {//求min
                    times[0][0] = times[i][0];
                    index = i;
                }
            }
            //输出结果
            if (index == 0) {
                System.out.println("disjoint");
            } else {
                System.out.println(index + " " + times[0][0]);
            }
        }
    }
}

