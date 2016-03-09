//* @author
//import java.io.File;
//import java.io.FileNotFoundException;
//import java.util.Arrays;
import java.util.Scanner;

public class Main{
Scanner cin = new Scanner(System.in);

int n;
int cases;
int stone[][];
double map[][];

public void inPut() {
   //File f = new File("D:\\ACM\\POJ解题\\2253\\test.txt");
  // cin = new Scanner(f);

   while (true) {
    cases ++;
    n = cin.nextInt();
    if (n == 0) {
     return;
    }
    stone = new int[n][2];
    map = new double[n][n];
    for (int i = 0; i < n; i++) {
     stone[i][0] = cin.nextInt();
     stone[i][1] = cin.nextInt();
    }

    for (int i = 0; i < n; i++) {
     for (int j = 0; j < n; j++) {
      map[i][j] = Math.sqrt((stone[i][0] - stone[j][0])
        * (stone[i][0] - stone[j][0])
        + (stone[i][1] - stone[j][1])
        * (stone[i][1] - stone[j][1]));
     }
    }

    solve();
   }
}

private void solve() {
//   System.out.println(Arrays.deepToString(map));
   System.out.println("Scenario #" + cases);
   System.out.printf("Frog Distance = %.3f\n\n", floyd());
}

private double floyd() {
   for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
     for (int j = 0; j < n; j++) {

//这个if语句里面的东西有改变,根据题意是要求两个石头之间的所有路径中最大跳(necessary jump range)最小的
//这样就能把从石头A跳到石头B的所有路径中最大跳最小的值存到map[A][B]中,最后map[0][1]中存的就是所要的值
      if (map[k][i] != 0
        && map[i][j] != 0
        && map[k][j] > (map[k][i] > map[i][j] ? map[k][i]
          : map[i][j])) {
       map[k][j] = (map[k][i] > map[i][j] ? map[k][i] : map[i][j]);
      }
     }
    }
   }
   return map[0][1];
}

public static void main(String[] args) {
   new Main().inPut();
}

}

