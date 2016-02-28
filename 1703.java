import java.io.*;
public class Main
{
	static int[] p,q;
	static int u;
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int a=Integer.parseInt(in.readLine());
		while((a--)!=0)
		{
			String[] ss=in.readLine().split(" ");
			int n=Integer.parseInt(ss[0]);
			int m=Integer.parseInt(ss[1]);
			p=new int[n+1];
			q=new int[n+1];
			for(int i=0;i<=n;i++)
				p[i]=i;
			for(int i=0;i<m;i++)
			{
				ss=in.readLine().split(" ");
				int x=Integer.parseInt(ss[1]);
				int y=Integer.parseInt(ss[2]);
				if(ss[0].equals("D"))
					union(x,y);
				else{
					if(root(x)!=root(y))
						System.out.println("Not sure yet.");
					else
					{
						if(get(x)==get(y))
							System.out.println("In the same gang.");
						else
							System.out.println("In different gangs.");
					}
				}
			}
		}
	}
	static int root(int a)
	{
		while(p[a]!=a)
			a=p[a];
		return a;
	}
	static void union(int x,int y)
	{
		int s1=get(x);
		int x1=u;
		int s2=get(y);
		int y1=u;
		if(x1==y1)return;
		if(x1<y1)
		{
			p[y1]=x1;
			if(s1==s2)
				q[y1]=q[x1]+1;
		}
		else
		{
			p[x1]=y1;
			if(s1==s2)
				q[x1]=q[y1]+1;
		}
	}
	static int get(int a)
	{
		int t=0;
		while(p[a]!=a)
		{
			t+=q[a];
			a=p[a];
		}
		u=a;
		return t%2;
	}
}