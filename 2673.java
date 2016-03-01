/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

 int total,per,t,max;
 total=sc.nextInt();
 per=sc.nextInt();
 t=sc.nextInt();
 max=total;
 while((t--)!=0)
 {
   int dis,speed,fir,sum;
   dis=sc.nextInt();
   speed=sc.nextInt();
   if(speed==0) continue;
   if(speed>=dis) max=0;
   fir=dis/speed;
   if(dis%speed==0) fir--;
   sum=fir+(total-fir)/2;
   if(sum< max) max=sum;
  }
  System.out.printf("%d",max*per);
 }
}

