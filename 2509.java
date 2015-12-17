import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    while (in.hasNext()) {
      int n = in.nextInt();
      int k = in.nextInt();
      int temp = n;
      int add = 0;
      while (n >= k) {

        int diff = n / k;
        add = add + diff;
        n = diff + n - (n / k) * k;
      }
      System.out.println(temp + add);
    }
  }
}