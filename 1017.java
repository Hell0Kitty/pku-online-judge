 import java.util.Scanner;

 public class Main {

     int a;
     int b;
     int c;
     int d;
     int e;
     int f;
     int packets;
     int t;

     public Main() {
         Scanner scan = new Scanner(System.in);
         a = scan.nextInt();
         b = scan.nextInt();
         c = scan.nextInt();
         d = scan.nextInt();
         e = scan.nextInt();
         f = scan.nextInt();
         while (a != 0 || b != 0 || c != 0 || d != 0 || e != 0 || f != 0) {
             // 6*6
             packets = f;
             // 5*5
             packets += e;
             a -= 11 * e;
             // 4*4
             packets += d;
             if (b >= 5 * d) {
                 b -= 5 * d;
             } else {
                 t = 5 * d - b;
                 b = 0;
                 a -= 4*t;
             }
             // 3*3
             packets += c / 4;
             t = c % 4;
             if (t != 0) {
                 packets += 1;
                 if (t == 1) {
                     if (b >= 5) {
                         b -= 5;
                         a -= 7;
                     } else if (b >= 0) {
                         a -= (36 - 9 - 4 * b);
                         b = 0;
                     }
                 } else if (t == 2) {
                     if (b >= 3) {
                         b -= 3;
                         a -= 6;
                     } else if (b >= 0) {
                         a -= (36 - 18 - 4 * b);
                         b = 0;
                     }
                 } else if (t == 3) {
                     if (b >= 1) {
                         b -= 1;
                         a -= 5;
                     } else if (b >= 0) {
                         a -= (36 - 27 - 4 * b);
                         b = 0;
                     }
                 }
             }
             // 2*2
             if (b > 0) {
                 packets += b / 9;
                 t = b % 9;
                 if (t != 0) {
                     packets += 1;
                     a -= 36 - 4 * t;
                 }
             }
             // 1*1
             if (a > 0) {
                 packets += a / 36;
                 t = a % 36;
                 if (t != 0) {
                     packets += 1;
                 }
             }
             System.out.println(packets);
             a = scan.nextInt();
             b = scan.nextInt();
             c = scan.nextInt();
             d = scan.nextInt();
             e = scan.nextInt();
             f = scan.nextInt();
         }
     }

     public static void main(String[] args) {
         new Main();
     }
}