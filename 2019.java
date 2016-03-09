//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{

 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  String[] ss=in.readLine().split(" ");
  int a=Integer.parseInt(ss[0]);
  int b=Integer.parseInt(ss[1]);
  int c=Integer.parseInt(ss[2]);
  int[][] p=new int[a][a];
  for(int i=0;i< a;i++)
  {
   ss=in.readLine().split(" ");
   for(int j=0;j< a;j++)
     p[i][j]=Integer.parseInt(ss[j]);
  }
  while((c--)!=0)
  {
   ss=in.readLine().split(" ");
   int x=Integer.parseInt(ss[0]);
   int y=Integer.parseInt(ss[1]);
   int max=-99999,min=99999;
   for(int i=x-1;i< x+b-1;i++)
   {
     for(int j=y-1;j< y+b-1;j++)
     {
    if(p[i][j]>max)max=p[i][j];
      if(p[i][j]< min) min=p[i][j];
    }
      }
      System.out.println(max-min);
    }
  }
}

