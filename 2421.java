//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 static int[] bin;
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  int[][] p=new int[a][a];
  for(int i=0;i< a;i++)
   for(int j=0;j< a;j++)
    p[i][j]=in.nextInt();
  bin=new int[a];
  for(int i=0;i< a;i++)
	bin[i]=i;
  int n=in.nextInt();
  while((n--)!=0)
  {
   int w1=in.nextInt();
   int w2=in.nextInt();
   union(w1-1,w2-1);
  }
  int ans=0,min,tag,tag2;
  lv: while(true)
      {
	min=9999999;
	tag=-1;tag2=-1;
	boolean bb=false;
	for(int i=0;i< a-1;i++)
	{
	  for(int j=i+1;j< a;j++)
	  {
	   if(root(j)!=root(i))
	   {
	    if(p[i][j]< min)
	     {
		min=p[i][j];
		tag=j;tag2=i;
	      }
	    bb=true;
	   }
	  }
	if(!bb) break lv;
	}
	union(tag2,tag);
	ans+=min;
      }
      System.out.println(ans);
    }

  static int  root(int b)
  {
   int a=b;
   while(bin[a]!=a)
	a=bin[a];
   bin[b]=a;
   return a;
  }

 static void union(int a,int b)
 {
	int a1=root(a);
	int b1=root(b);
	if(a1==b1) return;
	if(a1>b1) bin[a1]=b1;
	else bin[b1]=a1;
  }
}

