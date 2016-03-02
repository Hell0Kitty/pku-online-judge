//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{
 static long ans=0;
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  int cnt=0;
  while((a--)!=0)
  {
   ans=0;
   cnt++;
   String[] ss=in.readLine().split(" ");
   int n=Integer.parseInt(ss[2]);
   my[] p=new my[n];
   for(int i=0;i< n;i++)
   {
	ss=in.readLine().split(" ");
	int x1=Integer.parseInt(ss[0]);
	int y1=Integer.parseInt(ss[1]);
	p[i]=new my(x1,y1);
    }
    Arrays.sort(p);
    mergesort(p,0,n);
    System.out.println("Test case "+cnt+": "+ans);
   }
 }

 static void mergesort(my[] arr,int f,int n)
 {
   int n1,n2;
   if(n>1)
   {
	n1=n/2;
	n2=n-n1;
	mergesort(arr,f,n1);
	mergesort(arr,f+n1,n2);
	merge(arr,f,n1,n2);
   }
 }


 static void merge(my[] arr,int f,int n1,int n2)
 {
  int[] temp=new int[n1+n2];
  int cp=0,cp1=0,cp2=0,i=0;
  while((cp1< n1)&&(cp2< n2))
  {
	if(arr[f+cp1].y< arr[f+n1+cp2].y)
		temp[cp++]=arr[f+(cp1++)].y;
	else if (arr[f+cp1].y==arr[f+n1+cp2].y)
	{
		temp[cp++]=arr[f+(cp1++)].y;
	}
	else {
		temp[cp++]=arr[f+n1+(cp2++)].y;
		ans+=n1-cp1;
	}
   }
  while(cp1< n1)
	temp[cp++]=arr[f+(cp1++)].y;
  while(cp2< n2)
	temp[cp++]=arr[f+n1+(cp2++)].y;
  for(i=0;i< cp;i++)
	arr[f+i].y=temp[i];
 }
}

class my implements Comparable< my>
{
	int x,y;
	public my(int a,int b)
	{
         x=a;
	  y=b;
	}
	public int compareTo(my arg0) {
	  if(x==arg0.x)
		 return y-arg0.y;
	  return x-arg0.x;
	}
}

