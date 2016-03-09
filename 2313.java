
import java.util.*;
public class Main {

static long abs(long a)
{
    if(a< 0)
        return -a;
    else
        return a;
}

static  boolean in(long a,long b,long c)
{
    if(abs(a-c)+abs(b-c)==abs(a-b))
        return true;
    else return false;
}

static public void main( String [] str ) throws Exception{
   Scanner sc = new Scanner(System.in);
   long sum=0;
   int n;
   n=sc.nextInt();
   long a[]=new long[n+1];
   long b[]=new long[n+1];

    for(int i=1;i<=n;i++)
    {
       a[i]=sc.nextLong();;
    }
    b[0]=a[0]=0;
    b[0]=a[1];
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(in(a[i-1],b[i-2],a[i]))
     {
        b[i-1]=a[i];
      }
     else
     {
       if(abs(a[i]-a[i-1])< abs(a[i]-b[i-2]))
        b[i-1]=a[i-1];
       else
        b[i-1]=b[i-2];

      }
    sum+=abs(a[i]-b[i-1]);
      }

   System.out.printf("%d",sum);

   }
}

