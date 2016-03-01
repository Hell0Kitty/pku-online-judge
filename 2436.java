//* @author: 82638882@163.com
import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  String[] ss=in.readLine().split(" ");
  int n=Integer.parseInt(ss[0]);
  int d=Integer.parseInt(ss[1]);
  int k=Integer.parseInt(ss[2]);
  int[] q=new int[n];
  for(int i=0;i< n;i++)
  {
   ss=in.readLine().split(" ");
   int a=Integer.parseInt(ss[0]);
   for(int j=0;j< a;j++){
	int f=Integer.parseInt(ss[j+1]);
	q[i]+=Math.pow(2, f-1);
   }
  }
  System.out.println(f(d,k,q,0,0,0));
 }

 static int f(int d,int k,int[] q,int c,int s,int l)
 {
  if(c==k)
  {
	int ans=0;
	s=~s;
	for(int i=0;i< q.length;i++)
		if((s&q[i])==0)ans++;
	return ans;
   }
   if(l+k>d+c) return 0;
   int w=(int) Math.pow(2, l);
   return Math.max(f(d,k,q,c,s,l+1), f(d,k,q,c+1,s+w,l+1));
  }
}

