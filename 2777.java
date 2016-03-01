import java.io.*;
import java.util.*;
public class Main
{
  static  tree[] mytree=new tree[300003];
  static boolean[] flag=new boolean[35];
  public static void main(String args[]) throws Exception
  {
     InputStreamReader is=new InputStreamReader(System.in);
     BufferedReader in=new BufferedReader(is);
     String[] ss=in.readLine().split(" ");
     int l=Integer.parseInt(ss[0]);
     int t=Integer.parseInt(ss[1]);
     int o=Integer.parseInt(ss[2]);
     buildtree(1,l,1);
     while(o--!=0)
      {
         ss=in.readLine().split(" ");
         if(ss[0].equals("C"))
         {
           int A=Integer.parseInt(ss[1]);
           int B=Integer.parseInt(ss[2]);
           if(A>B)
           {
            int temp=A;
            A=B;
            B=temp;
           }
           int p=Integer.parseInt(ss[3]);
           insert(A,B,p,1);

         }
          if(ss[0].equals("P"))
           {
            int A=Integer.parseInt(ss[1]);
            int B=Integer.parseInt(ss[2]);
            if(A>B)
            {
              int temp=A;
              A=B;
              B=temp;
           }
           Arrays.fill(flag, false);
           query(A,B,1);
           int count=0;
           for(int i=0;i< 35;i++)
            if(flag[i])
              count++;
           System.out.println(count);

       }
     }
   }

   public static void buildtree(int a,int b,int i)
    {
     	mytree[i]=new tree();
      	mytree[i].left=a;
       mytree[i].right=b;
      	mytree[i].color=1;
       if(a!=b)
        {
          int mid=(a+b)/2;
          buildtree(a,mid,i*2);
          buildtree(mid+1,b,i*2+1);
        }
   }

   public static void insert(int a,int b,int c,int i)
    {
       if(mytree[i].left==a&&mytree[i].right==b)
         mytree[i].color=c;
       else
       {
         if( mytree[i].color !=-1)
          {
            mytree[i*2].color =mytree[i].color ;
            mytree[i*2+1].color =mytree[i].color ;
            mytree[i].color =-1;
          }
        int mid=(mytree[i].left+mytree[i].right)/2;
        if(b<=mid)
           insert(a,b,c,2*i);
        else if(a>=mid+1)
           insert(a,b,c,2*i+1);
        else
        {
           insert(a,mid,c,2*i);
           insert(mid+1,b,c,2*i+1);
        }
     }

  }

   public static void query(int a,int b,int i)
    {
     if(mytree[i].color==-1)
     {
        if(mytree[2*i]==mytree[2*i+1]&&mytree[2*i].color!=-1)
            mytree[i].color=mytree[2*i+1].color;
     }
     if(mytree[i].color!=-1)
     {
         flag[mytree[i].color]=true;
      }
     else
     {
        int mid=(mytree[i].left+mytree[i].right)/2;
        if(b<=mid&&mytree[2*i]!=null)
           query(a,b,2*i);
        else if(a>=mid+1&&mytree[2*i+1]!=null)
           query(a,b,2*i+1);
        else
        {
           if(mytree[2*i]!=null)
            query(a,mid,2*i);
           if(mytree[2*i+1]!=null)
            query(mid+1,b,2*i+1);
        }
      }
   }
}

class tree
{
	int left;
	int right;
	int color;
}

