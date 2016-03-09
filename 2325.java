//* @author
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        BigInteger n,zero,ten;
        int count,flag,a[],i,j;
        a=new int[2000];
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            n = cin.nextBigInteger();
            zero=BigInteger.ZERO;
            ten=BigInteger.TEN;
            if(n.compareTo(BigInteger.valueOf(-1))==0)
               break;
            if(n.compareTo(ten)< 0)//n< 10
            {
                System.out.println("1"+n);
                continue;
            }
            flag=0;count=0;
            while(true)
            {
                flag=0;
                for(i=9;i>=2;i--)
                {
                    if(n.mod(BigInteger.valueOf(i)).compareTo(zero)==0)
                    {
                        flag=1;
                        a[++count]=i;
                        n=n.divide(BigInteger.valueOf(i));
                        break;
                    }
                }
                if(n.compareTo(ten)< 0)
                {
                    flag=1;
                    a[++count]=n.intValue();
                    break;
                }
                if(flag==0)//如果存在对于每一个i都不整除的话
                    break;
            }
            if(flag==0)
                System.out.println("There is no such number.");
            else
            {
                for(i=count;i>=1;i--)
                    System.out.print(a[i]);
                System.out.println();
            }
        }
    }

 }

