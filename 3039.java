/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
 double a,b,e,min;
 int c,d,u=0,v=0;
 a=sc.nextDouble();
 b=sc.nextDouble();
 a=a/b;
 c=d=1;
 min=32768;
 while(c< 32768&&d<32768)
 {
    e=c*1.0/d*1.0;
    if(e==a){
	d++;
	continue;
    }
    if(e>a){
	if(e-a< min){
	 min=e-a;
	 u=c;
	 v=d;
	}
	d++;
    }
   else {
      if(a-e< min){
	 min=a-e;
	 u=c;
	 v=d;
      }
      c++;
   }
  }
  System.out.printf("%d %d",u,v);
  }
}

