
import java.util.*;
import java.lang.*;
import java.io.*;
import java.text.*;

public class Main {
  public static void main(String[] args) throws IOException {
    Date twoK, res, t1, t2;
    long twoKl, resl, t;

    SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd EEEE", Locale.US);
    // BufferedInputStream bin = new BufferedInputStream(new
    // FileInputStream("in.txt"));
    // System.setIn(bin);
    Scanner cin = new Scanner(System.in);
    twoK = new Date(100, 0, 1, 8, 0, 0);
    twoKl = twoK.getTime();
    t1 = new Date(100, 0, 1, 8, 0, 0);
    t2 = new Date(100, 0, 2, 8, 0, 0);
    t = t2.getTime() - t1.getTime(); //计算一天的getTime()差值
    while (cin.hasNext()) {
      resl = cin.nextLong();
      if (resl == -1) {
        break;
      }
      resl = resl * t + twoKl;
      res = new Date(resl);
      System.out.println(sdf.format(res));
    }
  }
}