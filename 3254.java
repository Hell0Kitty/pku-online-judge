import java.util.ArrayList;
    import java.util.List;
    import java.util.Scanner;

    public class Main{

        static int n,m;
        static List< Integer> num[] = new ArrayList[13];
        static int dp[][] = new int[13][1024];

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            m = scan.nextInt();
            n = scan.nextInt();

            for(int i=0;i< 13;i++)
                num[i] = new ArrayList< Integer>();

            for(int i=0;i< m;i++){
                int temp = 0;
                for(int j=0;j< n;j++){
                    int a = scan.nextInt();
                    a = 1 - a;
                    temp = temp*2+a;
                }
                getNum(i,temp);
            }

            for(int i=0;i< num[0].size();i++)
                dp[0][i] = 1;

            for(int i=1;i< m;i++){
                for(int j=0;j< num[i].size();j++){
                    for(int k=0;k< num[i-1].size();k++){
                        if((num[i].get(j)&num[i-1].get(k))!=0)
                            continue;
                        dp[i][j] += dp[i-1][k];
                    }
                }
            }

            int ans = 0;
            for(int j=0;j< num[m-1].size();j++){
                ans += dp[m-1][j];
                ans %= 1000000000;
            }

            System.out.println(ans);

        }

        public static void getNum(int r, int temp) {

            for(int i=0;i<(1<< n);i++){
                if(((i<< 1)&i)!=0||((i>>1)&i)!=0) //处理连续的1
                    continue;
                if((i&temp)!=0)
                    continue;  // 处理 原来 为0的位置   不能放牛
                num[r].add(i);
            }

        }

    }
