//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  TreeSet< Long> t=new TreeSet< Long>();
  Scanner in=new Scanner(System.in);
  long a=in.nextInt();
  long b=in.nextInt();
  long c=in.nextInt();
  int d=in.nextInt();
  long[] arr=new long[d+1];
  arr[0]=1;
  int x1=0,x2=0,x3=0;
  for(int i=1;i<=d;i++)
  {
   	long y1=arr[x1]*a;
	long y2=arr[x2]*b;
	long y3=arr[x3]*c;
	long min=Math.min(y1, y2);
	min=Math.min(min, y3);
	arr[i]=min;
	if(min==y1) x1++;
	if(min==y2) x2++;
	if(min==y3) x3++;
   }
   System.out.println(arr[d]);

  }
}

