import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Hashtable;
import java.util.Scanner;
public class Main
{
	static int[]k=new int[6];
	static int[]p=new int[6];
	static int n,m,mark;
	static int total;
	static Hashtable<Long,Integer>hash=new Hashtable<Long,Integer>();
	public static void main(String[] args)
	{
		int i,j;
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext())
		{
			hash.clear();
			total=0;
			n=cin.nextInt();
			m=cin.nextInt();
			for(i=0;i<n;i++)
			{
				k[i]=cin.nextInt();
				p[i]=cin.nextInt();
			}
			mark=n/2;
			dfs(0,0);
			dfs2(mark,0);
			System.out.println(total);
		}		
	}
	static void dfs(int pos,long sum)
	{
		if(pos==mark)
		{
			sum*=-1;
			if(hash.containsKey(sum))
			{
				hash.put(sum,hash.get(sum)+1);
			}
			else
				hash.put(sum,1);
			return;
		}
		int i,j;
		long tmp;
		for(i=1;i<=m;i++)
		{
			tmp=(long)k[pos];
			for(j=0;j<p[pos];j++)
			{
				tmp*=i;
			}
			dfs(pos+1,sum+tmp);
		}
	}
	static void dfs2(int pos,long sum)
	{
		if(pos>=n)
		{
			if(hash.containsKey(sum))
			{
				total+=hash.get(sum);
			}
			return;
		}
		int i,j;
		long tmp;
		for(i=1;i<=m;i++)
		{
			tmp=(long)k[pos];
			for(j=0;j<p[pos];j++)
			{
				tmp*=i;
			}
			dfs2(pos+1,sum+tmp);
		}
		
	}
}