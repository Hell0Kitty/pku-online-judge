import java.io.*;
import java.util.*;
import java.math.*;

/**
 *
 * @author gongshaoqing
 */
public class Main {
private static  int  NULL=0;
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int i, j, t;
        int m;
        BigInteger N, b[][], c,ans,temp;
        b = new BigInteger[102][102];
        b[1][1]=BigInteger.ONE;
        b[2][1]=BigInteger.ONE;
        b[2][2]=BigInteger.valueOf(2);
        for (i = 3; i <= 100; i++) {
            b[i][1]=BigInteger.ONE;
            for (j = 2; j <= i; j++) {
                if((i-1)< j)b[i-1][j]=BigInteger.ZERO;
                b[i][j]=b[i-1][j-1].add(b[i-1][j]);
                b[i][j]=b[i][j].multiply(BigInteger.valueOf(j));

            }
        }
        /*for(i=1;i<=100;i++)
        {   for(j=1;j<=i;j++)
                System.out.print(b[i][j]+" ");
            System.out.println();
        }*/
        t=cin.nextInt();
        while(cin.hasNext())
        {
            if(t==0)break;
            t--;
            N=cin.nextBigInteger();
            m=cin.nextInt();
            temp=N.add(BigInteger.ONE);

            ans=BigInteger.ZERO;
            for(i=1;i<=m;i++)
            {
                c=temp.multiply(N);
                temp=c.divide(BigInteger.valueOf(i+1));
                c=temp.multiply(b[m][i]);
                ans=ans.add(c);
                N=N.subtract(BigInteger.ONE);
                if(N.compareTo(BigInteger.ZERO)==0) break;
            }
            System.out.println(ans);
        }
        // TODO code application logic here
    }
}

