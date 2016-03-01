//* @author: 82638882@163.com
import java.io.*;
public class Main
{
 static int[] b,c;
 static long[] e,d,p;
 public static void main(String[] args)throws IOException
 {
	InputStreamReader is=new InputStreamReader(System.in);
	BufferedReader in=new BufferedReader(is);
	int a=Integer.parseInt(in.readLine());
	p=new long[a+2];
	b=new int[a+1];
	c=new int[a+1];
	d=new long[a+1];
	e=new long[a+1];
	String[] ss=in.readLine().split(" ");
	for(int i=1;i<=a;i++)
		e[i]=d[i]=p[i]=Long.parseLong(ss[i-1]);
	p[0]=p[a+1]=-1;
	long max=-1;
	for(int i=1;i<=a;i++)
	{
         b[i]=1;
	  int j=i;
	  while(p[j-b[j]]>=p[i])
	  {
		j-=b[j];
		b[i]+=b[j];
		d[i]+=d[j];
	   }
	}
	for(int i=a;i>0;i--)
	{
	  c[i]=1;
	  int j=i;
	  while(p[j+c[j]]>=p[i])
	  {
	    j+=c[j];
	    c[i]+=c[j];
	    e[i]+=e[j];
	   }
	}
	int st=-1,ed=-1;
	for(int i=1;i<=a;i++)
	{
	   long sum=d[i]+e[i]-p[i];
	   sum*=p[i];
	   if(sum>max)
	   {
		max=sum;
		st=i-b[i]+1;
		ed=i+c[i]-1;
	   }
	 }

	System.out.println(max);
	System.out.println(st+" "+ed);
   }
}


