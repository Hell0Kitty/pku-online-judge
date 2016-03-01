//* @author
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        int n;
        BigInteger two,ans;
        Scanner cin = new Scanner (System.in);
        while(cin.hasNext())
        {
            n = cin.nextInt();
            two = BigInteger.valueOf(2);
            ans = two;
            if(n%2==0)
            {
                ans=ans.pow(n-1).subtract(two).divide(BigInteger.valueOf(3)).add(BigInteger.ONE);
            }
            else
            {
                ans=ans.pow(n-1).subtract(BigInteger.ONE).divide(BigInteger.valueOf(3));
            }
            System.out.println(ans);
        }
    }
}

(2)
import java.util.*;
import java.math.*;

 public class Main{
    public static void main(String[] args){
     int n;
      BigInteger  a[]=new  BigInteger[1001];
     a[1]=BigInteger.ZERO;
     for(int i=2;i<=1000;i++){
           if(i%2==0) a[i]=a[i-1].multiply(BigInteger.valueOf(2)).add(BigInteger.ONE);
           else       a[i]=a[i-1].multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
        }
     Scanner cin = new Scanner(System.in);
     while(cin.hasNext())
        {
       n = cin.nextInt();
       System.out.println(a[n]);
     }
   }
}

