 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.HashSet;
 import java.util.Set;

 public class Main {

     static Set set;
     static int[][] a;

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         a = new int[5][5];
         String[] s;
         for (int i = 0; i < 5; i++) {
             s = read.readLine().split(" ");
             for (int j = 0; j < 5; j++) {
                 a[i][j] = Integer.parseInt(s[j]);
             }
         }
         set = new HashSet();
         for (int i = 0; i < 5; i++) {
             for (int j = 0; j < 5; j++) {
                 search(0, 0, i, j);
             }
         }
         System.out.println(set.size());
     }

     public static void search(int sum, int dp, int x, int y) {
         if (dp == 6) {
             set.add(sum);
             return;
         }
         if (x - 1 >= 0) {
             search(sum * 10 + a[x - 1][y], dp + 1, x - 1, y);
         }
         if (x + 1 < 5) {
             search(sum * 10 + a[x + 1][y], dp + 1, x + 1, y);
         }
         if (y - 1 >= 0) {
             search(sum * 10 + a[x][y - 1], dp + 1, x, y - 1);
         }
         if (y + 1 < 5) {
             search(sum * 10 + a[x][y + 1], dp + 1, x, y + 1);
         }
     }
}

