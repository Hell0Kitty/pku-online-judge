//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
	Scanner in=new Scanner(System.in);
	int a=in.nextInt();
	while((a--)!=0)
	{
         double D=in.nextDouble();
	  double d=in.nextDouble();
	  double s=in.nextDouble();
	  System.out.printf("%d\n", (int)(Math.PI/Math.asin((d+s)/(D-d))));
	}
  }
}

