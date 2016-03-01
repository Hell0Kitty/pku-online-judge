import java.util.Scanner;
public class Main{
 public static void main(String args[]){

  int data[]=new int[100000];
  int dp[]=new int[100000];
  int n;
  Scanner in=new Scanner(System.in);
    while((n=in.nextInt())!=0){

        int sum = 0, tmp = -999999999;
        for(int i = 0; i < n; i++){
            data[i]=in.nextInt();
            sum += data[i];
            if(sum > tmp)
                tmp = sum;
            dp[i] = tmp;
            if(sum < 0)
                sum = 0;
        }
        sum = 0;
        int ans = -999999999;
        for(int i = n-1; i > 0; i--){
            sum += data[i];
            if(dp[i-1]+sum > ans)
                ans = dp[i-1]+sum;
            if(sum < 0)
                sum = 0;
        }
        System.out.printf("%d\n", ans);
    }
 }
}

