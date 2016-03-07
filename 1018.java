 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     double bp = 0;

     public Main() throws NumberFormatException, IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int t = Integer.parseInt(read.readLine());
         int num;
         int[][] b;
         int[][] p;
         int[] n;
         int bmin = Integer.MAX_VALUE;
         int[] bmaxs;
         int bmax;
         String[] s;
         int sum;
         int temp;
         for (int i = 0; i < t; i++) {
             num = Integer.parseInt(read.readLine());
             b = new int[num][];
             p = new int[num][];
             n = new int[num];
             bmin = Integer.MAX_VALUE;
             bmaxs = new int[num];
             bmax = Integer.MAX_VALUE;
             for (int j = 0; j < num; j++) {
                 s = read.readLine().split(" ");
                 n[j] = Integer.parseInt(s[0]);
                 b[j] = new int[n[j]];
                 p[j] = new int[n[j]];
                 for (int k = 0; k < n[j]; k++) {
                     b[j][k] = Integer.parseInt(s[k * 2 + 1]);
                     if (b[j][k] > bmaxs[j]) {
                         bmaxs[j] = b[j][k];
                     }
                     if (b[j][k] < bmin) {
                         bmin = b[j][k];
                     }
                     p[j][k] = Integer.parseInt(s[k * 2 + 2]);
                 }
             }
             for (int j = 0; j < num; j++) {
                 if (bmaxs[j] < bmax) {
                     bmax = bmaxs[j];
                 }
             }
             bp = 0;
             for (int j = bmin; j <= bmax; j++) {
                 sum = 0;
                 for (int k = 0; k < num; k++) {
                     temp = Integer.MAX_VALUE;
                     for (int h = 0; h < n[k]; h++) {
                         if (b[k][h] >= j && p[k][h] < temp) {
                             temp = p[k][h];
                         }
                     }
                     sum += temp;
                 }
                 if ((double) j / sum > bp) {
                     bp = (double) j / sum;
                 }
             }
             System.out.printf("%.3f\n", bp);
         }
     }

     public static void main(String[] args) throws NumberFormatException,
             IOException {
         new Main();
     } 
}