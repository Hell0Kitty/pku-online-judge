import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(in.hasNext())
		{
			int a=in.nextInt();
			int b=in.nextInt();
			int c=in.nextInt();
			if(a==0&&b==0&&c==0)System.exit(0);
			String[] s=new String[a];
			char[][] d=new char[a][b];
			for(int i=0;i<a;i++)
				s[i]=in.next();
			int[][] e=new int[a][b];
			for(int i=0;i<a;i++)
				for(int j=0;j<b;j++)
					d[i][j]=s[i].charAt(j);
			int x=0;
			int y=c-1;
			int r=1;
			int u=0;
			while(x<a&&x>-1&&y>-1&&y<b)
			{
				if(e[x][y]==0)e[x][y]=r;
				else 
					{
						u=r-e[x][y];
						break;
					}
				if(d[x][y]=='N')x-=1;
				else if(d[x][y]=='S')x+=1;
				else if(d[x][y]=='W')y-=1;
				else if(d[x][y]=='E')y+=1;
				r++;
			}
			if(u==0)System.out.println(r-1+" step(s) to exit");
			else System.out.println((r-u-1)+" step(s) before a loop of "+u+" step(s)");
		}
	}
}