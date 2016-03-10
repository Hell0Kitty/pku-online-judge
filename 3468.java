//* @author
import java.util.*;
import java.io.*;

public class Main
{
 public static void main(String []args)
 {
  SegmentTree segmentTree=new SegmentTree();
 }
};
class SegmentTree
{
 public SegmentTree()
 {
  tot=0;
  int n,m,left,right,value;
  String str;
  Scanner input=new Scanner(System.in);
  n=input.nextInt();
  m=input.nextInt();
  for(int i=1;i<=n;i++)
   a[i]=input.nextInt();
  creatTree(1,1,n);
  for(int i=0;i< m;i++)
  {
   str=input.next();
   if(str.charAt(0)=='Q')
   {
    left=input.nextInt();
    right=input.nextInt();
    System.out.println(query(1,left,right,0));
   }
   else
   {
    left=input.nextInt();
    right=input.nextInt();
    value=input.nextInt();
    insert(1,left,right,value);
   }
  }
 }
 public long creatTree(int now,int left,int right)
 {
  if(now>tot)
   tot=now;
  _left[now]=left;
  _right[now]=right;
  long lSum=0,rSum=0;
  if(left< right)
  {
   lSum=creatTree(2*now,left,(left+right)/2);
   rSum=creatTree(2*now+1,(left+right)/2+1,right);
   _sum[now]=lSum+rSum;
  }
  else
   _sum[now]=a[left];
  return _sum[now];
 }
 public void insert(int now,int left,int right,int value)
 {
  if(now>tot)
   return ;
  if(left<=_left[now]&&right>=_right[now])
  {
   _d[now]+=value;
   return ;
  }
  long lSum=0,rSum=0;
  if(left<=(_left[now]+_right[now])/2)
   insert(2*now,left,right,value);
  if(right>(_left[now]+_right[now])/2)
   insert(2*now+1,left,right,value);
  if(2*now<=tot)
   lSum=_sum[2*now]+_d[2*now]*(_right[2*now]-_left[2*now]+1);
  if(2*now+1<=tot)
   rSum=_sum[2*now+1]+_d[2*now+1]*(_right[2*now+1]-_left[2*now+1]+1);
  _sum[now]=lSum+rSum;
 }
 public long query(int now,int left,int right,long d)
 {
  if(now>tot)
   return 0;
  if(left<=_left[now]&&right>=_right[now])
   return _sum[now]+(_d[now]+d)*(_right[now]-_left[now]+1);
  long lSum=0,rSum=0;
  if(left<=(_left[now]+_right[now])/2)
   lSum=query(2*now,left,right,d+_d[now]);
  if(right>(_left[now]+_right[now])/2)
   rSum=query(2*now+1,left,right,d+_d[now]);
  return lSum+rSum;
 }
 public static final int N=100005;
 public int tot;
 public int[] a=new int[N];
 public int[] _left=new int [3*N];
 public int[] _right=new int [3*N];
 public long[] _sum=new long [3*N];
 public long[] _d=new long [3*N];
}

