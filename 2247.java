import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  TreeSet< Integer> t=new TreeSet< Integer>();
  for(int i=0;i< 50;i++)
  {
   if(Math.pow(2, i)>2000000000) break;
   for(int j=0;;j++)
   {
    int ans2=(int)(Math.pow(2, i)*Math.pow(3, j));
    if(ans2>2000000000) break;
    for(int k=0;;k++)
    {
     int ans1=(int)(Math.pow(2, i)*Math.pow(3, j)*Math.pow(5, k));
     if(ans1>2000000000) break;
     for(int w=0;;w++)
     {
      int ans=(int)(Math.pow(2, i)*Math.pow(3, j)*Math.pow(5, k)*Math.pow(7, w));
      if(ans>2000000000) break;
      t.add(ans);
      }
     }
    }
   }
   Integer[] arr=new Integer[6000];
   t.toArray(arr);
   Scanner in=new Scanner(System.in);
   while(true)
   {
   int n=in.nextInt();
   if(n==0) break;
   if (n % 10==1&&n%100!=11) System.out.println("The "+n+"st humble number is "+arr[n-1]+".");
   else if (n % 10==2&&n%100!=12) System.out.println("The "+n+"nd humble number is "+arr[n-1]+".");
   else if (n % 10==3&&n%100!=13) System.out.println("The "+n+"rd humble number is "+arr[n-1]+".");
   else System.out.println("The "+n+"th humble number is "+arr[n-1]+".");
   }
 }
}

