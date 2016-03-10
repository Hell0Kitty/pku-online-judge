mport java.io.*;
public class Main
{
 static int[][] q=new int[160001][17];
 static int[][] p=new int[160001][17];
 public static void main(String[] args) throws NumberFormatException, IOException
 {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    String[] ss=in.readLine().split(" ");
    int n=Integer.parseInt(ss[0]);
    int k=Integer.parseInt(ss[1]);
    int v=(int)(Math.log(n)/Math.log(2));
    for(int i=1;i<=n;i++)
        q[i][0]=p[i][0]=Integer.parseInt(in.readLine());
    for(int j=1;j<=v;j++)
    {
        for(int i=1;i<=n;i++)
        {
         int u= (int)Math.pow(2, j-1)+i;
         q[i][j]=Math.max(q[i][j-1],q[u][j-1]);
         p[i][j]=Math.min(p[i][j-1],p[u][j-1]);
        }
    }
      while((k--)!=0)
      {
    ss=in.readLine().split(" ");
    int x1=Integer.parseInt(ss[0]);
    int x2=Integer.parseInt(ss[1]);
    int t=x2-x1;
    if(t!=0) t=(int)(Math.log(t)/Math.log(2));
    int o=(int)Math.pow(2, t);
    int max=Math.max(q[x1][t], q[x2-o+1][t]);
    int min=Math.min(p[x1][t], p[x2-o+1][t]);
    System.out.println(max-min);
     }
  }
}

