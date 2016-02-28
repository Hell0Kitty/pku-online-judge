import java.io.*;
public class Main
{
  public static void main(String[] args) throws IOException
  {
   InputStreamReader is=new InputStreamReader(System.in);
   BufferedReader in=new BufferedReader(is);
   int a=Integer.parseInt(in.readLine());
   int n=0;
   my[] p=new my[a];
   String[] ss;
   while(a-n>10)
    {
	ss=in.readLine().split(" ");
	for(int i=0;i< 10;i++)
	{
		p[n+i]=new my();
		p[n+i].p=Integer.parseInt(ss[i]);
	}
	n+=10;
    }
   ss=in.readLine().split(" ");
   for(int i=0;i< ss.length;i++)
   {
	p[n+i]=new my();
	p[n+i].p=Integer.parseInt(ss[i]);
   }
   for(int i=0;i< a;i++)
   {
	p[i].q=1;
	for(int j=i-1;j>=0;j--)
	{
		if(p[j].p>p[i].p&&p[j].q>=p[i].q)
			p[i].q=p[j].q+1;
	}
   }

  int max=p[a-1].q;
  for(int i=0;i< a;i++)
	if(p[i].q>max) max=p[i].q;
  System.out.print(max);
  int cnt=0;
  for(int i=0;i< a;i++)
	if(p[i].q==1)p[i].n=1;
  for(int i=0;i< a;i++)
  {
	for(int j=0;j< i;j++)
	{
		if(p[i].q==p[j].q+1&&p[i].p< p[j].p)
			 p[i].n+=p[j].n;
		else if(p[i].p==p[j].p&&p[i].q==p[j].q)
		{
			p[i].n-=p[j].n;
		}
	}
   }
   for(int i=0;i< a;i++)
	if(p[i].q==max) cnt+=p[i].n;
   System.out.println(" "+cnt);
 }
}

  class my implements Comparable< my>
  {
	int p;
	int q;
	int n=0;
	@Override
	public int compareTo(my arg0) {
		if(q==arg0.q)
			return p-arg0.p;
		else return q-arg0.q;
	}
}

