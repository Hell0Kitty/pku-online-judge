/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
 int n,L,v;
 n=sc.nextInt();
 L=sc.nextInt();
 int m=0;
 while((n--)!=0)
 {
     v=sc.nextInt();
     if(v%L==0)continue;
     int u=L-v%L;
     if(u>m)m=u;
  }
  System.out.printf("%d",m);
 }
}

