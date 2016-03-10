//* @author:

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

class cin
{
static BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
static StringTokenizer st;
static int leave=0;
static int nextInt() throws IOException
{
   while(leave==0)
   {
    st=new StringTokenizer(in.readLine());
    leave=st.countTokens();
   }
   leave--;
   return Integer.parseInt(st.nextToken());
}
static String nextString() throws IOException
{
   while(leave==0)
   {
    st=new StringTokenizer(in.readLine());
    leave=st.countTokens();
   }
   leave--;
   return st.nextToken();
}
static boolean hasNext() throws IOException
{
   while(leave==0)
   {
    String temp=in.readLine();
    if(temp==null)return false;
    st=new StringTokenizer(temp);
    leave=st.countTokens();
   }
   return true;
}
}

class Node //树邻接表
{
int now,v=1;
Node next;
Node(int y)
{
   now=y;
   next=null;
}
}

class TreeArray //数状数组
{
    int value[],n;
    int now;
    Node tree[];
    int pis[][];
    TreeArray(int num,Node e[])
    {
    n=num;
    value=new int[n+1];
    tree=e;
    pis=new int[n+1][2];
    Arrays.fill(value,0);
    }

    int lowBit(int t)
    {
    return t&(t^(t-1));
    }

    void plus(int a,int i)
    {
    while(i<=n)
    {
       value[i]+=a;
        i+=lowBit(i);
    }
    }

    int getSum(int i)
    {
    int sum=0;
    while(i>0)
    {
       sum+=value[i];
       i=i-lowBit(i);
    }
    return sum;
    }
    void dfs(int t) //dfs记录时间
    {
    pis[t][0]=now;
    now++;
    Node p=tree[t].next;
    while(p!=null)
    {
       dfs(p.now);
       p=p.next;
    }
    pis[t][1]=now;

    }
    void init()
    {
    now=0;
    dfs(1);
    for(int i=1;i<=n;i++) //初始化树状树组
    {
       plus(1,i);
    }
    }
}

public class Main {
    public static void main(String args[]) throws IOException
    {
    int n,t1,t2,i;
    String s;
    n=cin.nextInt();
    Node lunch[]=new Node[n+1],temp;
    for(i=1;i<=n;i++)
    {
       lunch[i]=new Node(i);
    }
    for(i=0;i< n-1;i++)
    {
       t1=cin.nextInt();
       t2=cin.nextInt();
       temp=new Node(t2);
         temp.next=lunch[t1].next;
         lunch[t1].next=temp;
    }
    TreeArray data=new TreeArray(n,lunch);
    data.init();
    n=cin.nextInt();
    for(i=0;i< n;i++)
    {
       s=cin.nextString();
       t1=cin.nextInt();
       if(s.charAt(0)=='C')
       {
        if(data.tree[t1].v==1)
        {
         data.tree[t1].v=0;
         data.plus(-1,data.pis[t1][0]+1);
        }
        else
        {
         data.tree[t1].v=1;
         data.plus(1,data.pis[t1][0]+1);
        }
       }
       else
       {
        t2=data.getSum(data.pis[t1][0]);
        int t3=data.getSum(data.pis[t1][1]);
        System.out.println(t3-t2);
       }
    }
    }
}

