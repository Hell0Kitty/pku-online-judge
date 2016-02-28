import java.io.*;
import java.util.*;
public class Main{
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int a=Integer.parseInt(in.readLine());
		while((a--)!=0)
		{
			String[] ss=in.readLine().split(" ");
			int l=Integer.parseInt(ss[0]);
			int cnt=Integer.parseInt(ss[1]);
			int[] arr=new int[l];
			ss=in.readLine().split(" ");
			for(int i=0;i<l;i++)
				arr[i]=Integer.parseInt(ss[i]);
			while((cnt--)!=0)
			{
				boolean bb=false;
				for(int y=l-1;y>=0;y--)
				{
					for(int i=l-1;i>y;i--)
					{
						if(arr[i]>arr[y])
						{
							int u=arr[i];
							arr[i]=arr[y];
							arr[y]=u;
							Arrays.sort(arr,y+1,l);
							bb=true;
							break;
						}
					}
					if(bb)break;
				}
				if(!bb)
					for(int i=0;i<l;i++)arr[i]=i+1;
			}
			for(int i=0;i<l-1;i++)
				System.out.print(arr[i]+" ");
			System.out.println(arr[l-1]);
		}
	}
}