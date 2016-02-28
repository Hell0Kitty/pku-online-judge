import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    BigInteger[][] dp = new BigInteger[51][51];

    BigInteger go(int n, int y) {
        if (y == 1)
            return BigInteger.ONE;
        if (n < y || y < 1)
            return BigInteger.ZERO;
        if(dp[n][y] != null) {
            return dp[n][y];
        }
        return (dp[n][y] =
            go(n-1, y).multiply(new BigInteger(""+y))
            .add(go(n-1, y-1).multiply(new BigInteger(""+(2*n-y)))));
    }

    void run() {
        Scanner cin = new Scanner(System.in);
        int ntc = cin.nextInt();

        for (int i = 0; i < ntc; ++i) {
            int n = cin.nextInt();
            int y = cin.nextInt();

            System.out.println(go(n, y));
        }
    }

    public static void main(String[] args) {
        new Main().run();

    }

}
