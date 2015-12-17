Source Code

Problem: 1784   User: freebsdx
Memory: 5612K   Time: 375MS
Language: Java    Result: Accepted
Source Code
import java.util.Scanner;
public class Main {

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);

  int p[]=new int[202];
  int q[]=new int[202];
  int s[][]=new int[202][202];
  int ans[][]=new int[202][202];
  int sum[]=new int[202];
  int n , i, j, l, k, temp, r;
  while(sc.hasNext())
  {
  n=sc.nextInt();
  if( n == 0 ) break;
  for( i=1; i<=n; i++ )
  {
           p[i]=sc.nextInt();
           sum[i] = p[i];
  }

  sum[0] = 0;
  sum[n+1] = 0;
  p[n+1] = 0;
  for( i=0; i<=n; i++ )
  {
           q[i]=sc.nextInt();
           sum[i+1] += sum[i] + q[i];
  }

  for( i=1; i<=n; i++ )
  {
     ans[i][i] = p[i] + q[i-1] + q[i];
     ans[i][i-1] = 0;
     s[i][i] = i;
  }
  ans[n+1][n] = 0;

  for( l=1; l< n; l++ )
    for( i=1; i+l<=n; i++ )
    {
      j = i+l;
      ans[i][j] = 999999999;
      for( k = s[i][j-1]; k<=s[i+1][j]; k++ )
      {
    if( ( temp = ans[i][k-1] + ans[k+1][j] ) < ans[i][j] )
    {
       ans[i][j] = temp;
       s[i][j] = k;
    }
      }
          ans[i][j] += sum[j+1] - p[j+1] - sum[i-1];
  }
  System.out.printf( "%d\n", ans[1][n] );
     }
   }
}