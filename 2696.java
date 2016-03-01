//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int k=in.nextInt();
  while((k--)!=0)
  {
    int[] arr=new int[9];
    for(int i=0;i< 9;i++)
    arr[i]=in.nextInt();
    int[] y=new int[arr[8]+1];
    y[0]=arr[0];
    y[1]=arr[1];
    y[2]=arr[2];
    for(int i=3;i<=arr[8];i++)
	 f(y,i,arr);
    System.out.println(y[arr[8]]);
   }
 }


  public static void f(int[] y,int n,int[] arr)
  {
   int u=0;
   if(n%2==1){
     u=arr[3]*y[n-1]+arr[4]*y[n-2]-arr[5]*y[n-3];
     u=(u%arr[6]+arr[6])%arr[6];
    }
    else
    {
	u=arr[5]*y[n-1]-arr[3]*y[n-2]+arr[4]*y[n-3];
	u=(u%arr[7]+arr[7])%arr[7];
     }
  y[n]=u;
 }
}

