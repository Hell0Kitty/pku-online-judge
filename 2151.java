//* @author: 
import java.util.*;
public class Main
{
 
 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   double dp[][]=new double[40][40];
   int n,m,t;
   double p,e,tp;
   while (sc.hasNext()) {
     m=sc.nextInt();
     if(m==0) break;    

     t=sc.nextInt();
     n=sc.nextInt();
     e=tp=1;
     for (int i=1;i<=t;i++) {
     double tem=0;
     dp[0][0]=1;
     for (int j=1;j<=m;j++) {
      p=sc.nextDouble();
      if (j==1) {
        dp[1][0]=1-p;
        dp[1][1]=p;
      }
      else {
        dp[j][0]=dp[j-1][0]*(1-p);
        for (int k=1;k<=j;k++) dp[j][k]=dp[j-1][k-1]*p+dp[j-1][k]*(1-p);
      }
    }
    for (int j=1;j< n;j++) tem+=dp[m][j];
       tp*=tem;
    for (int j=n;j<=m;j++) tem+=dp[m][j];
    e*=tem;
    }
    System.out.printf("%.3f\n",e-tp);
   }
  }
}

