import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int a = in.nextInt();
    int count = 1;
    int[] arr = new int[] {9, 3, 7};
    while ((a--) != 0) {
      String s = in.next();
      int total = 0;
      int k = 0;
      int p = 0;
      int t = s.length();
      for (int i = t - 1; i > -1; i--) {
        char c = s.charAt(i);
        if (c != '?') {
          int w = c - 48;
          total += w * arr[(t - 1 - i) % 3];
        }
        if (c == '?') {
          k = arr[(t - 1 - i) % 3];
          p = i;
        }
      }
      for (int i = 0; i < 10; i++) {
        if ((total + i * k) % 10 == 0) {
          System.out.println("Scenario #" + count + ":");
          System.out.println(s.substring(0, p) + i + s.substring(p + 1));
          System.out.println();
          break;
        }
      }
      count++;
    }
  }
}