//* @author: 82638882@163.com
import java.io.*;
public class Main
{
	static int[][] p;
	static int a,b,max=0,cnt;
	public static void main(String[] args) throws IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		String[] ss=in.readLine().split(" ");
		a=Integer.parseInt(ss[0]);
		b=Integer.parseInt(ss[1]);
		p=new int[b+2][a+2];
		for(int i=1;i<=b;i++)
		{
		  for(int j=1;j<=a;j++)
			p[i][j]=in.read();
		  in.readLine();
		}
		for(int i=1;i<=b;i++)
		{
		  for(int j=1;j<=a;j++)
		  {
			cnt=0;
			f(i,j);
			if(cnt>max) max=cnt;
		   }
		}
		System.out.println(max);
	}
	static void f(int x,int y)
	{
		if(p[x][y]!='*')return;
		p[x][y]=0;
		cnt++;
		f(x,y+1);
		f(x,y-1);
		f(x+1,y);
		f(x-1,y);
	}
}

