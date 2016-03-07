import java.io.*;
public class Main
{
	static int[] arr=new int[26];
	static int[] cin=new int[26];
	static int[] cout=new int[26];
	static boolean[] used=new boolean[26];
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int y=Integer.parseInt(in.readLine());
		while((y--)!=0)
		{
			int n=Integer.parseInt(in.readLine());
			for(int i=0;i<26;i++){
				arr[i]=i;
				cin[i]=0;
				cout[i]=0;
				used[i]=false;
			}
			for(int i=0;i<n;i++)
			{
				String s=in.readLine();
				int u=s.charAt(0)-'a';
				int v=s.charAt(s.length()-1)-'a';
				cin[u]++;
				cout[v]++;
				used[u]=true;
				used[v]=true;
				union(u,v);
			}
			boolean euler=true;
			int one=0,none=0;
			for(int i=0;i<26;i++)
			{
				if(!used[i])continue;
				if(Math.abs(cin[i]-cout[i])>1){
					euler=false;
					break;
				}
				if(cin[i]-cout[i]==1)
				{
					one++;
					if(one>1)
					{
						euler=false;
						break;
					}
				}
				if(cout[i]-cin[i]==1)
				{
					none++;
					if(none>1)
					{
						euler=false;
						break;
					}
				}
			}
			if(one!=none)euler=false;
			int yy=-1;
			for(int i=0;i<26;i++)
			{
				if(!used[i])continue;
				if(yy==-1)yy=root(i);
				else if(yy!=root(i))
				{
					euler=false;
					break;
				}
			}
			if(!euler)System.out.println("The door cannot be opened.");
			else System.out.println("Ordering is possible.");
		}
	}
	static int root(int a)
	{
		int b=a;
		while(arr[b]!=b)
			b=arr[b];
		return arr[a]=b;
	}
	static void union(int a,int b)
	{
		int x=root(a);
		int y=root(b);
		if(x==y)return;
		if(x>y)arr[x]=y;
		else arr[y]=x;
	}
}
