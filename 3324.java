//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
 public static void main(String args[]) throws Exception {
    Scanner cin=new Scanner(System.in);
    BigInteger s,M;
    int p,i;
    while(cin.hasNext())
    {
        p=cin.nextInt();
        s=BigInteger.valueOf(4);
        M=BigInteger.ONE;
        M=M.shiftLeft(p).subtract(BigInteger.ONE);
        for(i=0;i< p-2;++i)
        {
            s=s.multiply(s).subtract(BigInteger.valueOf(2));
            while(s.bitLength()>p)
            {
                s=s.shiftRight(p).add(s.and(M));
            }
        }
        if(s.compareTo(BigInteger.ZERO)==0||s.compareTo(M)==0)
        {
            System.out.println(0);
            continue;
        }
        String ans="";
        while(s.compareTo(BigInteger.ZERO)>0)
        {
            long buf=s.mod(BigInteger.valueOf(16)).longValue();
            ans+=Integer.toHexString((int)buf);
            s=s.divide(BigInteger.valueOf(16));
        }
        for(i=ans.length()-1;i>=0;--i)System.out.print(ans.charAt(i));
        System.out.println();
    }
  }
}

