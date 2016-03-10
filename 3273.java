//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  int b=in.nextInt();
  int[] c=new int[a];
  int total=0;
  int min=0;
  for(int i=0;i< a;i++)
  {
   c[i]=in.nextInt();
   total+=c[i];
   if(c[i]>min) min=c[i];
   }
  int max=total;
  while(max>min)
   {
    int mid=(max+min)/2;
    int t=0;
    int count=0;
    for(int i=0;i< a;i++)
    {
         t+=c[i];
      if(t>mid)
      {
        count++;
        t=c[i];
      }
    }
    if(count< b) max=mid;
    else min=mid+1;
   }
   System.out.println(min);
 }
}

