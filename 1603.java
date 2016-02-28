import java.util.Scanner;
public class Main
{
	static int[][] w=new int[21][21];
	static final int n=20;
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int cnt=0;
		while(in.hasNext())
		{
			cnt++;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					w[i][j]=9999999;
			for(int i=0;i<n-1;i++)
			{
				int u=in.nextInt();
				for(int j=0;j<u;j++)
				{
					int v=in.nextInt();
					w[i][v-1]=w[v-1][i]=1;
				}
			}
			for(int k=0;k<n;k++)
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						w[i][j]=Math.min(w[i][j], w[i][k]+w[k][j]);
			int c=in.nextInt();
			System.out.println("Test Set #"+cnt);
			while((c--)!=0)
			{
				int a1=in.nextInt();
				int a2=in.nextInt();
				System.out.println(a1+" to "+a2+": "+w[a1-1][a2-1]);
			}
			System.out.println();
		}
	}
}