//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  int cnt=0;
  while((a--)!=0)
  {
   cnt++;
   String[] ss=in.readLine().split(" ");
   int t=Integer.parseInt(ss[0]);
   int w=Integer.parseInt(ss[1]);
   int[] p=new int[w];
   ss=in.readLine().split(" ");
   for(int i=0;i< w;i++)
    p[i]=Integer.parseInt(ss[i]);
   Arrays.sort(p);
   int sum=0,i,j;
   for(i=0;i< w;i++)
   {
    if(t< p[i])break;
    t-=p[i];
   }
   for(j=0;j< i;j++)
     sum+=(i-j)*p[j];
   System.out.println("Scenario #"+cnt+":");
   System.out.println("Steve wins with "+i+" solved problems and a score of "+sum+".");
   System.out.println();
  }
 }
}

