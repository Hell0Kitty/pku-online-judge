//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(in.hasNext())
  {
   int a=in.nextInt();
   int x=1,y=1,z=a,m=1,n=1,q=a;
   for(int i=(int)Math.pow(a,1.0/3)+1;i>0;i--)
   {
    if(a%i==0)
    {
         x=i;
      for(int j=(int)Math.sqrt(a/x)+1;j>0;j--)
      {
       if((a/x)%j==0)
       {
        y=j;
        z=a/x/j;
        if(x*y+y*z+z*x< m*n+n*q+q*m)
        {
        m=x;
        n=y;
        q=z;
        }
        break;
       }
      }
     }
     }
     System.out.println(m+" "+n+" "+q);
   }
 }
}

