import java.io.*;
public class Main
{
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
			String[] ss;
			int b=Integer.parseInt(in.readLine());
			int[] ax=new int[b];
			int[] ay=new int[b];
			int[][] p=new int[b][b];
			for(int i=0;i<b;i++)
			{
				ss=in.readLine().split(" ");
				ax[i]=Integer.parseInt(ss[0]);
				ay[i]=Integer.parseInt(ss[1]);
			}
			for(int i=0;i<b;i++)
			{
				for(int j=i+1;j<b;j++)
				{
					int juli=(ax[i]-ax[j])*(ax[i]-ax[j])+(ay[i]-ay[j])*(ay[i]-ay[j]);
					p[i][j]=p[j][i]=juli;
				}
			}
			int a=Integer.parseInt(in.readLine());
			for(int i=0;i<a;i++)
			{
				ss=in.readLine().split(" ");
				int u1=Integer.parseInt(ss[0])-1;
				int u2=Integer.parseInt(ss[1])-1;
				p[u1][u2]=p[u2][u1]=0;
			}
			int[] low=new int[b];
			low[0]=-1;
			int[] near=new int[b];
			for(int i=1;i<b;i++)
				low[i]=p[0][i];
			for(int i=1;i<b;i++)
			{
				int min=9999999,tag=0;
				for(int j=0;j<b;j++)
				{
					if(low[j]!=-1&&low[j]<min)
					{
						min=low[j];
						tag=j;
					}
				}
					if(min!=0)System.out.println((near[tag]+1)+" "+(tag+1));
					low[tag]=-1;
				for(int j=0;j<b;j++)
				{
					if(p[tag][j]<low[j])
					{
						low[j]=p[tag][j];
						near[j]=tag;
					}
				}
			}
	}
}
	
