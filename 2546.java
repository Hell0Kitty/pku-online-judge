//* @author: ccQ.SuperSupper
import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
import java.math.*;
public class Main {

	/**
	 * @param args
	 */
	static double min(double a,double b)
	{
		if(a>b) return b;
		return a;
	}
	static double max(double a,double b)
	{
		if(a>b) return a;
		return b;
	}
	public static double Number3(double pDouble)
	{
		String pattern = "##0.###";
		DecimalFormat df = new DecimalFormat(pattern);
		String result = String.valueOf(df.format(pDouble));
		System.out.println(result);
		pDouble = Double.parseDouble(result);
		return pDouble;
	}

  public static void main(String[] args)throws Exception {
   // TODO Auto-generated method stub
   double x1,y1,r1,x2,y2,r2,disten,ans;

   Scanner cin = new Scanner(System.in);
   while(cin.hasNext()){
	x1 = cin.nextDouble();
	y1 = cin.nextDouble();
	r1 = cin.nextDouble();

	x2 = cin.nextDouble();
	y2 = cin.nextDouble();
	r2 = cin.nextDouble();

	disten = Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	if(disten>=r1+r2){
		ans = 0.0;
	}
	else if(disten+min(r1,r2)<=max(r1,r2)){
		ans = Math.acos(-1) * min(r1,r2) * min(r1,r2);
	}
	else
	{
	double ans1,ans2;
 ans1 = Math.acos((min(r1,r2)*min(r1,r2)+disten*disten-max(r1,r2)*max(r1,r2))/2.0/min(r1,r2)/disten);
 ans2 = Math.acos((max(r1,r2)*max(r1,r2)+disten*disten-min(r1,r2)*min(r1,r2))/2.0/max(r1,r2)/disten);
        ans = (r1+r2+disten)/2.0;
	ans = Math.sqrt(ans*(ans-r1)*(ans-r2)*(ans-disten));
	ans = max(r1,r2)*max(r1,r2)*ans2 + min(r1,r2)*min(r1,r2)*ans1 - 2.0*ans;
	}
	//	ans = Math.floor(ans*1000+0.5)/1000;

	DecimalFormat df = new DecimalFormat("##0.000");
	System.out.println(df.format(ans));
   }
}

}

