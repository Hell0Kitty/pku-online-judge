//* @author: 82638882@163.com
import java.util.HashMap;
import java.util.Scanner;

public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int n=in.nextInt();
  int[] arr=new int[n];
  HashMap< String,Integer> hs=new HashMap< String,Integer>();
  String s=in.nextLine();
  int tag=-1;
  for(int i=0;i< n;i++)
  {
    s=in.nextLine();
    s=s.trim();
    if(s.equals("Li Ming"))tag=i;
    hs.put(s, i);
   }
   int m=in.nextInt();
   for(int i=0;i< m;i++)
   {
    for(int j=0;j< n;j++)
    {
        int num=in.nextInt();
        s=in.nextLine();
        s=s.trim();
        int u=hs.get(s);
        arr[u]+=num;
    }
    int ww=arr[tag];
    int cnt=1;
    for(int j=0;j< n;j++)
        if(arr[j]>arr[tag])cnt++;
    System.out.println(cnt);
    }

  }

}

