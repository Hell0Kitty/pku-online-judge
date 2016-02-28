import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
   Scanner in=new Scanner(System.in);
   while(in.hasNext())
   {
	int a=in.nextInt();
	System.out.print(a+" ");
	double x1,y1,x,y,kx,ky;
	x=x1=in.nextDouble();
	y=y1=in.nextDouble();
	for(int i=1;i< a;i++)
	{
	  kx=in.nextDouble();
	  ky=in.nextDouble();
	  System.out.printf("%.6f %.6f ",(x+kx)/2,(y+ky)/2);
	  x=kx;
	  y=ky;
	}
	System.out.printf("%.6f %.6f\n",(x+x1)/2,(y+y1)/2);
      }
  }
}

