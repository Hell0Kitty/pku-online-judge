//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
  {
	int a=in.nextInt();
	if(a==0) break;
	a-=1960;
	a/=10;
	a=(int)Math.pow(2, a+2);
	double k=0;
	int n=2;
	while(k< a)
	{
          k+=Math.log(n)/Math.log(2);
	  n++;
	}
	System.out.println(n-2);
   }
 }
}

