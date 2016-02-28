import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(in.hasNext())
		{
		String s=in.next();
		boolean bb=true;
		for(int i=0;i<s.length()-1;i++)
		{
			if(s.charAt(i)-s.charAt(i+1)>=0)
			{
				System.out.println(0);
				bb=false;
				break;
			}
		}
		if(!bb)continue;
		int l=s.length();
		long ans=0;
		for(int i=1;i<l;i++)
			ans+=find(26,i);
		int k=0;
		for(int i=0;i<l;i++)
		{
			k=0;
			if(i!=0)k=s.charAt(i-1)-'a'+1;
			int y=s.charAt(i)-'a'+1;
			for(int j=y-1;j>k;j--)
			{
				ans+=find(26-j,l-i-1);
			}
		}
		System.out.println(ans+1);
		}
	}
	public static long find(int u,long a)
	{
		if(u<a)return 0;
		if(a==0)return 1;
		long l=1;
		for(int i=u;i>u-a;i--)
			l*=i;
		for(int i=1;i<=a;i++)
			l/=i;
		return l;
	}
}