import java.io.*;
import java.util.Arrays;
public class Main
{
 static int[] p;
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
    int a=Integer.parseInt(in.readLine());
    if(a==0)break;
    double[][] dd=new double[a][4];
    for(int i=0;i< a;i++)
    {
      String[] ss=in.readLine().split(" ");
      for(int j=0;j< 4;j++)
        dd[i][j]=Double.parseDouble(ss[j]);
    }
    p=new int[a];
    for(int i=0;i< a;i++)
        p[i]=i;
    rir[] yy=new rir[7000];
    int len=0;
    for(int i=0;i< a;i++)
     for(int j=i+1;j< a;j++)
     {
      if(i==j) continue;
        double dis=(dd[i][0]-dd[j][0])*(dd[i][0]-dd[j][0])+
        (dd[i][1]-dd[j][1])*(dd[i][1]-dd[j][1])+
        (dd[i][2]-dd[j][2])*(dd[i][2]-dd[j][2]);
       dis=Math.sqrt(dis);
       dis-=dd[i][3];
       dis-=dd[j][3];
       if(dis< 0) dis=0;
         yy[len]=new rir(i,j,dis);
       len++;
    }
    Arrays.sort(yy,0,a*(a-1)/2);
    //for(int i=0;i< a*(a-1)/2;i++)
    //System.out.println(yy[i].juli+" "+yy[i].x+" "+yy[i].y);
    double sum=0;
    for(int i=0;i< len;i++)
    {
      if(un(yy[i].x,yy[i].y))
      {
       sum+=yy[i].juli;
      }
    }
    System.out.printf("%.3f\n",sum);

  }
 }

  static int root(int x)
  {
   int b=x;
   while(p[b]!=b)
    b=p[b];
   return p[x]=b;
  }

  static boolean un(int a,int b)
  {
   int aa=root(a);
   int bb=root(b);
   if(aa==bb)return false;
   if(aa>bb)
    p[aa]=bb;
    else p[bb]=aa;
    return true;
  }
}

class rir implements Comparable< rir>
{
 int x;
 int y;
 double juli;
 public rir(int xx,int yy,double j)
 {
    x=xx;y=yy;juli=j;
 }
 @Override
 public int compareTo(rir o) {
    if(juli-o.juli< 0)return -1;
    if(juli==o.juli)return 0;
    else return 1;
 }
}

