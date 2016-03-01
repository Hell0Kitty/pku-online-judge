import java.io.BufferedInputStream;
import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            int n = scan.nextInt();
            int[] data = new int[n];
            int[] count = new int[n];
            for (int i = 0; i < n; i++) {
                int a = scan.nextInt();
                data[i] = a;
                count[i] = 1;
                int max = count[i];
                int flag = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (data[i] > data[j]) {
                        if (count[j] > max) {
                            max = count[j];
                        }
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    count[i] = max + 1;
                }
            }
            int max = count[0];
            for (int i = 1; i < n; i++) {
                if (count[i] > max) {
                    max = count[i];
                }
            }
            System.out.println(max);
        }
    }
}

