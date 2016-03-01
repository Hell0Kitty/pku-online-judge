//* @author: 82638882@163.com
import java.io.*;
class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int cnt=Integer.parseInt(in.readLine());
  while((cnt--)!=0)
  {
   int[][] p=new int[9][9];
   for(int i=0;i< 9;i++)
   {
	for(int j=0;j< 9;j++)
          p[i][j]=in.read()-'0';
        in.readLine();
   }
   uu(0,0,p);
   for(int i=0;i< 9;i++)
   {
     for(int j=0;j< 9;j++)
	System.out.print(p[i][j]);
     System.out.println();
    }
   }
  }

  public static boolean uu(int a,int b,int[][] p)
  {
   if(b>8)
    {
	a++;
	b=0;
	if(a>8) return true;
    }
    if(p[a][b]!=0)return uu(a,b+1,p);
    int[] uu=new int[10];
    for(int k=0;k< 9;k++)
    {
	uu[p[a][k]]++;
	uu[p[k][b]]++;
    }
    int w=a/3,t=b/3;
    for(int k=w*3;k< w*3+3;k++)
	for(int h=t*3;h< t*3+3;h++)
	   uu[p[k][h]]++;
    for(int k=1;k< 10;k++)
    {
	if(uu[k]!=0) continue;
	p[a][b]=k;
	if(uu(a,b+1,p)) return true;
    }
    p[a][b]=0;
    return false;
   }
}

