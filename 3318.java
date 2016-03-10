//* @author: 82638882@163.com
import java.io.*;
import java.util.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    int a=Integer.parseInt(in.readLine());
    int[][] p1=new int[a][a];
    int[][] p2=new int[a][a];
    int[][] p3=new int[a][a];
    for(int i=0;i< a;i++)
    {
        String[] ss=in.readLine().split(" ");
        for(int j=0;j< a;j++)
          p1[i][j]=Integer.parseInt(ss[j]);
    }
    for(int i=0;i< a;i++)
    {
        String[] ss=in.readLine().split(" ");
        for(int j=0;j< a;j++)
          p2[i][j]=Integer.parseInt(ss[j]);
    }
    for(int i=0;i< a;i++)
    {
        String[] ss=in.readLine().split(" ");
        for(int j=0;j< a;j++)
          p3[i][j]=Integer.parseInt(ss[j]);
    }
      int i;
      if(a< 50) i=Math.min(2000, a*a);
      else if(a< 100) i=5000;
      else i=50000;
      while((i--)>0)
     {
     int x=(int)(Math.random()*a);
     int y=(int)(Math.random()*a);
     int ans=0;
     for(int j=0;j< a;j++)
         ans+=p1[x][j]*p2[j][y];
     if(ans!=p3[x][y]) break;
     }
     if(i==-1) System.out.println("YES");
     else System.out.println("NO");
  }
}

