import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
       BigInteger sum,m,D[] = new BigInteger[2];
       int i,b[] = new int[340];
       Scanner cin = new Scanner(System.in);
       m = cin.nextBigInteger();
       sum = cin.nextBigInteger();
       int k = 0;
       while(sum.compareTo(BigInteger.ZERO) != 0)
       {
           D = sum.divideAndRemainder(m);
           sum = D[0];
           if(D[1].compareTo(BigInteger.ZERO) == 0)
           {
               sum = sum.subtract(BigInteger.ONE);
               b[++k] = m.intValue();
           }
           else
               b[++k] = D[1].intValue();
       }
       for(i = k;i >= 1;i --)
          System.out.print(b[i]);
       System.out.println();
    }
}

