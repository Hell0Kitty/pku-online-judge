//* @author: 82638882@163.com
import java.io.*;
public class Main
{
 static int[] p,q,d;
 static int a,b;
 public static void main(String[] args) throws IOException
 {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    String[] ss=in.readLine().split(" ");
    a=Integer.parseInt(ss[0]);
    b=Integer.parseInt(ss[1]);
    p=new int[a+1];
    q=new int[a+1];
    for(int i=1;i<=a;i++)
    {
         ss=in.readLine().split(" ");
      p[i]=Integer.parseInt(ss[0]);
      q[i]=Integer.parseInt(ss[1]);
    }
    d=new int[b+1];
    for(int i=1;i<=a;i++)
        for(int j=b;j>=p[i];j--)
            d[j]=Math.max(d[j-p[i]]+q[i], d[j]);
    System.out.println(d[b]);
  }
}

