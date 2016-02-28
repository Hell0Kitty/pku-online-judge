import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		String[] ss;
		int a=Integer.parseInt(in.readLine());
		HashSet<Integer> hs=new HashSet<Integer>();
		while((a--)!=0)
		{
			int b=Integer.parseInt(in.readLine());
			ss=in.readLine().split(" ");
			int[] arr=new int[b+1];
			for(int i=0;i<b;i++)
				arr[i+1]=Integer.parseInt(ss[i]);
			int c=0;
			for(int i=1;i<=b;i++)
			{
				int u=arr[i];
				if(!hs.contains(u))
				{
					while(!hs.contains(u))
					{
						hs.add(u);
						u=arr[u];
					}
					c++;
				}
			}
			System.out.println(b-c);
			hs.clear();
		}
	}		
}