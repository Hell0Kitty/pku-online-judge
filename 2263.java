//* @author: 82638882@163.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main
{
 static int[][] w=new int[256][256];
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int cnt=0;
  while(true)
  {
   cnt++;
   String[] ss=in.readLine().split(" ");
   int n=Integer.parseInt(ss[0]);
   int m=Integer.parseInt(ss[1]);
   if(n==0&&m==0) break;
   for(int i=0;i< n;i++)
    for(int j=0;j< n;j++)
    w[i][j]=0;
   for(int i=0;i< n;i++)
    w[i][i]=1000000000;
   String[] name=new String[n+1];
   int len=0;
   for(int i=0;i< m;i++)
   {
    ss=in.readLine().split(" ");
    int a=-1;
    for(int j=0;j< len;j++)
      if(ss[0].equals(name[j]))
       {
        a=j;
        break;
       }
    if(a==-1){
       a=len;
       name[len++]=ss[0];
    }
    int b=-1;
    for(int j=0;j< len;j++)
      if(ss[1].equals(name[j]))
      {
        b=j;
        break;
       }
    if(b==-1){
      b=len;
      name[len++]=ss[1];
    }
    w[a][b]=w[b][a]=Integer.parseInt(ss[2]);
     }
     ss=in.readLine().split(" ");
     int str=-1,dis=-1;
     for(int i=0;i< n;i++)
      {
    if(ss[0].equals(name[i]))
        str=i;
    if(ss[1].equals(name[i]))
        dis=i;
      }
     for(int k=0;k< n;k++)
    for(int i=0;i< n;i++)
     for(int j=0;j< n;j++)
       w[i][j]=Math.max(w[i][j], Math.min(w[i][k], w[k][j]));
     System.out.println("Scenario #"+cnt);
     System.out.println(w[str][dis]+" tons");
     System.out.println();
    }
  }
}

