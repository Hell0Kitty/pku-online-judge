import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main{
 static int n, k, m;
 static int[][] matrix;
 static int[][] result;

 /**
  * 将数组a中元素复制到另外一数组中
  *
  * @param a
  * @return
  */
 static int[][] copy(int[][] a) {
       int[][] re = new int[n][n];
       for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
         re[i][j] = a[i][j];
       return re;
 }

 /**
  * 针对两数组求和并取其%m
  *
  * @param a
  * @param b
  */
 static void add(int[][] a, int[][] b) {
       for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
         a[i][j] += b[i][j];
         a[i][j] %= m;
        }
 }

 /**
  * 计算两矩阵的积并取其%m
  *
  * @param a
  * @param b
  * @return
  */
 static int[][] mul(int[][] a, int[][] b) {
       int[][] re = new int[n][n];
       for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
         long t = 0;
         for (int k = 0; k < n; k++) {
          t += 1L * a[i][k] * b[k][j];
         }
         re[i][j] = (int) (t % m);
        }
       return re;
 }

 /**
  * 计算matrix的p次幂%m
  *
  * @param p
  * @return
  */
 static int[][] powm(int p) {
       if (p == 1)
        return matrix;
       int[][] re = powm(p / 2);
       re = mul(re, re);
       if (p % 2 == 1)
        re = mul(re, matrix);
       return re;
 }

 /**
  * 计算A + A2 + A3 + … + Ak的和%m
  *
  * @param lk
  * @return
  */
 static int[][] calc(int lk) {
       if (lk == 1)
        return copy(matrix);
       int mid = lk / 2;
       if (lk % 2 == 1)
        mid++;

       //计算A + A2 + A3 + … +Ai
       int[][] re1 = calc(lk / 2);

       //计算Ai
       int[][] fac = powm(mid);

       int[][] re = mul(fac, re1);

       add(re, re1);
       if (lk % 2 == 1)
        add(re, fac);
       return re;
 }

 public static void main(String[] args) throws Exception {
       BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
       PrintWriter out = new PrintWriter(System.out);
       // 读取n,k,m
       String s = cin.readLine();
       String[] sa = s.split(" ");
       n = Integer.parseInt(sa[0]);
       k = Integer.parseInt(sa[1]);
       m = Integer.parseInt(sa[2]);
       matrix = new int[n][n];
       result = new int[n][n];
       for (int i = 0; i < n; i++) {
        s = cin.readLine().trim();
        sa = s.split(" ");
        for (int j = 0; j < n; j++)
         matrix[i][j] = Integer.parseInt(sa[j]);
       }
       int[][] re = calc(k);
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
         out.print(re[i][j] + " ");
        }
        out.println();
       }
       out.flush();
       out.close();
 }
}

