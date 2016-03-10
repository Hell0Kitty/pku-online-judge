import java.math.BigInteger;
import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static BigInteger t=new BigInteger("1");
    static BigInteger c[][] = new BigInteger [210][210];

    /**//*
    static BigInteger C(int n,int m)
    {
        if(m==0||m==n)
            return BigInteger.ONE;
        BigInteger res=new BigInteger("1");
        int i;
        for(i=n;i>=n-m+1;i--)
            res=res.multiply(BigInteger.valueOf(i));
        for(i=m;i>=1;i--)
            res=res.divide(BigInteger.valueOf(i));
        return res;
    }
    */

    static int a[]=new int[202];
    static BigInteger ans[]=new BigInteger [202];

    /** *//**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        for(int i=0;i<=200;i++) c[i][0]=c[i][i]=BigInteger.ONE;
        for(int i=2;i<=200;i++)
        {
            for(int j=1;j< i;j++)
            {
                c[i][j]=c[i-1][j].add(c[i-1][j-1]);
            }
        }
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        while(cin.hasNext())
        {

            n=cin.nextInt();
            t=cin.nextBigInteger();
            int i,j;
            for(i=0;i<=n;i++)
                a[i]=cin.nextInt();
            for(i=0;i<=n;i++)
                ans[i]=BigInteger.ZERO;

            for(i=0;i<=n;i++)
                for(j=i;j<=n;j++)
                   if(j-i< i)
                    ans[i]=ans[i].add(c[j][j-i].multiply(t.pow(j-i)).multiply(BigInteger.valueOf(a[j])));
                   else
                    ans[i]=ans[i].add(c[j][i].multiply(t.pow(j-i)).multiply(BigInteger.valueOf(a[j])));
            for(i=0;i< n;i++)
            {
                System.out.print(ans[i]);
                System.out.print(" ");
            }
             System.out.println(ans[n]);

            /**//*
            String res=new String ("");
            for(i=0;i< n;i++)
            {
                res+=ans[i].toString();
                res+=" ";
            }
            res+=ans[n].toString();
            System.out.print(res);
            System.out.println();
             * */

       }

    }
}

