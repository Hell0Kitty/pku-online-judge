import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
/*
 *参考大牛的程序,第一次写树状树组...
 *先将cows以volume为关键字排序..
 *两个树状数组,一个维护点个数,一个维护前面坐小于当前点的坐标之和
 */
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

class TreeArray
{
    int value[],n;
    TreeArray(int num)
    {
     n=num;
     value=new int[n+1];
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
}

class Moo
{
 int x,v;
 Moo(int a,int b)
 {
  v=a;x=b;
 }
}

class Cmp implements Comparator< Object>
{
 public int compare(Object a,Object b)
 {
  if(((Moo)a).v>((Moo)b).v)return 1;
  return -1;
 }
}

class MooFest
{
 TreeArray count,total;
 long sum=0,now=0;
 int n,i;
 Moo cow[];
 MooFest() throws IOException
 {
  n=cin.nextInt();
  cow=new Moo[n+1];
  count=new TreeArray(20000);
  total=new TreeArray(20000);
  for(i=1;i<=n;i++)
  {
   cow[i]=new Moo(cin.nextInt(),cin.nextInt());
  }
  Arrays.sort(cow,1,n+1,new Cmp());
 }

 long totalV()
 {
  int c,t;
  for(i=1;i<=n;i++)
  {
   now+=cow[i].x;
   count.plus(1,cow[i].x);
   total.plus(cow[i].x,cow[i].x);
   c=count.getSum(cow[i].x);
   t=total.getSum(cow[i].x);
   sum+=(long)(2*c*cow[i].x-2*t+now-i*cow[i].x)*cow[i].v;
  }
  return sum;
 }
}
public class Main {
     public static void main(String args[]) throws IOException
     {
      MooFest data=new MooFest();
      System.out.println(data.totalV());
     }
}

