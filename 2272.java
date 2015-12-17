import java.util.*;
public class Main {

  public static int score(double x, double y) {
    double r = x * x + y * y;
    if (r <= 9.)
      return 100;
    if (r <= 36.)
      return 80;
    if (r <= 81.)
      return 60;
    if (r <= 144.)
      return 40;
    if (r <= 225.)
      return 20;
    return 0;
  }
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    double x, y;
    int sum1, sum2;
    while (true) {
      sum1 = 0;
      sum2 = 0;
      x = sc.nextDouble();
      y = sc.nextDouble();
      if (x == -100)
        break;
      sum1 += score(x, y);
      for (int i = 1; i <= 2; i++) {
        x = sc.nextDouble();
        y = sc.nextDouble();
        sum1 += score(x, y);
      }
      for (int i = 1; i <= 3; i++) {
        x = sc.nextDouble();
        y = sc.nextDouble();
        sum2 += score(x, y);
      }
      if (sum1 > sum2)
        System.out.println("SCORE: " + sum1 + " to " + sum2 +
                           ", PLAYER 1 WINS.");
      else if (sum1 == sum2)
        System.out.println("SCORE: " + sum1 + " to " + sum2 + ", TIE.");
      else
        System.out.println("SCORE: " + sum1 + " to " + sum2 +
                           ", PLAYER 2 WINS.");
    }
  }
}