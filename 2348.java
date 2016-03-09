/* @author: */
import java.util.Scanner;
public class Main{
 static boolean judge(int x,int y)
{
    int t;
    if(x< y) {t=x;x=y;y=t;}
    if(x%y==0) return true;
    if(x-y< y) return !judge(y,x-y);
    return true;
}

 public static void main(String args[])
{
   Scanner sc=new Scanner(System.in);
   int m,n;
   while(sc.hasNext())
   {
      m=sc.nextInt();
      n=sc.nextInt();
      if(m==0&&n==0) break;
      if(judge(m,n)) System.out.println("Stan wins");
      else System.out.println("Ollie wins");
   }
  }
}

