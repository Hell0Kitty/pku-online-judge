 import java.util.Scanner;

 public class Main {

     int n;
     int m;
     int k;
     boolean[][] cells;
     int max;
     int t;

     public Main() {
         Scanner scan = new Scanner(System.in);
         n = scan.nextInt();
         m = scan.nextInt();
         k = scan.nextInt();
         cells = new boolean[n][m];
         for (int i = 0; i < k; i++) {
             cells[scan.nextInt() - 1][scan.nextInt() - 1] = true;
         }
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < m; j++) {
                 if (cells[i][j]) {
                     t = 0;
                     search(i, j);
                     if (t > max) {
                         max = t;
                     }
                 }
             }
         }
         System.out.println(max);

     }

     public void search(int i, int j) {
         if (!cells[i][j]) {
             return;
         } else {
             t++;
             cells[i][j] = false;
             if (j - 1 >= 0) {
                 search(i, j - 1);
             }
             if (j + 1 < m) {
                 search(i, j + 1);
             }
             if (i - 1 >= 0) {
                 search(i - 1, j);
             }
             if (i + 1 < n) {
                 search(i + 1, j);
             }
         }
     }

     public static void main(String[] args) {
         new Main();
     }
}
