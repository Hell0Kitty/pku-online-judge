import java.io.*;
public class Main
{
 static int[] p,b,c;
 static int a;
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
   String[] ss=in.readLine().split(" ");
   a=Integer.parseInt(ss[0]);
   if(a==0) break;
   p=new int[a+2];
   b=new int[a+1];
   c=new int[a+1];
   for(int i=1;i<=a;i++)
	p[i]=Integer.parseInt(ss[i]);
   p[0]=p[a+1]=-1;
   long max=0;
   for(int i=1;i<=a;i++)
   {
	b[i]=1;
	int j=i;
	while(p[j-b[j]]>=p[i])
	{
          j-=b[j];
	  b[i]+=b[j];
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
	}
     }
    for(int i=1;i<=a;i++)
     {
	long h=(long)p[i]*(b[i]+c[i]-1);
	max=Math.max(h, max);
     }
    System.out.println(max);
  }
 }
}

