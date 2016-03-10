 import java.io.BufferedReader;
 import java.io.InputStreamReader;
 import java.util.Arrays;

 public class Main {

     static int n, b;
     static int[] h;
     static boolean[] used;
     static int min = Integer.MAX_VALUE;

     public static void main(String[] args) throws Exception {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String[] s = read.readLine().split(" ");
         n = Integer.parseInt(s[0]);
         h = new int[n];
         used = new boolean[n];
         b = Integer.parseInt(s[1]);
         for (int i = 0; i < n; i++) {
             h[i] = Integer.parseInt(read.readLine());
         }
         Arrays.sort(h);
         search(0, 0);
         System.out.println(min);
     }

     public static boolean search(int sum, int deep) {
         if (sum >= b) {
             if (sum - b < min) {
                 min = sum - b;
             }
             return true;
         }
         for (int i = deep; i < n; i++) {
             if (used[i]) {
                 continue;
             }
             used[i] = true;
             if (search(sum + h[i], i + 1)) {
                 used[i] = false;
                 break;
             }
             used[i] = false;
         }
         return false;
     }
}

