/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

 int n,mx=-1,tag=-1,i,v;
 n=sc.nextInt();
 while((n--)!=0)
 {
   v=sc.nextInt();
   int u=v;
   int maxx=1;
   if(v%2==0)
   {
	maxx=2;
	while(v%2==0)v/=2;
   }
   for(i=3;i*i<=v;i+=2)
   {
	if(v%i==0)
	{
          maxx=i;
	   while(v%i==0)v/=i;
	 }
    }
    if(v>maxx)maxx=v;
    if(maxx>mx)
    {
	mx=maxx;
	tag=u;
     }
   }
   System.out.printf("%d\n",tag);
  }
}

