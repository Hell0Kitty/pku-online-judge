//* @author: 82638882@163.com
import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int cnt = 0;
    while ((a--) != 0) {
      int b = in.nextInt();
      int c = in.nextInt();
      cnt++;
      int d = 0, e = 0;
      while (true) {
        if (b > c) {
          d += b / c;
          b = b % c;
          if (b == 0)
            break;
        } else {
          e += c / b;
          c = c % b;
          if (c == 0)
            break;
        }
      }
      if (b == 0)
        d--;
      if (c == 0)
        e--;
      System.out.println("Scenario #" + cnt + ":");
      System.out.println(d + " " + e);
      System.out.println();
    }
  }
}