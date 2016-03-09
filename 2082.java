import java.io.*;
public class Main
{
 static int[] p,b,c,w;
 static int a;
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
    String[] ss=in.readLine().split(" ");
    a=Integer.parseInt(ss[0]);
    if(a==-1)break;
    p=new int[a+2];
    b=new int[a+1];
    c=new int[a+1];
    w=new int[a+1];
    for(int i=1;i<=a;i++)
    {
        ss=in.readLine().split(" ");
        w[i]=Integer.parseInt(ss[0]);
        p[i]=Integer.parseInt(ss[1]);
    }
    p[0]=p[a+1]=-1;
    long max=0;
    for(int i=1;i<=a;i++)
    {
        b[i]=1;
        int j=i;
        while(p[j-b[j]]>=p[i])
        {
            j-=b[j];
            b[i]+=b[j];
        }
    }
    for(int i=a;i>0;i--)
    {
        c[i]=1;
        int j=i;
        while(p[j+c[j]]>=p[i])
        {
            j+=c[j];
            c[i]+=c[j];
        }
    }
    for(int i=1;i<=a;i++)
    {
        int total=w[i];
        for(int u=1;u< c[i];u++)
            total+=w[u+i];
        for(int u=1;u< b[i];u++)
            total+=w[i-u];
        long ans=total*p[i];
        max=Math.max(ans, max);
    }
    System.out.println(max);
   }
 }
}

