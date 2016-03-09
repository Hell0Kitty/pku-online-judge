//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{
 static int[] p;
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int n=Integer.parseInt(in.readLine());
  while((n--)!=0)
  {
   String[] ss=in.readLine().split(" ");
   int a=Integer.parseInt(ss[0]);
   int b=Integer.parseInt(ss[1]);
   p=new int[b];
   int[] ax=new int[b];
   int[] ay=new int[b];
   mymy[] gg=new mymy[b*b/2];
   int ll=0;
   for(int i=0;i< b;i++)
    p[i]=i;
   for(int i=0;i< b;i++)
   {
    ss=in.readLine().split(" ");
    ax[i]=Integer.parseInt(ss[0]);
    ay[i]=Integer.parseInt(ss[1]);
   }
   for(int i=0;i< b;i++)
   {
    for(int j=i+1;j< b;j++)
     {
    int juli=(ax[i]-ax[j])*(ax[i]-ax[j])+(ay[i]-ay[j])*(ay[i]-ay[j]);
    gg[ll++]=new mymy(i,j,juli);
     }
    }
   Arrays.sort(gg,0,ll);
   int cnt=0;
   for(int i=0;i< ll;i++)
   {
    if(un(gg[i].x,gg[i].y))
     {
    cnt++;
    if(cnt==b-a)
    {
      double hehe=Math.sqrt(gg[i].juli);
      System.out.printf("%.2f\n",hehe);
      break;
    }
      }
    }
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
class mymy implements Comparable< mymy>
{
    int x,y,juli;
    public mymy(int xx,int yy,int j)
    {
        x=xx;y=yy;juli=j;
    }
    @Override
    public int compareTo(mymy o) {
        return juli-o.juli;
    }
}

