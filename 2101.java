import java.util.Scanner;

public class Main {

public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   int n = cin.nextInt();
   int e = cin.nextInt();
   double l1 = 0, l2 = 0;
   while(--n > 0) {
    l1 += cin.nextInt();
   }
   while(--e > 0) {
    l2 += cin.nextInt();
   }
   l1 = Math.hypot(l1, l2);
   System.out.println((int)Math.ceil(l1));
}

}


