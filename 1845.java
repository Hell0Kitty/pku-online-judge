import java.util.*; 
public class Main {
  
      static long modPow(long a,long n)
      {
          long MOD=9901;
          if (n==1) return a%MOD;
         long tmp=modPow(a,n>>1);
         tmp=tmp*tmp%MOD;
         if ((n&1)==1) tmp=tmp*a%MOD;
         return tmp;
     }

     static long myPow(long a,long n)
    {
        if (n==0) return 1;
        long ans=modPow(a,(n>>1)+1);
        ans=(ans+1)%9901;
        if ((n&1)==1)
            ans=ans*myPow(a,n>>1)%9901;
        else
        {
            ans=ans*myPow(a,(n-1)>>1)%9901;
            ans=ans+modPow(a,n>>1);
        }
        return ans%9901;
    }

    public static void main(String[] args) {
         Scanner cin=new Scanner(System.in);
        long a=cin.nextLong();
        long b=cin.nextLong();
        long ans=1;
        for (long i=2;i*i<=a;i++)
        if (a%i==0)
         {
            long pow=0;
            while (a%i==0)
            {
                a/=i;
                pow++;
            }
            pow*=b;
            ans=ans*myPow(i,pow)%9901;
        }
        if (a!=1)
            ans=ans*myPow(a,b)%9901;
        System.out.println((ans+9901)%9901);
   }
 }
  