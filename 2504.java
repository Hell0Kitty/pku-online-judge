import java.util.Scanner;
public class Main{
 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
int n;
double xx1,xx2,xx3,yy1,yy2,yy3,x,y,mnx,mxx,mny,mxy;

	int t=1;
	while(sc.hasNext())
	{
           n=sc.nextInt();
           if(n==0) break;
           xx1=sc.nextDouble();
           yy1=sc.nextDouble();
           xx2=sc.nextDouble();
           yy2=sc.nextDouble();
           xx3=sc.nextDouble();
           yy3=sc.nextDouble();
		double A1=2*(xx1-xx2);
		double A2=2*(xx1-xx3);
		double B1=2*(yy1-yy2);
		double B2=2*(yy1-yy3);
		double C1=xx1*xx1+yy1*yy1-xx2*xx2-yy2*yy2;
		double C2=xx1*xx1+yy1*yy1-xx3*xx3-yy3*yy3;
		double J=A1*B2-A2*B1;
		x=(C1*B2-C2*B1)/J;
		y=(A1*C2-A2*C1)/J;
		mnx=mny=999999999;
		mxx=mxy=-999999999;
		double angle=2*3.14159265358979/n;
		double xx,yy;
		for(int i=0;i< n;i++)
		{
		 xx=Math.cos(i*angle)*(xx1-x)-Math.sin(i*angle)*(yy1-y)+x;
		 yy=Math.sin(i*angle)*(xx1-x)+Math.cos(i*angle)*(yy1-y)+y;
		 if(xx< mnx)mnx=xx;
		 if(xx>mxx)mxx=xx;
		 if(yy< mny)mny=yy;
		 if(yy>mxy)mxy=yy;
		}
		mxx=mxx-mnx;
		mxy=mxy-mny;
		System.out.printf("Polygon %d: %.3f\n",t,mxx*mxy);
		t++;
	}
  }
}

