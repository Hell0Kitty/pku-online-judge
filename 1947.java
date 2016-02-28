    import java.util.ArrayList;
    import java.util.List;
    import java.util.Scanner;

    public class Main{

        public static final int MAX = 152;
        static List< Integer> v[];
        static int dp[][];
        static int p;
        static int root;

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            int n = scan.nextInt();
            p = scan.nextInt();

            boolean s[] = new boolean[n+1];
            v = new ArrayList[n+1];
            java.util.Arrays.fill(s, true);
            dp = new int[n+1][p+1];

            for(int i=0;i<=n;i++)
                java.util.Arrays.fill(dp[i], MAX);

            for(int i=1;i<=n;i++)
                v[i] = new ArrayList< Integer>();

            for(int i=1;i< n;i++){
                int u = scan.nextInt();
                int t = scan.nextInt();
                v[u].add(t);
                s[t] = false;
            }

            for(int i=1;i<=n;i++){
                if(s[i]){
                    root = i;
                    dfs(root);
                    break;
                }
            }

            int ans = MAX;
            for(int i=1;i<=n;i++)
                ans = Math.min(ans,dp[i][p]);

            System.out.println(ans);

        }

        public static void dfs(int u) {

            for(int i=0;i< v[u].size();i++){

                dfs(v[u].get(i));

            }

            if(u == root)
                dp[u][1] = v[u].size();
            else
                dp[u][1] = v[u].size()+1;

         for(int i=0;i< v[u].size();i++){
            for(int j=p-1;j>=1;j--){
               if(dp[u][j]< MAX){
                 for(int k=1;k+j<=p;k++){
                   if(dp[u][k]< MAX){
                      dp[u][j+k] = Math.min(dp[u][j+k], dp[u][j]+dp[v[u].get(i)][k]-2);//每次加一个子树 更新d[u][2..P]
                            }
                        }
                    }
                }
            }

        }

    }

