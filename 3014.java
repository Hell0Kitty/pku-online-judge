import java.util.*;
import java.io.*;
public class Main{
   static int dp[][]=new int[4501][4501];
  public static void main(String args[]){

    Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while(scan.hasNext()) {
                int n = scan.nextInt();
                int m = scan.nextInt();
                System.out.println(f(n, m));
            }
        }

  public static int f(int n ,int m ){ //m个东西往n个盒子放

   for(int i = 1; i <= m; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (i == j) dp[i][j]++;
            if (j > i) dp[i][j] += dp[i][j - i];
            if (dp[i][j] >= 1000000007) dp[i][j] -= 1000000007;
        }
    }
     return dp[n][m];
  }
}

