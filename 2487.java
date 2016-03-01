import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {

  private static int partition(int[] array, int low, int high) {
    int key = array[low];
    while (low < high) {
      while (low < high && array[high] >= key) {
        high--;
      }
      array[low] = array[high];
      while (low < high && array[low] <= key) {
        low++;
      }
      array[high] = array[low];
    }
    array[low] = key;
    return low;
  }

  private static void qSort(int[] array, int low, int high) {
    int pivotloc;
    if (low < high) {
      pivotloc = partition(array, low, high);
      qSort(array, low, pivotloc - 1);
      qSort(array, pivotloc + 1, high);
    }
  }

  private static void quickSort(int[] array) {
    int n = array.length - 1;
    qSort(array, 1, n);
  }

  public static void main(String[] args) {
    Scanner scan = new Scanner(new BufferedInputStream(System.in));
    if (scan.hasNext()) {
      int n = scan.nextInt();
      for (int i = 1; i <= n; i++) {
        int stamps = scan.nextInt();
        int friends = scan.nextInt();
        int[] fs = new int[friends + 1];
        for (int j = 1; j <= friends; j++) {
          fs[j] = scan.nextInt();
        }
        quickSort(fs);
        int count = 0;
        int sum = 0;
        for (int k = friends; k >= 1; k--) {
          if (sum < stamps) {
            sum = sum + fs[k];
            count++;
          } else {
            break;
          }
        }
        if (sum < stamps) {
          System.out.println("Scenario #" + i + ":");
          System.out.println("impossible");
          System.out.println();
        } else {
          System.out.println("Scenario #" + i + ":");
          System.out.println(count);
          System.out.println();
        }
      }
    }
  }
}
