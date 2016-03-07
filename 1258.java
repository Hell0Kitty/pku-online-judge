 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String s = null;
         int n;
         int[][] a;
         int t;
         String[] ss;
         int index;
         while ((s = read.readLine()) != null) {
             if (s.equals("")) {
                 break;
             }
             n = Integer.parseInt(s);
             a = new int[n][n];
             t = n;
             while (t-- > 0) {
                 index = 0;
                 while (index != n) {
                     ss = read.readLine().split(" ");
                     for (int i = 0; i < ss.length; i++, index++) {
                         a[n - t - 1][index] = Integer.parseInt(ss[i]);
                     }
                 }
             }
             System.out.println(prim(a, n));
         }
     }

     public static int prim(int[][] a, int count) {
         int sum = 0;
         int i, j, k;
         int[] lowcost = new int[count];
         int[] closeset = new int[count];
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