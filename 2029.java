mport java.io.*;
import java.util.*;

public class Main {

/**
 * @param args
 */
 static int max(int a,int b)
 {
   if(a>b) return a;
    return b;
 }

  public static void main(String[] args) {
    // TODO Auto-generated method stub
    int k,n,m,a,b;
    int i,j;

    int DP[][] = new int[110][110];

    Scanner cin = new Scanner(System.in);

    while(cin.hasNext())
     {
    k = cin.nextInt();
    if(k==0) break;

    n = cin.nextInt();
    m = cin.nextInt();
    for(i=0;i< 110;++i) for(j=0;j< 110;++j)
        DP[i][j]=0;
    for(i=0;i< k;++i)
    {
        a = cin.nextInt();
        b = cin.nextInt();
        DP[a][b]=1;
    }

    a = cin.nextInt();
    b = cin.nextInt();

    for(i=1;i<=n;++i) for(j=1;j<=m;++j)
    {
        DP[i][j]=DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1]+DP[i][j];
    }

    k = 0;
    for(i=1;i<=n;++i) for(j=1;j<=m;++j) if(i>=a&&j>=b)
    {
        k = max(k,DP[i][j]-DP[i-a][j]-DP[i][j-b]+DP[i-a][j-b]);
    }
    System.out.println(k);
   }

 }
}

