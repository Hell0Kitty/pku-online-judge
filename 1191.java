import java.util.*;  
public class Main   
{  
    static int min(int a,int b){return (a>b)? b:a;}  
    static double min(double a,double b){return (a>b)? b:a;}  
    final int Max_Int=200000000;  
    static double qr(double x){return x*x;}  
    public static void main(String[] args)  
    {  
        Scanner cin=new Scanner(System.in);  
        int a[][]=new int[10][10],s[][]=new int [10][10],sum[][][][]=new int[9][9][9][9];  
        double dp[][][][][]=new double [9][9][9][9][17];  
        int n=cin.nextInt();  
        double tot=0,ave=0;  
        for(int i=1;i<=8;i++)  
        {  
            s[i][0]=0;  
            for(int j=1;j<=8;j++)  
            {     
                a[i][j]=cin.nextInt();  
                tot+=(double)a[i][j];  
                s[i][j]=s[i][j-1]+a[i][j];  
            }  
        }  
        ave=tot/(double)n;  
        for(int i=1;i<=8;i++)  
            for(int j=i;j<=8;j++)  
                for(int k=1;k<=8;k++)  
                    for(int l=k;l<=8;l++)  
                    {  
                        sum[i][j][k][l]=0;  
                        for(int t=i;t<=j;t++)  
                            sum[i][j][k][l]+=s[t][l]-s[t][k-1];  
                        dp[i][j][k][l][1]=qr(sum[i][j][k][l]-ave);  
                    }  
        for(int v=2;v<n;v++)  
            for(int i=1;i<=8;i++)  
                for(int j=i;j<=8;j++)  
                    for(int k=1;k<=8;k++)  
                        for(int l=k;l<=8;l++)  
                        {  
                            dp[i][j][k][l][v]=100000000.0;  
                            for(int t=i;t<j;t++)  
                                dp[i][j][k][l][v]=min(dp[i][j][k][l][v],dp[i][t][k][l][v-1]+dp[t+1][j][k][l][1]);  
                            for(int t=i;t<j;t++)  
                                dp[i][j][k][l][v]=min(dp[i][j][k][l][v],dp[t+1][j][k][l][v-1]+dp[i][t][k][l][1]);  
                            for(int t=k;t<l;t++)  
                                dp[i][j][k][l][v]=min(dp[i][j][k][l][v],dp[i][j][k][t][v-1]+dp[i][j][t+1][l][1]);  
                            for(int t=k;t<l;t++)  
                                dp[i][j][k][l][v]=min(dp[i][j][k][l][v],dp[i][j][t+1][l][v-1]+dp[i][j][k][t][1]);  
                        }  
        dp[1][8][1][8][n]=100000000.0;  
        for(int t=1;t<8;t++)  
            dp[1][8][1][8][n]=min(dp[1][8][1][8][n], dp[1][t][1][8][n-1]+dp[t+1][8][1][8][1]);  
        for(int t=1;t<8;t++)  
            dp[1][8][1][8][n]=min(dp[1][8][1][8][n], dp[t+1][8][1][8][n-1]+dp[1][t][1][8][1]);  
        for(int t=1;t<8;t++)  
            dp[1][8][1][8][n]=min(dp[1][8][1][8][n], dp[1][8][1][t][n-1]+dp[1][8][t+1][8][1]);  
        for(int t=1;t<8;t++)  
            dp[1][8][1][8][n]=min(dp[1][8][1][8][n], dp[1][8][t+1][8][n-1]+dp[1][8][1][t][1]);  
        System.out.printf("%.3f", Math.sqrt(dp[1][8][1][8][n]/(double)n));  
    }  
}  
