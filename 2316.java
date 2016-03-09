//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int[] a=new int[300];
  int k=0;
  while(in.hasNextInt())
  {

   String s=in.next();
   for(int i=0;i< s.length();i++)
    a[i]=(a[i]+s.charAt(i)-'0')%10;
   k=s.length();
  }
  for(int i=0;i< k;i++)
  {
   System.out.print(a[i]);
  }
 }
}

