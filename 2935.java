import java.io.*;
import java.util.*;
public class Main
{
 static int x1,y1,x2,y2,l;
 static boolean[][] p=new boolean[8][8];
 static int[] ax1,ay1,ax2,ay2;
 public static void main(String[] args) throws IOException
 {
   InputStreamReader is=new InputStreamReader(System.in);
   BufferedReader in=new BufferedReader(is);
   String[] ss;
   while(true)
   {
	for(int i=0;i< 8;i++)
		for(int j=0;j< 8;j++)
			p[i][j]=false;
	for(int i=0;i< 8;i++)
	{
		p[0][i]=true;
		p[7][i]=true;
		p[i][0]=true;
		p[i][7]=true;
	}
	ax1=new int[50];
	ay1=new int[50];
	ax2=new int[50];
	ay2=new int[50];
	l=0;
	ss=in.readLine().split(" ");
	y1=Integer.parseInt(ss[0]);
	x1=Integer.parseInt(ss[1]);
	if(x1==0&&y1==0)break;
	ss=in.readLine().split(" ");
	y2=Integer.parseInt(ss[0]);
	x2=Integer.parseInt(ss[1]);
	int a1,a2,b1,b2;
	for(int i=0;i< 3;i++)
	{
		ss=in.readLine().split(" ");
		a1=Integer.parseInt(ss[0]);
		b1=Integer.parseInt(ss[1]);
		a2=Integer.parseInt(ss[2]);
		b2=Integer.parseInt(ss[3]);
		if(a1==a2)
		{
		  if(b1>b2)
		  {
			int temp=b1;
			b1=b2;
			b2=temp;
		   }
		   for(int j=b1+1;j<=b2;j++)
		   {
			ay1[l]=a1;
			ay2[l]=a1+1;
			ax1[l]=ax2[l]=j;
			l++;
		    }
		}
		if(b1==b2)
		{
		  if(a1>a2)
		  {
			int temp=a1;
			a1=a2;
			a2=temp;
		   }
		  for(int j=a1+1;j<=a2;j++)
		  {
			ax1[l]=b1;
			ax2[l]=b1+1;
			ay1[l]=ay2[l]=j;
			l++;
		   }
		}
	}
	bfs();
	System.out.println();
   }

 }

static boolean f(int x,int y,int x1,int y1)
{
  for(int i=0;i< l;i++)
  {
	if(x==ax1[i]&&y==ay1[i]&&x1==ax2[i]&&y1==ay2[i])
		return false;
	if(x1==ax1[i]&&y1==ay1[i]&&x==ax2[i]&&y==ay2[i])
		return false;
   }
  return true;
 }

static void ff(ri tt)
{
	if(tt.root!=null)ff(tt.root);
	if(tt.root==null)return;
	if(tt.x==tt.root.x&&tt.y==tt.root.y+1)
		System.out.print("E");
	else if(tt.x==tt.root.x&&tt.y==tt.root.y-1)
		System.out.print("W");
	else if(tt.x==tt.root.x+1&&tt.y==tt.root.y)
		System.out.print("S");
	else if(tt.x==tt.root.x-1&&tt.y==tt.root.y)
		System.out.print("N");
  }

 static void bfs()
 {
	Queue< ri> qu=new LinkedList< ri>();
	ri orz=new ri(x1,y1,null);
	qu.add(orz);
	p[x1][y1]=true;
	while(!qu.isEmpty())
	{
	  ri temp=qu.poll();
	  if(temp.x==x2&&temp.y==y2)
	  {
		ff(temp);
		return;
	  }
	  int x=temp.x;
	  int y=temp.y;
	  if(!p[x+1][y])
	  {
		if(f(x,y,x+1,y))
		{
	         ri uu=new ri(x+1,y,temp);
		  qu.add(uu);
		  p[x+1][y]=true;
		}
	    }
	   if(!p[temp.x-1][temp.y])
	   {
		if(f(x,y,x-1,y))
		{
	         ri uu=new ri(x-1,y,temp);
		  qu.add(uu);
		  p[x-1][y]=true;
		}
	     }
	   if(!p[temp.x][temp.y+1])
	   {
		if(f(x,y,x,y+1))
		{
	         ri uu=new ri(x,y+1,temp);
		  qu.add(uu);
		  p[x][y+1]=true;
		}
	    }
	   if(!p[temp.x][temp.y-1])
	   {
		if(f(x,y,x,y-1))
		{
	         ri uu=new ri(x,y-1,temp);
		  qu.add(uu);
		  p[x][y-1]=true;
		 }
	    }
	}
  }
}
class ri
{
	int x,y;
	ri root;
	public ri(int xx,int yy,ri t)
	{
		x=xx;
		y=yy;
		root =t;
	}
}

