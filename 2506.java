import java.util.*;
import java.math.*;
public class Main{
 static BigInteger[] ans;
 public static void main(String args[])
  {
   Scanner sc=new Scanner(System.in);
   ans=new BigInteger[251];
   ans[0]=BigInteger.valueOf(1);
   ans[1]=BigInteger.valueOf(1);
   ans[2]=BigInteger.valueOf(3);
   for(int i=3;i<=250;i++)
    ans[i]=ans[i-1].add(ans[i-2].multiply(BigInteger.valueOf(2)));
   while(sc.hasNextInt()){
    int n=sc.nextInt();
    System.out.println(ans[n]);
   }
  }
}


