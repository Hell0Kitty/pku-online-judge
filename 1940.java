import java.util.*;
public class Main
{
 public static void main(String[] args)
  {
   Scanner in=new Scanner(System.in);
   while(in.hasNext())
   {
	int a=in.nextInt();
	double[] x=new double[a];
	double[] y=new double[a];
	for(int i=0;i< a;i++)
	{
		x[i]=in.nextDouble();
		y[i]=in.nextDouble();
	}
	double sx=0,sy=0,uu=-1;
	System.out.print(a);
	for(int i=0;i< a;i++)
	{
		sx=sy=0;
		for(int j=i;j< a+i;j++)
		{
		  sx+=x[j%a]*Math.pow(uu, j-i);
		  sy+=y[j%a]*Math.pow(uu, j-i);
		}
		System.out.printf(" %.6f %.6f",sx,sy);
	}
	System.out.println();
    }
  }
}

