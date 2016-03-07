/*
 题意：给定N台电脑和K辆卡车，要求每辆卡车至少放一台电脑。问共有多少种放法？
数据范围N (1<=N<=200) and K(1<=K<=N)。

分析：典型dp，状态转移方程dp[i][j]=dp[i-1][j-1]+dp[i][j-i]；dp[i][j]表示i辆卡车装j台电脑的方法数。*/
import java.util.*;
public class Main{

   private long dp[][]=new long[201][201];

   public Main(){
     init();
    }
   private  void init(){
      for(int i=1;i<201;i++)
    {
        dp[i][i]=dp[1][i]=dp[i][0]=dp[0][i]=1;
    }
    for(int i=2;i<201;i++)
    {
        for(int j=i+1;j<201;j++)
        {

            dp[i][j]=dp[i-1][j-1]+dp[i][j-i];
        }
    }
   }
 
  public long dp(int k,int n){
     return dp[k][n];
  }
    
  
   public static void main(String args[]){
       Scanner in=new Scanner(System.in);
       Main m=new Main();
       while(true){
         int n=in.nextInt();
         int k=in.nextInt();
         if(n==0 && k==0) break;
         System.out.println(m.dp(k,n));
        }
     }
}