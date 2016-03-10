/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
 int arr[]=new int[10010];
 int n,m,i,j,u;
 n=sc.nextInt();
 m=sc.nextInt();
 for(i=0;i< n;i++)
    arr[i]=sc.nextInt();
 for(i=0;i< m;i++)
 {
   int maxx=-1,tag=0;
   for(j=0;j< n;j++)
    if(arr[j]>maxx)
    {
    maxx=arr[j];
    tag=j;
     }
   System.out.printf("%d\n",tag+1);
   int add=arr[tag]/(n-1);
   int mod=arr[tag]%(n-1);
   for(j=0;j< n;j++)
    arr[j]+=add;
   for(j=0;j< mod;j++)
   {
    arr[j]++;
    if(j==tag) mod++;
   }
   arr[tag]=0;
  }
 }
}

