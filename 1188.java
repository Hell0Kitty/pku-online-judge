import java.util.Scanner;
import java.util.Arrays;
public class Main{
 static int mins=Integer.MIN_VALUE;
 static int maxs=Integer.MAX_VALUE;

static int min(int a,int b)
{
    return a<=b?a:b;   
}

static int max(int a,int b)
{
    return a>=b?a:b;   
}

 
 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
    int n,i; 
    while(sc.hasNext())
    {
       n=sc.nextInt();
       if(n==0)
         break;
       int startx=mins;
       int starty=mins;
       int startz=mins;
       int stopx=maxs;
       int stopy=maxs;
       int stopz=maxs;
       int x,y,z,len,h=0; 
       for(i=0;i<n;i++)
       {
          x=sc.nextInt();
          y=sc.nextInt();
          z=sc.nextInt();
          len=sc.nextInt();
           if(h==1)
             continue;   
           startx=max(startx,x);
           starty=max(starty,y);
           startz=max(startz,z);
           x=x+len;
           y=y+len;
           z=z+len;
           stopx=min(stopx,x);
           stopy=min(stopy,y);
           stopz=min(stopz,z);
           if(startx>=stopx || starty>=stopy || startz>=stopz)
              h=1;               
       }
       if(h==0)
       {
           System.out.println((stopx-startx)*(stopy-starty)*(stopz-startz));        
       }   
       else
         System.out.println("0");  
    }
   }
}

