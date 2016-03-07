import java.io.*;
public class Main
{
	static boolean[][] p;
	static int sz;
	static String[] ss;
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		String[] ss=in.readLine().split(" ");
		int a=Integer.parseInt(ss[0]);
		int b=Integer.parseInt(ss[1]);
		int[][] p=new int[a][b];
		int[][] c=new int[a][b];
		for(int i=0;i<a;i++)
		{
			ss=in.readLine().split(" ");
			for(int j=0;j<b;j++)
				p[i][j]=Integer.parseInt(ss[j]);
		}
		for(int j=0;j<b;j++)
			c[0][j]=p[0][j];
		for(int i=1;i<a;i++)
		{
			for(int j=i;j<b;j++)
			{
				int max=-9999999;
				for(int k=0;k<j;k++)
					if(max<c[i-1][k])max=c[i-1][k];
				c[i][j]=p[i][j]+max;
			}
		}
		int max=-99999;
		for(int i=a;i<b;i++)
			if(c[a-1][i]>max)max=c[a-1][i];
		System.out.println(max);
	}
}