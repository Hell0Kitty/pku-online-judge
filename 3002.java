/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 static long gcd(long a,long b)
{
  if(b==0) return a;
  return gcd(b,a%b);
}


 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
 int t,n,i;
 long p[]=new long[6];
 t=sc.nextInt();
 while((t--)!=0)
 {
    n=sc.nextInt();
    for(i=0;i< n;i++)
      p[i]=sc.nextLong();
    long u=p[0];
    boolean bb=false;
    for(i=1;i< n;i++)
    {
	u=u*p[i]/gcd(p[i],u);
	if(u>1000000000){
         bb=true;
	  break;
	}
    }
    if(!bb) System.out.printf("%d\n",u);
    else System.out.println("More than a billion.");
   }
  }
}

