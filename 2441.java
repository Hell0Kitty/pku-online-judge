import java.util.*;
public class Main
{
 static final int N=20+2;
 static final int M=1<< 20+1;

 public static void main(String[] args){
   Scanner sc=new Scanner(System.in);
  int n, m, p;
   int mat[][]=new int[N][N];
   int dp[][]=new int[2][M];
   int i, k, j, next;
   n=sc.nextInt();
   m=sc.nextInt();
   for (i = 1; i <= n; i++)
   {
     p=sc.nextInt();
     while ((p--)!=0)
    {
     k=sc.nextInt();
     mat[i][k] = 1;
    }
  }

  int s = 0;
  dp[s][0] = 1;
  for (i = 1; i <= n; i++)
 {
   for (j = 0; j < (1 << m); j++)
   {
     if (dp[s][j]!=0)
     {
      for (k = 1; k <= m; k++)
      {
       if (mat[i][k] == 1)
       {
         next = j | (1 << (k - 1));
         if (next != j)      // 第k个barn没被占用
            dp[(s + 1) % 2][next] += dp[s][j];
       }

     }
    dp[s][j] = 0;
  }
 }

 s = (s + 1) % 2;
}
 int sum = 0;
 for (i = 0; i < (1 << m); i++) sum += dp[s][i];
      System.out.printf("%d\n", sum);
}
}

