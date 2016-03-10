 import java.io.*;
public class Main
{
 static int a,cnt=1;
 static int[] rank,un;
 static boolean[][] map;
 public static void main(String[] args) throws NumberFormatException, IOException
 {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    String[] ss=in.readLine().split(" ");
    a=Integer.parseInt(ss[0]);
    map=new boolean[a+1][a+1];
    rank=new int[a+1];
    un=new int[a+1];
    for(int i=1;i<=a;i++)
        un[i]=i;
    int b=Integer.parseInt(ss[1]);
    for(int i=0;i< b;i++)
    {
        ss=in.readLine().split(" ");
        int x=Integer.parseInt(ss[0]);
        int y=Integer.parseInt(ss[1]);
        map[x][y]=map[y][x]=true;
    }
    dsf(1,1,rank,un);
    int cnt=0;
    for(int i=1;i<=a;i++)
        rank[i]=0;
    for(int i=1;i<=a;i++)
    {
      int yy=root(i,un);
      for(int j=1;j<=a;j++)
      {
        if(!map[i][j])continue;
        int ww=root(j,un);
        if(ww!=yy)
        {
             rank[yy]++;
          if(rank[yy]>1)break;
        }
       }
    }
    for(int i=1;i<=a;i++)
    {
       if(rank[i]==1)cnt++;
    }
    System.out.println((cnt+1)/2);
 }


 static void dsf(int n,int pre,int[] rank,int[] un)
 {
    if(rank[n]!=0)
    {
      for(int i=1;i<=a;i++)
        if(rank[i]>rank[n]) union(i,n,un);
    }
    else
    {
      rank[n]=cnt++;
      for(int i=1;i<=a;i++)
      {
        if(map[i][n]&&i!=pre&&root(i,un)!=root(n,un))
          dsf(i,n,rank,un);
       }
       rank[n]=0;
    }
  }

static void union(int a,int b,int[] un)
 {
    int x1=root(a,un);
    int y1=root(b,un);
    if(x1>y1)un[x1]=y1;
    else un[y1]=x1;
 }

static int root(int a,int[] un)
 {
    int b=a;
    while(b!=un[b])
        b=un[b];
    return un[a]=b;
 }
}

