 import java.util.Scanner;

 public class Main {

     static final int LENGHT = 5;
     int t;
     int i;
     int a1[] = new int[LENGHT + 1];
     int a2[] = new int[LENGHT + 1];
     int b1[] = new int[LENGHT];
     int flg[] = new int[LENGHT + 1];
     int pos;
     int temp;
     int local;
     int local2;
     int res;

     public Main() {
         a1[0] = 0;
         a2[0] = 0;
         b1[0] = 0;
         a1[1] = 1;
         flg[0] = 9;
         for (int i = 1; i < LENGHT + 1; i++) {
             a1[i] = a2[i - 1] + (i);
             a2[i] = a1[i] + (flg[i - 1] - 1) * (i);
             if (i < LENGHT) {
                 b1[i] = b1[i - 1] + (a1[i] + a2[i]) * flg[i - 1] / 2;
             }
             flg[i] = flg[i - 1] * 10;

         }
         Scanner scan = new Scanner(System.in);
         t = scan.nextInt();
         for (int times = 0; times < t; times++) {
             i = scan.nextInt();
             pos = LENGHT;
             for (int j = 1; j < LENGHT; j++) {
                 if (i <= b1[j]) {
                     pos = j;
                     break;
                 }
             }
             temp = i - b1[pos - 1];
             for (int j = 0; j < flg[pos - 1]; j++) {
                 if (temp <= a1[pos] + pos * j) {
                     local = j;
                     break;
                 } else {
                     temp = temp - (a1[pos] + pos * j);
                 }
             }
             local = (int) Math.pow(10, pos - 1) + local;
             for (int i = 1; i < LENGHT + 1; i++) {
                 if (temp <= flg[i - 1] * i) {
                     local2 = i;
                     break;
                 } else {
                     temp = temp - flg[i - 1] * i;
                 }
             }
             res = (int) Math.pow(10, local2 - 1);
             for (; temp > local2;) {
                 temp -= local2;
                 res++;
             }
             String str = String.valueOf(res);
             System.out.println(str.charAt(temp - 1));
         }
     }

     public static void main(String[] args) {
         new Main();
     } 
}