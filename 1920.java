import java.io.*;
import java.util.Arrays;
public class Main
{
 public static void main(String[] args) throws IOException
 {
	InputStreamReader is=new InputStreamReader(System.in);
	BufferedReader in=new BufferedReader(is);
	int a=Integer.parseInt(in.readLine());
	while((a--)!=0)
	{
         String[] ss=in.readLine().split(" ");
	  int cow=Integer.parseInt(ss[0]);
	  int cul=Integer.parseInt(ss[1]);
	  int sum=Integer.parseInt(ss[2])-2;
	  my[] p=new my[cow*cul+3];
	  int l=1;
	  for(int i=0;i< cow;i++)
	  {
		ss=in.readLine().split(" ");
		for(int j=0;j< cul;j++)
		{
			int y=Integer.parseInt(ss[j]);
			if(y!=0)
			{
			  p[l]=new my();
			  p[l].x=i;
			  p[l].y=j;
			  p[l].n=y;
			  l++;
			}
		}
	    }
	   Arrays.sort(p,1,l);
	   p[0]=new my();
	   p[0].x=0;
	   p[0].y=p[1].y;
	   p[0].n=0;
	   int total=0;
	   for(int i=1;i< l;i++)
	   {
		int dis=Math.abs(p[i].x-p[i-1].x)+Math.abs(p[i].y-p[i-1].y);
		if(sum>=dis+1+p[i].x)
		{
			sum=sum-dis-1;
			total+=p[i].n;
		}
		else break;
	    }
	   System.out.println(total);
	}
   }
}

class my implements Comparable< my>
{
	int x;
	int y;
	int n;
	@Override
	public int compareTo(my arg0) {
		return arg0.n-n;
	}
}

