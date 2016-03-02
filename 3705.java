//* @author
import java.util.Scanner;

public class Main {
Scanner cin = new Scanner(System.in);
int n;

public void inPut() {
   n = cin.nextInt();

   reverse();
}

private void reverse() {
   if (n == 1) {
    System.out.println(0);
   } else {
    if (n == 2) {
     System.out.println(1);
     System.out.println(2 + " " + 1 + " " + 0);
    } else {
     if (n % 2 == 0) {
      int m = (n + 1) / 2 + 1;
      System.out.println(m);
      print(n, m);
     } else {
      if(n % 2 != 0) {
       int m = (n + 1) / 2;
       System.out.println(m);
       print(n, m);
      }
     }
    }
   }
}

void print(int n, int m) {
   if (n % 2 != 0) {
    for (int i = 0; i < m - 1; i++) {
     System.out.println((n / 2 + i + 1) + " " + 2 + " " + i);
    }
    System.out.println(1 + " " + (n - 1) / 2 + " " + (n - 1) / 2);

   } else {
    for (int i = 0; i < m - 2; i++) {
     System.out.println((n / 2 + i + 1) + " " + 2 + " " + (i + 1));
    }
    System.out.println(2 + " " + (n - 1) / 2 + " " + (n) / 2);
    System.out.println(1 + " " + 1 + " " + (n - 1));

   }
}

public static void main(String[] args) {
   new Main().inPut();
}

}

