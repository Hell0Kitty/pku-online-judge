import java.io.BufferedInputStream;
import java.util.Scanner;
public class Main {

    static long num = 0;

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            int n = scan.nextInt();
            if (n == 0) {
                break;
            }
            num = 0;
            int data[] = new int[n];
            for (int i = 0; i < n; i++) {
                data[i] = scan.nextInt();
            }
            mergeSort(data, 0, n - 1);
            System.out.println(num);
        }
    }

    static void mergeSort(int[] array, int left, int right) {

        if (left < right) {
            int center = (left + right) / 2;
            mergeSort(array, left, center);
            mergeSort(array, center + 1, right);
            Merge(array, left, center, right);
        }
    }

    static void Merge(int[] array, int left, int center, int right) {
        //[1,2,3,4] left=1,ceter=2,right=4
        int[] temp = new int[right - left + 1];
        int i = left;
        int j = center + 1;
        int k = 0;
        while (i <= center && j <= right) {
            if (array[i] > array[j]) {
                temp[k++] = array[j++];

                num += center - i + 1;

            } else {
                temp[k++] = array[i++];
            }
        }
        while (i <= center) {
            temp[k++] = array[i++];
        }
        while (j <= right) {
            temp[k++] = array[j++];
        }
        for (i = left, k = 0; i <= right; i++, k++) {
            array[i] = temp[k];
        }
    }
}

