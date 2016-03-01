/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

	int a,b;
       a=sc.nextInt();
       b=sc.nextInt();
	int p1,p2,p3,d1,d2,d3;
	p1=(int)Math.sqrt(a*1.0);
	if(p1*p1< a) p1++;
	d1=(int)Math.sqrt(b*1.0);
	if(d1*d1< b) d1++;
	int v1=(p1-1)*(p1-1);
	int v2=(d1-1)*(d1-1);
	p2=(a-v1+1)/2;
	d2=(b-v2+1)/2;
	p3=(p1*p1-a)/2+1;
	d3=(d1*d1-b)/2+1;
	int ans=Math.abs(p1-d1)+Math.abs(p2-d2)+Math.abs(p3-d3);
	System.out.printf("%d\n",ans);
 }
}

