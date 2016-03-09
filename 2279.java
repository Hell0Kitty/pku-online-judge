//* @author: ccQ.SuperSupper
import java.math.*;
import java.util.*;

public class Main {

/**
 * @param args
 */
public static void main(String[] args) throws Exception{
  // TODO Auto-generated method stub

  BigInteger  num ,b;//= new BigInteger;
  num=BigInteger.valueOf(1);

  Scanner cin = new Scanner(System.in);

   int n,i,j,sum,t;
   int way[] = new int[100];
   int flag[][] = new int[100][100];

   while(cin.hasNext())
   {
    n = cin.nextInt();
    if(n==0) break;
    for(i=1,sum=0;i<=n;++i)
    {
        way[i]=cin.nextInt();
        sum+=way[i];
    }

    num = BigInteger.valueOf(1);

    for(i=2;i<=sum;++i)
    {
        b = BigInteger.valueOf(i);
        num = num.multiply(b);
    }

    //System.out.println(num);
    for(i=1;i<=n;++i) for(j=1;j<=way[i];++j)
    {
        sum=way[i]-j;
        for(t=i+1;t<=n;++t) if(way[t]>=j) sum++;

        sum++;
        b = BigInteger.valueOf(sum);
        //System.out.println(b);
        num = num.divide(b);
    }

    System.out.println(num);

    }
 }

}

