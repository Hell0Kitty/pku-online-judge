import java.util.*;
import java.io.*;

public
class Main {
public
  static void main(String[] args) {
    Scanner scanner =
        new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int t = scanner.nextInt();
    int n, max;
    int[] r;
    for (int i = 0; i < t; i++) {
      n = scanner.nextInt();
      r = new int[n];
      for (int j = 0; j < n; j++) {
        r[j] = scanner.nextInt();
      }
      intSort(r, 0, n - 1);
      max = n * r[0];
      for (int j = 1; j < n; j++) {
        if ((n - j) * r[j] > max) {
          max = (n - j) * r[j];
        }
      }
      System.out.println(max);
    }
  }

public
  static void intSort(int[] number, int left, int right) {
    if (left < right) {
      int s = number[(left + right) / 2];
      int i = left - 1;
      int j = right + 1;
      while (true) {
        while (number[++i] < s)
          ;
        while (number[--j] > s)
          ;
        if (i >= j)
          break;
        swap(number, i, j);
      }
      intSort(number, left, i - 1);
      intSort(number, j + 1, right);
    }
  }

public
  static void swap(int[] number, int i, int j) {
    int t;
    t = number[i];
    number[i] = number[j];
    number[j] = t;
  }
}