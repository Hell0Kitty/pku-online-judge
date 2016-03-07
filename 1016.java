 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.util.Arrays;

 public class Main {

     public static void main(String[] args) throws IOException {
         BufferedReader read = new BufferedReader(new InputStreamReader(
                 System.in));
         String s;
         char[][] c;
         char[] next;
         int step;
         int[] num;
         int result;
         StringBuffer buff = new StringBuffer();
         while (!(s = read.readLine()).startsWith("-")) {
             c = new char[15][];
             step = 2;
             num = new int[10];
             c[0] = s.toCharArray();
             while (true) {
                 Arrays.fill(num, 0);
                 for (int i = 0; i < c[step - 2].length; i++) {
                     num[c[step - 2][i] - '0']++;
                 }
                 buff.delete(0, buff.length());
                 for (int i = 0; i < 10; i++) {
                     if (num[i] != 0) {
                         buff.append(num[i]);
                         buff.append(i);
                     }
                 }
                 next = buff.toString().toCharArray();
                 if ((result = equal(c, next, step)) != -1) {
                     if (step == 2) {
                         System.out.printf("%s is self-inventorying\n", s);
                     } else {
                         if (step - result == 2) {
                             System.out.printf(
                                     "%s is self-inventorying after %d steps\n",
                                     s, step - 1);
                         } else {
                             System.out
                                     .printf(
                                             "%s enters an inventory loop of length %d\n",
                                             s, step - result - 1);
                         }
                     }
                     break;
                 } else {
                     if (step >= 15) {
                         System.out
                                 .printf(
                                         "%s can not be classified after 15 iterations\n",
                                         s);
                         break;
                     }
                     c[step - 1] = next;
                     step++;
                 }
             }
         }
     }

     public static int equal(char[][] a, char[] b, int t) {
         int[] aa = new int[10];
         int[] bb = new int[10];
         loop: for (int i = 0; i < t - 1; i++) {
             Arrays.fill(aa, 0);
             Arrays.fill(bb, 0);
             if (a[i].length != b.length) {
                 continue;
             } else {
                 for (int j = 0; j < b.length; j++) {
                     aa[a[i][j] - '0']++;
                     bb[b[j] - '0']++;
                 }
                 for (int j = 0; j < 10; j++) {
                     if (aa[j] != bb[j]) {
                         continue loop;
                     }
                 }
                 return i;
             }
         }
         return -1;
     } 
}