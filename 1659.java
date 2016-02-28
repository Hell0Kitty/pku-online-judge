import java.io.*;
import java.util.*;
public class Main
{
	static int[][] p;
	static ri[] arr;
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int n=Integer.parseInt(in.readLine());
		while((n--)!=0)
		{
			int m=Integer.parseInt(in.readLine());
			p=new int[m][m];
			arr=new ri[m];
			String[] ss=in.readLine().split(" ");
			for(int i=0;i<m;i++)
				arr[i]=new ri(Integer.parseInt(ss[i]),i);
			
			int cnt=0;
			boolean bb=true;
			while(bb)
			{
				Arrays.sort(arr,cnt,m);
				int uu=arr[cnt].num;
				for(int i=0;i<arr[cnt].num;i++)
				{
					arr[cnt+1+i].num--;
					p[arr[cnt].n][arr[cnt+1+i].n]=1;
					p[arr[cnt+1+i].n][arr[cnt].n]=1;
					if(arr[cnt+1+i].num<0)
					{
						bb=false;
						break;
					}
				}
				cnt++;
				if(cnt==m)break;
			}
			if(!bb)System.out.println("NO");
			else{
				System.out.println("YES");
				for(int i=0;i<m;i++)
				{
					for(int j=0;j<m;j++)
						System.out.print(p[i][j]+" ");
					System.out.println();
				}
			}
			System.out.println();
		}
	}
}
class ri implements Comparable<ri>
{
	int num;
	int n;
	public ri(int a,int b)
	{
		num=a;
		n=b;
	}
	@Override
	public int compareTo(ri arg0) {
		
		return arg0.num-num;
	}
}
