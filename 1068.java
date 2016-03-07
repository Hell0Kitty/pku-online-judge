 import java.util.Scanner;

 public class Main {

     int t;
     int len;
     int[] p;
     int[] w;
     String[] s;
     int index;
     int temp;
     int pos;

     public Main() {
         Scanner scan = new Scanner(System.in);
         t = scan.nextInt();
         for (int i = 0; i < t; i++) {
             len = scan.nextInt();
             p = new int[len];
             w = new int[len];
             s = new String[len * 2];
             for (int j = 0; j < len; j++) {
                 p[j] = scan.nextInt();
             }
             pos = 0;
             temp = 0;
             index = 0;
             for (int k = 0; k < len; k++) {
                 for (; pos < p[k]; pos++) {
                     s[index++] = "(";
                 }
                 s[index++] = ")";
             }
             search();
             for (int m = 0; m < len; m++) {
                 System.out.print(w[m] + " ");
             }
             System.out.println();
         }
     }

     public void search() {
         pos = 0;
         int k = 0;
         for (int i = 0; i < len; i++) {
             for (; k < 2 * len; k++) {
                 if (s[k].equals(")")) {
                     pos = k;
                     k++;
                     break;
                 }
             }
             temp = 0;
             index = 1;
             for (int j = pos - 1;; j--) {
                 if (s[j].equals("(")) {
                     temp++;
                     index--;
                 } else {
                     index++;
                 }
                 if (index == 0) {
                     w[i] = temp;
                     break;
                 }
             }
         }
     }

     public static void main(String[] args) {
         new Main();
     } 
}

