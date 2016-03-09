//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int count=0;
  while(true)
  {
   count++;
   if(count!=1) System.out.println();
   int a=in.nextInt();
   if(a==0) break;
   int[] b=new int[a];
   for(int i=0;i< a;i++)
    b[i]=in.nextInt();
   for(int a1=0;a1< a-5;a1++)
    for(int a2=a1+1;a2< a-4;a2++)
     for(int a3=a2+1;a3< a-3;a3++)
      for(int a4=a3+1;a4< a-2;a4++)
       for(int a5=a4+1;a5< a-1;a5++)
    for(int a6=a5+1; a6< a; a6++){
     System.out.println(b[a1]+" "+b[a2]+" "+b[a3]+" "+b[a4]+" "+b[a5]+" "+b[a6]);
    }
    }
 }
}

