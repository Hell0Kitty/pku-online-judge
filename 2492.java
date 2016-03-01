import java.io.*;
public class Main
{
 static my[] p;
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  int cnt=0;
  while((a--)!=0)
  {
   cnt++;
   String[] ss=in.readLine().split(" ");
   int n=Integer.parseInt(ss[0]);
   p=new my[n+1];
   for(int i=0;i<=n;i++)
     p[i]=new my(i);
   int t=Integer.parseInt(ss[1]);
   boolean bb=true;
   while((t--)!=0)
   {
	ss=in.readLine().split(" ");
	if(bb)
	{
          int x1=Integer.parseInt(ss[0]);
	  int x2=Integer.parseInt(ss[1]);
	  int r1=root(x1),r2=root(x2);
	  if(r1< r2){
	    p[r2].root=r1;
	    p[x2].d=(p[x1].d+1)%2;
	  }
	  else if(r1>r2){
	    p[r1].root=r2;
	    p[x1].d=(p[x2].d+1)%2;
	  }
	  else if(p[x2].d==p[x1].d)bb=false;
	}
     }
     System.out.println("Scenario #"+cnt+":");
     if(bb)System.out.println("No suspicious bugs found!");
     else System.out.println("Suspicious bugs found!");
     System.out.println();
  }
 }

 static int root(int a)
  {
	int u=a;
	while(p[a].root!=a)a=p[a].root;
	p[u].root=a;
	return a;
  }

}

 class my
 {
	int root;
	int d=0;
	public my(int r)
	{
		root=r;
	}
 }

