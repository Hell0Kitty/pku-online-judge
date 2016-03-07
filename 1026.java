 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.Arrays;

 public class Main {

     public static void main(String[] args) throws NumberFormatException,
             IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int len;
         int[] n;
         int[] loop;
         String[] s;
         int times;
         int temp;
         String str;
         char[] result;
         int r;
         while ((len = Integer.parseInt(read.readLine())) != 0) {
             n = new int[len];
             loop = new int[len];
             result = new char[len];
             s = read.readLine().split(" ");
             for (int i = 0; i < len; i++) {
                 n[i] = Integer.parseInt(s[i]);
             }
             findLoop(n, loop);
             str = read.readLine();
             while ((times = Integer.parseInt(str.split(" ")[0])) != 0) {
                 Arrays.fill(result, ' ');
                 str = str.substring(str.indexOf(" ") + 1);
                 for (int i = 0; i < str.length(); i++) {
                     temp = times % loop[i];
                     r = i;
                     if (temp > 0) {
                         r = n[i];
                         for (int k = 1; k < temp; k++) {
                             r = n[r - 1];
                         }
                         result[r - 1] = str.charAt(i);
                     } else {
                         result[r] = str.charAt(i);
                     }
                 }
                 System.out.println(String.valueOf(result));
                 str = read.readLine();
             }
             System.out.println();
         }
     }

     public static void findLoop(int[] n, int[] loop) {
         int temp;
         int c;
         for (int i = 0; i < n.length; i++) {
             temp = 1;
             c = n[n[i] - 1];
             while (n[i] != c) {
                 c = n[c - 1];
                 temp++;
             }
             loop[i] = temp;
         }
     }
}