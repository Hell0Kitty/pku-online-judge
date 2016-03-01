//* @author
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    static boolean h[];
    public static void main(String[] args)
    {
        int m,i,j=2;
        h=new boolean[1000005];
        BigInteger n,p,q,nn;
        for(i=1;i<=1000001;i++)
            h[i]=true;
        for(i=2;i<=1000001;i+=2)
            h[i]=false;
        h[1]=false;h[2]=true;
        for(i=3;i<=1000;i+=2)
        {
          if(h[i]==true)
          {
              j=2;
              while(i*j<=1000000)
              {
                  h[i*j]=false;
                  j++;
              }
          }
        }
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext())
        {
            j=1000100;
            n=cin.nextBigInteger();
            m=cin.nextInt();
            nn=BigInteger.ZERO;
            if(n.compareTo(nn)==0&&m==0)
                break;
          for(i=2;i<=1000000;i++)
          {
          if(h[i]==true)
          {
            p=n.divide(BigInteger.valueOf(i));
            q=p.multiply(BigInteger.valueOf(i));
            if(q.compareTo(n)==0)
            {
                j=i;
                break;
            }
          }
         }
            if(j< m)
                System.out.println("BAD "+j);
            else
                System.out.println("GOOD");
        }
    }
}

