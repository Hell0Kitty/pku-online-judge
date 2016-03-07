import java.util.*;
import java.math.BigInteger;

public class Main {


    public static void main(String[] args)
    {
        BigInteger a[]=new BigInteger[105];
        int i,k;
        BigInteger temp;
        a[1]=new BigInteger("1");
        for(i=2;i<=100;i++)
        {
            temp=new BigInteger("1");
            for(k=1;k<i;k++)
            {
                temp=temp.add(a[k]);
            }
            a[i]=temp.add(a[i-1]);
        }
        Scanner stdin=new Scanner(System.in);
        while(stdin.hasNext())
        {
            int n=stdin.nextInt();
            System.out.println(a[n]);
        }
    }
}