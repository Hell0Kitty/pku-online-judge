 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         int t;
         int s;
         int[] len;
         String str;
         int start;
         int end;
         int max;
         len = new int[10000];
         for (int i = 1; i < 10000; i++) {
             s = 1;
             t = i;
             while (t != 1) {
                 if (t < 10000 && len[t] != 0) {
                     s += len[t] - 1;
                     break;
                 }
                 if (t % 2 == 1) {
                     t = 3 * t + 1;
                 } else {
                     t = t / 2;
                 }
                 s++;
             }
             len[i] = s;
         }
         while ((str = read.readLine()) != null && !str.equals("")) {
             start = Integer.parseInt(str.split(" ")[0]);
             end = Integer.parseInt(str.split(" ")[1]);
             max = 0;
             for (int i = Math.min(start, end); i <= Math.max(start, end); i++) {
                 if (len[i] > max) {
                     max = len[i];
                 }
             }
             System.out.printf("%d %d %d\n", start, end, max);
         }
     } 
}