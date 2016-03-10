import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String[] s = read.readLine().split(" ");
         int n = Integer.parseInt(s[0]);
         int m = Integer.parseInt(s[1]);
         int p1, p2;
         double[][] a = new double[n][n];
         int[][] p = new int[n][2];
         for (int i = 0; i < n; i++) {
             s = read.readLine().split(" ");
             p[i][0] = Integer.parseInt(s[0]);
             p[i][1] = Integer.parseInt(s[1]);
         }
         for (int i = 0; i < n; i++) {
             for (int j = i + 1; j < n; j++) {
                 a[i][j] = a[j][i] = Math.sqrt(Math.pow(p[i][0] - p[j][0], 2)
                         + Math.pow(p[i][1] - p[j][1], 2));
             }
         }
         for (int i = 0; i < m; i++) {
             s = read.readLine().split(" ");
             p1 = Integer.parseInt(s[0]);
             p2 = Integer.parseInt(s[1]);
             a[p1 - 1][p2 - 1] = a[p2 - 1][p1 - 1] = 0;
         }
         System.out.printf("%.2f", prim(a, n));
     }

     public static double prim(double[][] a, int count) {
         double sum = 0;
         int i, j, k;
         double[] lowcost = new double[count];
         double[] closeset = new double[count];
         boolean[] used = new boolean[count];
         for (i = 0; i < count; i++) {
             lowcost[i] = a[0][i];
             closeset[i] = 0;
             used[i] = false;
         }
         used[0] = true;
         for (i = 1; i < count; i++) {
             j = 0;
             while (used[j]) {
                 j++;
             }
             for (k = 0; k < count; k++) {
                 if ((!used[k]) && (lowcost[k] < lowcost[j])) {
                     j = k;
                 }
             }
             sum += lowcost[j];
             used[j] = true;
             for (k = 0; k < count; k++) {
                 if (!used[k] && (a[j][k] < lowcost[k])) {
                     {
                         lowcost[k] = a[j][k];
                         closeset[k] = j;
                     }
                 }
             }
         }
         return sum;
     }
}

