import java.util.Scanner;


public class Main{
 public static void main(String[] args)
 {
  Scanner in = new Scanner(System.in);
  double x1 = in.nextDouble();
  double y1 = in.nextDouble();
  double x2 = in.nextDouble();
  double y2 = in.nextDouble();
  //double r1 = 0;
  //double r2 = 0;
  //double d3 = 0;
  boolean canEscape = false;
  while(in.hasNext())
   {
	String s1 = in.next();
	in.skip(" ");
	String s2 = in.nextLine();
	//in.nextLine();
	double x3 = Double.parseDouble(s1);
	double y3 = Double.parseDouble(s2);
	double d1 = (x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1);
	double d2 = (x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2);
	if(d2 > 4 *  d1)
	{
	  canEscape = true;
	  System.out.print("The gopher can escape through the hole at ("+s1+','+s2+").");
	   break;
	}
    }

    if(canEscape == false)
	System.out.println("The gopher cannot escape.");
  }
}

