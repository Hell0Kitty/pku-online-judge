//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
  {
    long p=in.nextLong();
    long a=in.nextLong();
    if(a==0&&p==0) break;
    if(isPrime(p)){
        System.out.println("no");
        continue;
    }
    System.out.println(sum(a,p,p)==a?"yes":"no");
   }
  }

 public static boolean isPrime(long a)
 {
    if(a==2) return true;
    for(int i=3;i<=Math.sqrt(a);i+=2)
        if(a%i==0) return false;
    return true;
  }

 public static long sum(long a,long n,long p)
 {
    if(n==0) return 1;
    long w=sum(a*a%p,n/2,p);
    if(n%2==1) w=(w*a)%p;
    return w;
 }
}

