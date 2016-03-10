// @author: xuchang09@otcaix.iscas.ac.cn/
import java.io.*;
import java.util.*;
public class Main
{
  static  treex[] mytreex=new treex[210000];
  static int[] hash=new int[100005];
  static int[] left=new int[100005];
  static int[] right=new int[100005];
  static int[] data=new int[100005];
  static boolean build=false;
  static int k=0;

  public static void main(String args[]) throws Exception
  {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    String[] ss;
    StringBuffer res=new StringBuffer();
    while(true)
    {
        build=false;
       ss=in.readLine().split(" ");
       int n=Integer.parseInt(ss[0]);
       if(n==0)
           break;
       int q=Integer.parseInt(ss[1]);
       ss=in.readLine().split(" ");
       k=1;
       for(int i=0;i< n;i++)
       {
           data[i]=Integer.parseInt(ss[i]);
           if(i>0&&data[i]!=data[i-1])
           {
            right[k]=i-1;
            left[k+1]=i;
              k++;
           }
           hash[i]=k;
         }
         right[k]=n-1;
         for(int i=0;i< q;i++)
         {
            ss=in.readLine().split(" ");
            int begin=Integer.parseInt(ss[0])-1;
            int end=Integer.parseInt(ss[1])-1;
            if(hash[begin]==hash[end])
            {
                  res.append(end-begin+1);
                  res.append("\n");
                  continue;
            }
            if(hash[end]-hash[begin]==1)
            {
                int l=right[hash[begin]]-begin+1;
                int r=end-left[hash[end]]+1;
                int temp=l>r?l:r;
                res.append(temp);
                res.append("\n");
                continue;

            }
            if(!build)
            {
                  build=true;
                  buildtreex(1,k,1);
            }
            int n1=right[hash[begin]]-begin+1;
            int n2=end-left[hash[end]]+1;
            if(n1< n2)
                  n1=n2;
            n2=query(hash[begin]+1,hash[end]-1,1);
            res.append(n1>n2?n1:n2);
            res.append("\n");

        }
      }
      System.out.print(res.toString());
   }

  public static void buildtreex(int a,int b,int i)
  {
      if(mytreex[i]==null)
            mytreex[i]=new treex();
      mytreex[i].left=a;
      mytreex[i].right=b;
      if(a==b)
           mytreex[i].max=right[a]-left[a]+1;
      if(a!=b)
      {
           int mid=(a+b)/2;
           buildtreex(a,mid,i*2);
           buildtreex(mid+1,b,i*2+1);
           mytreex[i].max=mytreex[i*2].max>mytreex[i*2+1].max?mytreex[i*2].max:mytreex[i*2+1].max;
      }
   }


  public static int query(int a,int b,int i)
  {
     if(a==mytreex[i].left&&b==mytreex[i].right)
          return mytreex[i].max;
     int mid=(mytreex[i].left+mytreex[i].right)/2;
     if(b<=mid)
        return query(a,b,2*i);
     else if(a>=mid+1)
        return query(a,b,2*i+1);
     else
     {
       int l =query(a,mid,2*i);
       int r = query(mid+1,b,2*i+1);
       return l>r?l:r;
     }
  }

}

class treex
{
    int left;
    int right;
    int max;
}

