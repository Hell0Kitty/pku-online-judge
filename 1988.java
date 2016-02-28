import java.util.Scanner;
import java.util.Arrays;
public class Main{
 static int p[]=new int[30010];
 static int d[]=new int[30010];
 static int num[]=new int[30010];
 static int i=0;
 static char c[]=new char[5];

 static int getup(int a)
 {
  int b=a;
   while(p[b]!=b)
    b=p[b];
  return p[a]=b;
 }

 static int getd(int a)
 {
   int b=a;
   int v=0;
   while(d[b]!=b)
   {
    v+=num[b];
    b=d[b];
   }
   num[a]=v;
   return d[a]=b;
 }

 public static void main(String[] args){
  Scanner sc=new Scanner(System.in);
  for(i=1;i< 30005;i++)
   p[i]=d[i]=i;
  Arrays.fill(num,0);
  int n,m,u,v;
  n=sc.nextInt();
  while((n--)!=0)
  {
	c=sc.next().toCharArray();
	if(c[0]=='C')
	{
         m=sc.nextInt();
	  getd(m);
	  System.out.printf("%d\n",num[m]);
	}
	else if(c[0]=='M')
	{
	  u=sc.nextInt();
         v=sc.nextInt();
	  int g1=getd(u);
	  int g2=getup(v);
	  d[g1]=g2;
	  p[g2]=g1;
	  num[g1]=1;
	}
   }
  }
}

