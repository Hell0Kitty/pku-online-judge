//* @author: 82638882@163.com
import java.io.*;
public class Main{
 static long ans=0;
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  ans=0;
  int[] arr=new int[a];
  int[] aww=new int[a];
  for(int i=0;i< a;i++)
  {
   String[] ss=in.readLine().split(" ");
   arr[i]=Integer.parseInt(ss[0]);
   aww[i]=Integer.parseInt(ss[1]);
  }
  for(int i=0;i< a;i++)
  {
   for(int j=0;j< a;j++)
    {
    if(arr[i]==aww[j])
    {
      arr[i]=j;
      break;
    }
     }
   }
  mergesort(arr,0,a);
  System.out.println(ans);

  }

  static void mergesort(int[] arr,int f,int n)
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


  static void merge(int[] arr,int f,int n1,int n2)
   {
    int[] temp=new int[n1+n2];
    int cp=0,cp1=0,cp2=0,i=0;
    while((cp1< n1)&&(cp2< n2))
     {
    if(arr[f+cp1]< arr[f+n1+cp2])
    temp[cp++]=arr[f+(cp1++)];
    else {
        temp[cp++]=arr[f+n1+(cp2++)];
        ans+=n1-cp1;
    }
     }
     while(cp1< n1)
    temp[cp++]=arr[f+(cp1++)];
     while(cp2< n2)
    temp[cp++]=arr[f+n1+(cp2++)];
     for(i=0;i< cp;i++)
    arr[f+i]=temp[i];
   }
}

