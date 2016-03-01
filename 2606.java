import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  int[] arrx=new int[a];
  int[] arry=new int[a];

  for(int i=0;i< a;i++)
  {
   arrx[i]=in.nextInt();
   arry[i]=in.nextInt();
  }
  int max=0;
  for(int i=0;i< a-2;i++)
  {
   for(int j=i+1;j< a-1;j++)
   {
    int c=0;
    for(int u=j+1;u< a;u++)
    {
     if((arrx[i]-arrx[u])*(arry[i]-arry[j])==(arrx[i]-arrx[j])*(arry[i]-arry[u])) c++;
    }
    if(c>max) max=c;
   }
  }
  System.out.println(max+2);
 }
}

