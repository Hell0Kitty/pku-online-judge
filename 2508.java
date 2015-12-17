import java.util.*;
public class Main {

  static public void main(String[] str) {
    Scanner sc = new Scanner(System.in);
    double r, h, d1, a1, d2, a2, dg, l, s, a;

    while (sc.hasNext()) {
      r = sc.nextDouble();
      h = sc.nextDouble();
      d1 = sc.nextDouble();
      a1 = sc.nextDouble();
      d2 = sc.nextDouble();
      a2 = sc.nextDouble();
      l = Math.sqrt(r * r + h * h);
      dg = 2 * r * Math.PI / l;
      a = Math.abs(a1 - a2);
      if (a > 180)
        a = 360 - a;
      a = a / 360 * dg;
      s = Math.sqrt(d1 * d1 + d2 * d2 - 2 * d1 * d2 * Math.cos(a));
      System.out.printf("%.2f\n", s);
    }
  }
}