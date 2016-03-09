import java.io.*;
import java.util.*;
import java.math.*;


public class Main {

  static int N = 26;
  int n;
  int M;
  int[][] adj = new int[26][26];
  boolean[] chk = new boolean[26];

  boolean DFS(int K, int m) {
   chk[m] = true;
   if(m == 1)
       return true;
   int i;
   for(i = 0; i < n; ++i) if(!chk[i])
    if(adj[m][i]!=0 && adj[m][i] % K == 0)
         if(DFS(K, i))
        return true;
    return false;
   }

 BigInteger GCD(BigInteger x, BigInteger y) {
   if(x.compareTo(y) < 0)
    return GCD(y, x);
   while(y.compareTo(BigInteger.ZERO) > 0) {
    BigInteger tmp = y;
    y = x.mod(y);
    x = tmp;
   }
   return x;
 }

 BigInteger LCM(BigInteger x, BigInteger y) {
   BigInteger ret = x.multiply(y);
   ret = ret.divide(GCD(x, y));
   return ret;
  }

  void run() {
   Scanner cin = new Scanner(System.in);
   n = cin.nextInt();
   int i, j;
   M = 0;
   for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j) {
         adj[i][j] = cin.nextInt();
      if(adj[i][j] > M)
        M = adj[i][j];
    }

    BigInteger ans = new BigInteger("1");
    for(i = 1; i <= M; ++i) {
      for(j = 0; j < n; ++j)
        chk[j] = false;
      if(DFS(i, 0)) {
//      System.out.println(i + " " + ans);
        ans = LCM(ans, new BigInteger(""+i));
       }
    }
    System.out.println(ans);
    }

  public static void main(String[] args) {
    new Main().run();

  }

}

