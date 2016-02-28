import java.io.*;
public class Main
{
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int a=Integer.parseInt(in.readLine());
		int[] arr=new int[a];
		String[] ss=in.readLine().split(" ");
		for(int i=0;i<a;i++)
			arr[i]=Integer.parseInt(ss[i]);
		int[][] gra=new int[a][a];
		for(int i=2;i<a;i++)
		{
			for(int j=0;j+i<a;j++)
			{
				int min=999999999,u=-1;
				for(int k=j+1;k<j+i;k++)
				{
					u=gra[j][k]+gra[k][j+i]+arr[j]*arr[k]*arr[j+i];
					if(min>u)min=u;
				}
				gra[j][j+i]=min;
			}
		}
		System.out.println(gra[0][a-1]);
	}
}