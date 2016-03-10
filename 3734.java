import java.io.*;
import java.util.*;

public class Main {

/**
 * @param args
 * @return
 */
 static int pow_mod(int a,int b,int c)
 {
    int r=1,d=a;
    while(b>0){
        if((b&1)==1) r = r*d%c;
        d = d*d%c;
        b>>=1;
    }
    return r;
  }

public static void main(String[] args)throws Exception {
    // TODO Auto-generated method stub
    int ans,t,n;
    Scanner cin = new Scanner(System.in);

    t = cin.nextInt();
    for(int i=0;i< t;i++)
    {
        n = cin.nextInt();
        ans = pow_mod(2,n-1,10007);
        ans = (ans+1) *ans %10007;
        System.out.println(ans);
    }
  }

}

