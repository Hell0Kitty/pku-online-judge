import java.io.*;
import java.util.*;
public class Main
{
	static int[] p,q;
	static int m,n;
	static Queue<mye> qu;
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		qu=new LinkedList<mye>();
		while(in.hasNext())
		{
			qu.clear();
			n=in.nextInt();
			m=in.nextInt();
			p=new int[m];
			for(int i=0;i<m;i++)
				p[i]=in.nextInt();
			Arrays.sort(p);
			if(n==0)
				System.out.println(0);
			else {
				q=new int[n];
			bsf(q,p);
			if(q[0]==0)System.out.print(0);
			System.out.println();
			}		
		}
	}
	static void f(mye e)
	{
		if(e.pre!=null)
		{
			f(e.pre);
		}
		if(e.pre!=null)System.out.print(e.curN);
	}
	static void bsf(int[] q,int[] p)
	{
		qu.add(new mye(0,0,null));
		while(!qu.isEmpty())
		{
			mye uu=qu.poll();
			int num=uu.dig*10;
			for(int i=0;i<m;i++)
			{
				int k=num+p[i];
				if(k==0)continue;
				k%=n;
				if(q[k]==0)
				{
					q[k]++;
					if(k==0)
					{
						mye tt=new mye(k,p[i],uu);
						f(tt);
						return;
					}
					qu.add(new mye(k,p[i],uu));
				}
			}
		}		
	}
}
class mye
{
	int dig=0;
	int curN;
	mye pre;
	public mye(int d,int c,mye e)
	{
		dig=d;
		curN=c;
		pre=e;
	}
}