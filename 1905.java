/* @author: */
import java.util.Scanner;
public class Main{
  static final  double PI=3.1415926;
  static final  double eps=1e-6;

  public static void main(String args[])
{
  Scanner sc=new Scanner(System.in);
  double L,n,C,M,y1,low,high,mid;
  while(true)
  {
     L=sc.nextDouble();
     n=sc.nextDouble();
     C=sc.nextDouble();
     if(L==-1&&n==-1&&C==-1)break;
     if(L<=eps||n<=eps||C<=eps)
	{
	  System.out.println("0.000");
	  continue;
	}
     M=(1+n*C)*L;
     low=0;
     high=PI;
     while(true)
     {
	mid=(low+high)/2;
	y1=M-L*mid/Math.sin(mid);
	if(Math.abs(y1)<=eps)break;
	else if(y1>0)low=mid;
	else high=mid;
     }
     System.out.printf("%.3f\n",L*Math.tan(mid/2)/2);
    }
  }
}

