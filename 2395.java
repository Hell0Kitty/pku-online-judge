import java.util.Scanner;
public class Main{
 public static void main(String args[])
{
 int p[][]=new int[2001][2001];
 int n,m,i,j,k;
 int dis[]=new int[2001];
 int u,v,l;
 int ne[]=new int[2001];
  Scanner sc=new Scanner(System.in);
  n=sc.nextInt();
  m=sc.nextInt();
  int max=0;
  for(i=0;i< n;i++)
   for(j=0;j< n;j++)
	p[i][j]=1000000001;
  for(i=0;i< m;i++)
  {
     u=sc.nextInt();
     v=sc.nextInt();
     l=sc.nextInt();
     u--;
     v--;
     if(p[u][v]>l)p[u][v]=p[v][u]=l;
  }
  for(i=0;i< n;i++)
    {
	dis[i]=p[0][i];
	ne[i]=0;
     }
  ne[0]=-1;
  for(i=0;i< n-1;i++)
  {
    int min=1000000001,tag=-1;
    for(j=0;j< n;j++)
	if(ne[j]!=-1&&dis[j]< min)
	{
	   min=dis[j];
	   tag=j;
	 }
	 ne[tag]=-1;
	 if(dis[tag]>max)max=dis[tag];
	 for(j=0;j< n;j++)
	   if(ne[j]!=-1&&p[tag][j]< dis[j])
	   {
		dis[j]=p[tag][j];
		ne[j]=tag;
	   }
    }
   System.out.printf("%d",max);
   }
}

