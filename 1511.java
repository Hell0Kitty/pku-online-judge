import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main
{
	static int[] cost;
	static node[] edge,redge;
	static int n;
	static boolean[] used;
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		InputStreamReader is=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(is);
		int h=Integer.parseInt(in.readLine());
		while((h--)!=0)
		{
			String[] ss=in.readLine().split(" ");
			n=Integer.parseInt(ss[0]);
			edge=new node[n];
			redge=new node[n];
			cost=new int[n];
			used=new boolean[n];
			for(int i=0;i<n;i++)
			{
				edge[i]=new node(-1,-1);
				redge[i]=new node(-1,-1);
			}
			int m=Integer.parseInt(ss[1]);
			for(int i=0;i<m;i++)
			{
				ss=in.readLine().split(" ");
				int x=Integer.parseInt(ss[0]);
				int y=Integer.parseInt(ss[1]);
				int w=Integer.parseInt(ss[2]);
				insert(x,y,w);
			}
			long w=0;
			w+=spfa(0);
			w+=spfa(1);
			System.out.println(w);
		}
	}
	static void insert(int x,int y,int w)
	{
		x--;y--;
		node temp=new node(y,w);
		temp.next=edge[x].next;
		edge[x].next=temp;
		temp=new node(x,w);
		temp.next=redge[y].next;
		redge[y].next=temp;	
	}
	static long spfa(int d)
	{
		node temp;
		for(int i=0;i<n;i++)
			cost[i]=2000000000;
		Queue<Integer> qu=new LinkedList<Integer>();
		qu.add(0);
		cost[0]=0;
		while(!qu.isEmpty())
		{
			int u=qu.poll();
			used[u]=false;
			if(d==0)temp=edge[u].next;
			else temp=redge[u].next;
			while(temp!=null)
			{
				if(cost[temp.v]>cost[u]+temp.w)
				{
					cost[temp.v]=cost[u]+temp.w;
					if(!used[temp.v])
					{
						qu.add(temp.v);
						used[temp.v]=true;
					}
				}
				
				temp=temp.next;
			}
		}
		long ans=0;
		for(int i=0;i<n;i++)
			ans+=cost[i];
		return ans;
	}
	
}
class node
{
	int v,w;
	node next=null;
	public node(int vv,int ww)
	{
		v=vv;w=ww;
	}
}