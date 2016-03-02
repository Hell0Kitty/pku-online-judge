    import java.util.Scanner;

    public class Main{

        static double p[][];
        static double dp[][];

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            while (true) {
                int N = scan.nextInt();
                if (N == -1)
                    break;
                int n = 1 << N;

                p = new double[n][n];
                dp = new double[n][n];

                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        p[i][j] = scan.nextDouble();

                java.util.Arrays.fill(dp[0], 1);

                for(int i=1;i<=N;i++){
                    for(int j=0;j< n;j++){
                        for(int k=0;k< n;k++)
  // 相邻的两个 是对手(只处理个位)不影响个位以上的数字,个位以上不同,说明不可能是对手
                            if(((k>>(i-1))^1)==(j>>(i-1)))
                                dp[i][j] += dp[i-1][j]*dp[i-1][k]*p[j][k];
                    }
                }

                int ans = 0;

                for(int i=1;i< n;i++)
                    if(dp[N][i]>dp[N][ans])
                        ans = i;

                System.out.println(ans+1);

            }

        }

    }

