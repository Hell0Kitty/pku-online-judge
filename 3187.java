//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{
    static int[] p,arr;
    static int a;
    public static void main(String[] args) throws IOException
    {
     InputStreamReader is=new InputStreamReader(System.in);
     BufferedReader in=new BufferedReader(is);
     String[] ss=in.readLine().split(" ");
     a=Integer.parseInt(ss[0]);
     int sum=Integer.parseInt(ss[1]);
     p=new int[a];
     arr=new int[a];
     for(int i=0;i< a;i++)
        p[i]=i+1;
     for(int u=0;;u++)
     {
      if(sum==get(arr))
      {
       for(int i=0;i< a;i++)
        System.out.print(p[i]+" ");
       break;
       }
      next();
      }
    }

 static void next()
 {
   for(int i=a-1;i>=0;i--)
    {
      for(int j=a-1;j>i;j--)
      {
        if(p[j]>p[i])
    {
        int temp=p[j];
        p[j]=p[i];
        p[i]=temp;
        Arrays.sort(p,i+1,a);
        return;
    }
      }
    }
  }


static int get(int[] arr)
 {
    int b=a;
    for(int i=0;i< b;i++)
        arr[i]=p[i];
    while((b--)!=0)
    {
     for(int i=0;i< b;i++)
        arr[i]=arr[i]+arr[i+1];
    }
    return arr[0];
  }
}

