import java.util.Scanner;
public class Main {
  static int a[];
  static String s[];
  public static boolean check(int length) {
    int i, n, m;
    n = a[length];
    for (i = 0; i < length; i++) {
      m = a[i] - n;
      if (m > 0 && !s[i].equals("high")) {
        return false;
      }
      if (m < 0 && !s[i].equals("low")) {
        return false;
      }
      if (m == 0 && !s[i].equals("on")) {
        return false;
      }
    }
    return true;
  }
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int i, n;
    while ((n = sc.nextInt()) != 0) {
      a = new int[20];
      s = new String[21];
      a[0] = n;
      i = 0;
      while (true) {
        sc.next();
        s[i] = sc.next();
        if (s[i].equals("on"))
          break;
        i++;
        a[i] = sc.nextInt();
      }
      if (check(i)) {
        System.out.println("Stan may be honest");
      } else {
        System.out.println("Stan is dishonest");
      }
    }
  }
}