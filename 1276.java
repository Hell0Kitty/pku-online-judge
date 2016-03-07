import java.util.Scanner;

public class Main {

    static int[] value = new int[100];
    static int[] dp = new int[100001];

    public static void main(String[] args) {
        Scanner s;
        try {
            // s = new Scanner(new InputStreamReader(new FileInputStream(
            // "c:\\1.txt")));
            s = new Scanner(System.in);
            while (s.hasNextInt()) {

                int total = s.nextInt();
                int kind = s.nextInt();

                int count = 0;

                for (int i = 0; i < kind; i++) {
                    int a = s.nextInt();
                    int b = s.nextInt();
                    int k = 1;
                    while (a - k >= 0) {
                        a -= k;
                        value[count++] = k * b;
                        k *= 2;
                    }
                    if (a > 0)
                        value[count++] = a * b;

                }
                if (total == 0 || kind == 0 || count == 0) {
                    System.out.println(0);
                    continue;
                }
                for (int i = 1; i <= total; i++)
                    dp[i] = 0;
                dp[0] = 1;
                for (int i = 0; i < count; i++)
                    for (int j = total; j >= value[i]; j--)
                        if (dp[j] == 0)
                            dp[j] = dp[j - value[i]];
                for (int i = total; i >= 0; i--)
                    if (dp[i] > 0) {
                        System.out.println(i);
                        break;
                    }

            }

        } catch (Exception e) {
            System.exit(0);
        }

    }

}