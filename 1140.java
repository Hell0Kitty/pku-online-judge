 
import java.io.*;
import java.math.*;
import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int a,b,i,j,c[],f,d;
        c=new int[2000];
        for(;;)
        {
         a=cin.nextInt();
         b=cin.nextInt();
         if(a==0&b==0)break;
         c[0]=a;i=0;f=0;j=0;d=1;
         System.out.print(".");
         for(;;)
         {
          a=(a*10)%b;
          if(a!=0)
          {
           for(j=0;j<i;j++)
           {
            if(c[j]==c[i])break;
           }
           if(c[j]==c[i]&j!=i)break;
           System.out.printf("%d",c[i]*10/b);
           c[++i]=a;
           d++;
           if(d%50==0)System.out.println();
          }
          else
          {
           f=1;
           break;
          }
         }
         if(f==1)System.out.printf("%d\nThis expansion terminates.\n",c[i]*10/b);
         else
         {
          if(d%50!=0)System.out.printf("\n");
          System.out.printf("The last %d digits repeat forever.\n",i-j);
         }
        }
    }
}
