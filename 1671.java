import java.util.*;
public class Main{
 
 static double dp[][]=new double[51][51];
 static {
   dp[1][1]=1;
   for (int i=2;i<=50;i++)
     for(int j=1;j<=50;j++)
	dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
  }


public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
	while (sc.hasNext()) {
        int n=sc.nextInt();
        if(n==0) break;
	 double ans=0;
	 for (int i=1;i<=n;i++)
          ans+=dp[n][i];
	 System.out.printf("%d %.0f\n",n,ans);
	}
  }
}