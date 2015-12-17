import java.util.Scanner;
import java.util.Arrays;
public class Main {
  // 求从1到n-1与n互质的数的个数,代码如下
  static int eular(int n) {
    int ret = 1, i;
    for (i = 2; i * i <= n; i++)
      if (n % i == 0) {
        n /= i;
        ret *= (i - 1);
        while (n % i == 0) {
          n /= i;
          ret *= i;
        }
      }
    if (n > 1)
      ret *= (n - 1);
    return ret;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    while (sc.hasNext()) {
      int n = sc.nextInt();
      if (n == 0)
        break;
      System.out.println(eular(n));
   }
  }
}