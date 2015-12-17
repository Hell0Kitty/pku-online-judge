/* @author: */
import java.util.Scanner;
public class Main {

  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int a[] = new int[3], b[] = new int[3], c[] = new int[3], d[] = new int[3],
        p, q, r, s;
    int maxn;
    double sum;

    int i, flag;
    maxn = 100000001;
    while (sc.hasNext()) {
      p = sc.nextInt();
      q = sc.nextInt();
      r = sc.nextInt();
      s = sc.nextInt();

      a[0] = p;
      a[1] = s;
      a[2] = r - s;
      b[0] = r;
      b[1] = q;
      b[2] = p - q;
      for (i = 0; i < 3; i++)
        c[i] = d[i] = 2;
      sum = 1;
      flag = 1;
      while (flag != 0) {
        flag = 0;
        for (i = 0; i < 3; i++) {
          if (sum < maxn && c[i] <= a[i]) {
            flag = 1;
            sum *= c[i]++;
          }
          if (sum > 0.00000001 && d[i] <= b[i]) {
            flag = 1;
            sum /= d[i]++;
          }
        }
      }
      System.out.printf("%.5f\n", sum);
    }
  }
}