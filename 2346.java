import java.util.*;
/**
 *
 * @author leo
 */
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n, max=0;
        int[][] dp = new int[6][46];
        for(int i=0;i<=9;i++){
            dp[1][i]=1;
        }
        for(int i=1;i<=5;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=5;i++){
            for(int j=1;j<=i*9;j++){
                if(j< 10) dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-10];
            }
        }

        n = sc.nextInt();
        for(int i=0;i<=(n*9)/2;i++){
            max+=(dp[n/2][i]*dp[n/2][i]);
        }
        System.out.println(max);
    }
}

