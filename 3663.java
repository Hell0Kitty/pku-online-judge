//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  int b=in.nextInt();
  ArrayList< Integer> arr=new ArrayList< Integer>();
  for(int i=0;i< a;i++)
    arr.add(in.nextInt());
  Collections.sort(arr);
  int count=0;
  for(int i=0;i< a-1;i++)
  {
    int l=b-arr.get(i);
    int min=i+1;
    int max=a-1;
    boolean bb=false;
    while(max>min)
    {
        int mid=(max+min)/2;
        if(arr.get(mid)>l) max=mid-1;
        else if(arr.get(mid)<=l) min=mid+1;
        bb=true;

    }
    if(bb)
    {
        if(arr.get(min)>l) count--;
        count+=min-i;
    }

    }
    System.out.println(count);
  }
}

