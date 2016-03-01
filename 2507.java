//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
public class Main
{
 public static void main(String[] args) throws IOException
  {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(in.ready())
   {
	String[] ss=in.readLine().split(" ");
	double x=Double.parseDouble(ss[0]);
	double y=Double.parseDouble(ss[1]);
	double c=Double.parseDouble(ss[2]);
	double max=Math.min(x, y),min=0;
	for(int i=0;max-min>0.00001;i++)
	{
         double mid=(min+max)/2;
	 double d1=Math.sqrt(x*x-mid*mid);
	 double d2=Math.sqrt(y*y-mid*mid);
	 if(c*(d1+d2)==(d1*d2)){
		min=max=mid;
	        break;
	 }
	else if(c*(d1+d2)>(d1*d2)) max=mid;
	else min=mid;
       }
       System.out.printf("%.3f\n",(min+max)/2);
    }
  }
}

