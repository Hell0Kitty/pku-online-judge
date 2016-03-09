//* @author:alpc12
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        new Main().run();

    }

    BigInteger [][] dp;

    private void run() throws FileNotFoundException {
        Scanner cin = new Scanner(System.in);
        //Scanner cin = new Scanner(new BufferedReader(new FileReader("t.in")));
        dp = new BigInteger[19][201];
        for(int i = 0; i < 19; ++i) {
            Arrays.fill(dp[i], BigInteger.ZERO);
        }
        dp[1][0] = BigInteger.ONE;
        for(int i = 2; i < 19; ++i) {
            for(int j = 0; j <= (i-1)*i/2 && j < 201; ++j) {
                for(int k = j; k >= j-i+1 && k >= 0; --k) {
                    dp[i][j] = dp[i][j].add(dp[i-1][k]);
                }
            }
        }
        while(true) {
            int a = cin.nextInt(), b = cin.nextInt();
            if(a == 0 && b == 0)
                break;
            System.out.println(dp[a][b]);
        }

    }

}

