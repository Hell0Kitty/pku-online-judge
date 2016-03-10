import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] nodes = new int[n];

        for (int i = 0; i < n; i++) {
            nodes[i] = sc.nextInt();
        }

        if (n == 1)
            System.out.println(nodes[0]);
        else
            System.out.println(get(nodes));
    }

    private static long get(int[] nodes) {

        long sum = 0;
        int len = nodes.length;
        Arrays.sort(nodes);
        for (int i = 0; i < len - 1; i++) {

            sum += nodes[i] + nodes[i + 1];

            nodes[i + 1] = nodes[i] + nodes[i + 1];

            // System.out.println(nodes[i+1]);

            for (int j = i + 1; j < len - 1; j++) {
                if (nodes[j] > nodes[j + 1]) {
                    int temp = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = temp;
                } else {
                    break;
                }
            }
        }

        return sum;
    }

}

