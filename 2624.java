/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

	double x1,y1,x2,y2,x3,y3,x4,y4,x5=0,y5=0;
	while(sc.hasNext())
	{
       x1=sc.nextDouble();
       y1=sc.nextDouble();
       x2=sc.nextDouble();
       y2=sc.nextDouble();
       x3=sc.nextDouble();
       y3=sc.nextDouble();
       x4=sc.nextDouble();
       y4=sc.nextDouble();
	   if(x1==x3&&y1==y3)
		{
			x5=x4-x3+x2;
			y5=y4-y3+y2;
		}
		else if(x1==x4&&y1==y4)
		{
			x5=x2-x1+x3;
			y5=y2-y1+y3;
		}
		else if(x2==x4&&y2==y4)
		{
			x5=x1-x2+x3;
			y5=y1-y2+y3;
		}
		else if(x2==x3&&y2==y3)
		{
			x5=x1-x2+x4;
			y5=y1-y2+y4;
		}
		System.out.printf("%4.3f %4.3f\n",x5,y5);
	}
 }
}


