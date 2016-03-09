//* @author:
import java.util.*;
public class Main
{
 public static void main(String[] args){
   Scanner sc=new Scanner(System.in);

   long dp[][]=new long[11][2010];
   int nn=sc.nextInt();
   for (int i=1;i<=2000;i++) dp[1][i]=1;
   for (int i=2;i<=10;i++)
        for (int j=i;j<=2000;j++)
        for (int k=1;k<=j/2;k++) dp[i][j]+=dp[i-1][k];
    for (int ii=1;ii<=nn;ii++) {
        int n=sc.nextInt();
        int m=sc.nextInt();
     long ans=0;
    for (int i=n;i<=m;i++) ans+=dp[n][i];
    System.out.printf("Case %d: n = %d, m = %d, # lists = %d\n",ii,n,m,ans);
    }
  }
}

