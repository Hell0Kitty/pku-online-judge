/* @author: */
import java.util.Scanner;
public class Main{
  public static void  main(String args[])
{
  int p[]=new int[8010];
  int q[]=new int[8080];
  int n,k;
  Scanner sc=new Scanner(System.in);
  n=sc.nextInt();
  p[0]=0;
  for(int i=1;i< n;i++)
  {
     k=sc.nextInt();
     for(int j=i;j>k;j--)
      p[j]=p[j-1];
      p[k]=i;
  }
  for(int i=0;i< n;i++)
    q[p[i]]=i;
  for(int i=0;i< n;i++)
    System.out.printf("%d\n",q[i]+1);
  }
}

