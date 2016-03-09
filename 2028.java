import java.awt.Label;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
 public static void main(String[] args) {
  Scanner in = new Scanner(System.in);
   while (true) {

    int n = in.nextInt();
    int q = in.nextInt();
    if ((n | q) == 0)
          break;
      Map< Integer, Integer> map = new HashMap< Integer, Integer>();
      for (int i = 0; i < n; i++) {
       int m = in.nextInt();
       for (int j = 0; j < m; j++) {
       int temp = in.nextInt();
        if (map.get(temp) == null)
            map.put(temp, 1);
        else
            map.put(temp, map.get(temp) + 1);
        }
      }
    Set< Integer> key = map.keySet();
    int max = 0;
    int keyValue = 0;
    for (Integer i : key) {
        if (map.get(i) > max) {
            max = map.get(i);
            keyValue = i;
        }
        if (map.get(i) == max) {
            if (i <= keyValue)
                      keyValue = i;
        }
    }
    if (max < q)
        System.out.println(0);
    else
            System.out.println(keyValue);
    }
  }
}

