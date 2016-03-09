//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  boolean flag=true;
  int sum=0;
  int[] arr=new int[a+1];
  for(int i=0;i< a;i++)
    arr[i]=in.nextInt();
  for(int i=0;i< a;i++)
  {
    if(flag)
    {
     if(arr[i]>arr[i+1])
     {
      sum+=arr[i];
      flag=false;
     }
    }
    else{
     if(arr[i]< arr[i+1])
      {
         sum-=arr[i]; flag=true;
      }
     }
    }
    System.out.println(sum);
  }
}

