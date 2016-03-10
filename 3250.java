import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

    int n,i;
       int p[]=new int[80010],q[]=new int[80010];
       n=sc.nextInt();
    for(i=0;i< n;i++)
         p[i]=sc.nextInt();
    for(i=0;i< n;i++) q[i]=1;
    p[n]=1000000010;
    for(i=n-1;i>=0;i--)
    {
     int u=p[i+1];
     while(p[i]>p[i+q[i]])
       q[i]+=q[i+q[i]];
    }
    long  total=0;
    for(i=0;i< n;i++)
        total+=q[i];
    total-=n;
    System.out.printf("%d\n",total);
  }
}

