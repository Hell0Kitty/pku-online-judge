import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int a=Integer.parseInt(in.readLine());
		int ans=2,i;
		my[] arr=new my[a];
		String[] ss;
		for(i=0;i<a;i++)
		{
			ss=in.readLine().split(" ");
			int x=Integer.parseInt(ss[0]);
			int y=Integer.parseInt(ss[1]);
			arr[i]=new my(x,y);
		}
		Arrays.sort(arr);
		int x=arr[0].b,y=x-1;
		for(i=1;i<a;i++)
		{
			if(y>=arr[i].a){}
			else if(x>=arr[i].a)
			{
				y=x;
				x=arr[i].b;
				ans++;
			}
			else
			{
				x=arr[i].b;
				y=x-1;
				ans+=2;
			}
		}
		System.out.printf("%d\n",ans);
	}
}
class my implements Comparable<my>
{
	public int a,b;
	public my(int x,int y)
	{
		a=x;
		b=y;
	}
	public int compareTo(my o) {
		return b-o.b;
	}
}