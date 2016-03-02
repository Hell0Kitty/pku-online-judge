//* @author
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static int a[];
    public static int luckpeople(int n)
    {
        if(n==1)
            return 1;
        if(n%2==1)
            return luckpeople((n-1)/2)*2+1;
        else
            return luckpeople(n/2)*2-1;
    }
    public static int fun(int n)
    {
        int b;
        while(true)
        {
            b=a[n];
            if(b==n)
                return b;
            n=b;
        }
    }
    public static void main(String[] args)
    {
        int i,count;
        //a = new int[110];
        //for(i=1;i<=100;i++)
            //System.out.println(luckpeople(i));
            //a[i]=luckpeople(i);
        //for(i=1;i<=100;i++)
        //System.out.println(fun(i));
        BigInteger n,ans;
        String s;
        Scanner cin = new Scanner (System.in);
        while(cin.hasNext())
        {
            n = cin.nextBigInteger();
            s = n.toString(2);
            count = 0;
            for(i=0;i< s.length();i++)
                if(s.charAt(i)=='1')
                    count++;
            ans=BigInteger.valueOf(2);
            ans = ans.pow(count);
            ans = ans.subtract(BigInteger.ONE);
            System.out.println(ans);
        }

    }

}


