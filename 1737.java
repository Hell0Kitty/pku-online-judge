import java.util.*;
import java.math.*;

public class Main
{
   BigInteger[] ans = new BigInteger[52];
   public Main()
   {
      DP();
      solve();
   }
   //求组合数
   BigInteger combinationNum(int n, int m)
   {
      BigInteger ret = new BigInteger("1");
      int i;
      for (i = 0; i < m; ++i)
      {
         ret = ret.multiply(new BigInteger(n - i + ""));
         ret = ret.divide(new BigInteger(i + 1 + ""));
      }
      return ret;
   }

    void DP()
   {
      ans[1] = new BigInteger("1");
      ans[2] = new BigInteger("1");
      int i, j;
      BigInteger tmp = new BigInteger("0");
      BigInteger com = new BigInteger("0");
      for (i = 3; i <= 50; ++i)
      {
         ans[i] = new BigInteger("0");
         for (j = 1; j < i; ++j)
         {
            com = combinationNum(i - 2, j - 1);
            tmp = ans[j].multiply(ans[i - j]);
            tmp = tmp.multiply(com);
            tmp = tmp.multiply(new BigInteger(((long)1 << j) - 1 + ""));
            ans[i] = ans[i].add(tmp);
         }
      }
      //for (i = 1; i <= 50; ++i)
      //   System.out.println(i + ": " + ans[i]);
   }
    void solve()
    {
       int n;
       Scanner cin = new Scanner(System.in);
       while (true)
       {
          n = cin.nextInt();
          if (n == 0)
             return;
          System.out.println(ans[n]);
       }
    }

   public static void main(String args[])
   {
      new Main();
   }
}
