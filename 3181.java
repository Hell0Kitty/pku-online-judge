//* @author:alpc12
import java.io.*;
import java.util.*;
import java.math.*;


public class Main {
 final int N = 1010;
 BigInteger[] dp = new BigInteger[N];

 void run() {
  Scanner cin = new Scanner(System.in);
  while(cin.hasNext()) {
    int i, j;
    int n = cin.nextInt(), k = cin.nextInt();
    for(i = 1; i <= n; ++i)
    dp[i] = BigInteger.ZERO;
    dp[0] = BigInteger.ONE;
    for(i = 1; i <= k; ++i) {
      for(j = 0; j + i <= n; ++j)
        dp[j+i] = dp[j+i].add(dp[j]);
    }
    System.out.println(dp[n]);
   }
 }

 public static void main(String[] args) {
    new Main().run();

 }

}

