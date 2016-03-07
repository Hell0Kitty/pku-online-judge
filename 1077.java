import java.util.*;
public class Main
{
	static int[][] arr;
	static boolean[] bb=new boolean[10000000];
	static Queue< my> qu=new LinkedList< my>();
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		arr=new int[5][5];
		String s;
		for(int i=1;i< 4;i++)
		{
			for(int j=1;j< 4;j++)
			{
				s=in.next();
				if(s.equals("x"))arr[i][j]=0;
				else arr[i][j]=Integer.parseInt(s);
			}
		}
		int u=getNum();
		bfs(u);
		
	}
	static void bfs(int t)
	{
			qu.add(new my("",t));
		while(!qu.isEmpty())
		{
			my h=qu.poll();
			int u=h.u;
			String s=h.s;
			if(u==123456780)
			{
				System.out.println(s);
				return;
			}
			if(bb[u%9999991])continue;
			bb[u%9999991]=true;
			int i=-1,j=-1,p=u;
			for(int u1=3;u1>0;u1--)
			{
				for(int u2=3;u2>0;u2--)
				{
					arr[u1][u2]=p%10;
					if(arr[u1][u2]==0)
					{
						i=u1;
						j=u2;
					}
					p/=10;
				}
			}
			change(i,j,i-1,j);
			int y=getNum();
			qu.add(new my(s+"u",y));
			change(i-1,j,i,j);
			
			change(i,j,i+1,j);
			y=getNum();
			qu.add(new my(s+"d",y));
			change(i+1,j,i,j);
			
			change(i,j,i,j+1);
			y=getNum();
			qu.add(new my(s+"r",y));
			change(i,j+1,i,j);
			
			change(i,j,i,j-1);
			y=getNum();
			qu.add(new my(s+"l",y));
			change(i,j-1,i,j);
		}
		System.out.println("unsolvable");
	}
	static int getNum()
	{
		int t=0;
		for(int i=1;i< 4;i++)
			for(int j=1;j< 4;j++)
			{
				t*=10;
				t+=arr[i][j];
			}
		return t;
	}
	static void change(int x1,int y1,int x2,int y2)
	{
		arr[x1][y1]=arr[x2][y2];
		arr[x2][y2]=0;
	}
}
class my
{
	String s="";
	int u;
	public my(String t,int a)
	{
		u=a;
		s=t;
	}
}

