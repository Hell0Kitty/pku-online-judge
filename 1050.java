 import java.util.Scanner;

 public class Main {

     int[][] a;
     int l;
     int max = Integer.MIN_VALUE;
     int t;
     int t1;
     int t2[];

     public Main() {
         Scanner scan = new Scanner(System.in);
         l = scan.nextInt();
         a = new int[l][l];
         for (int i = 0; i < l; i++) {
             for (int j = 0; j < l; j++) {
                 a[i][j] = scan.nextInt();
             }
         }
         search();
         System.out.println(max);
     }

     public void search() {
         for (int i = 0; i < l; i++) {
             for (int j = 0; j < l; j++) {
                 t1 = 0;
                 t2 = new int[l];
                 for (int k = i; k < l; k++) {
                     t1 += a[k][j];
                     t = t1;
                     if (t > max) {
                         max = t;
                     }
                     for (int m = j + 1; m < l; m++) {
                         t2[m] += a[k][m];
                         t += t2[m];
                         if (t > max) {
                             max = t;
                         }
                     }
                 }
             }
         }
     }

     public static void main(String[] args) {
         new Main();
     }
}