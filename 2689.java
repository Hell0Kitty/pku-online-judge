 import java.util.Scanner;

 public class Main {

     final static int MAXVALUE = (int) Math.sqrt(Integer.MAX_VALUE) + 1;

     public static void main(String[] args) {
         int k, l, u, tt, index;
         boolean hasFlg;
         int a, b, aa, bb;
         int[] num = new int[MAXVALUE];
         boolean[] frimeflg = new boolean[MAXVALUE];
         boolean[] flg;
         index = 1;
         // 鏋勯€犱竴涓皬绱犳暟琛?
         for (int i = 2; i < MAXVALUE; i++) {
             if (!frimeflg[i]) {
                 k = i * 2;
                 num[index++] = i;
                 while (k < MAXVALUE) {
                     frimeflg[k] = true;
                     k += i;
                 }
             }
         }
         Scanner scan = new Scanner(System.in);
         while (scan.hasNextInt()) {
             l = scan.nextInt();
             u = scan.nextInt();
             tt = (int) Math.sqrt(u);
             // 鏋勯€犱竴涓猽-l+1鐨勫尯闂?
             flg = new boolean[u - l + 1];
             // 绛涢€夊尯闂达紝涓嶆槸绱犳暟鐨勬爣璁颁负true
             for (int i = 1; i < index && i <= tt; i++) {
                 k = Math.max(num[i], l / num[i]);
                 if (k * num[i] < l || k <= 1) {
                     k++;
                 }
                 if (k <= 1) {
                     k++;
                 }
                 while ((long) k * num[i] <= u) {
                     flg[k * num[i] - l] = true;
                     k++;
                 }
             }
             hasFlg = false;
             a = 0;
             b = Integer.MAX_VALUE;
             aa = 0;
             bb = 0;
             if (l == 1) {
                 flg[0] = true;
             }
             for (int i = 0; i < u - l + 1; i++) {
                 if (!flg[i]) {
                     for (int j = i + 1; j <= u - l; j++) {
                         if (!flg[j]) {
                             if (b - a > j - i) {
                                 a = i + l;
                                 b = j + l;
                             }
                             if (bb - aa < j - i) {
                                 bb = j + l;
                                 aa = i + l;
                             }
                             hasFlg = true;
                             break;
                         }
                     }
                 }
             }
             if (hasFlg) {
                 System.out.printf(
                         "%d,%d are closest, %d,%d are most distant.\n", a, b,
                         aa, bb);
             } else {
                 System.out.println("There are no adjacent primes.");
             }
         }
     }
}

