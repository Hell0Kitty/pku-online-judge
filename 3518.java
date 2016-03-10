//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{

    public static void main(String rgs[]) throws Exception
    {
        boolean[] prime=new boolean[1299710];
        Arrays.fill(prime,true);
        prime[1] = false;
        prime[0] = false;
        for(int i=2; i<=10000; ++i){
            if(prime[i])
                for (int j=i; i*j< 1299710; ++j)
                    prime[i*j] = false;
        }
        int n, left, right;
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        n = cin.nextInt();
        while(n!=0){
            if(prime[n])
                System.out.println(0);
            else{
                right = left = n;
                while(!prime[--left]);
                while(!prime[++right]);
                System.out.println(right - left);
            }
            n = cin.nextInt();
        }
    }
}

