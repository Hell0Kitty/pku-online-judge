import java.util.Scanner;


public class Main {
 public static void main(String[] args)
  {
	Scanner in = new Scanner(System.in);
	while(true)
	{
		int D = in.nextInt();
		int V = in.nextInt();
		if(D==0 && V==0)
			break;
		//double v1 = (d * d * d * Math.PI / 4 - v);
		double d1 = Math.pow(D*D*D-6*V/Math.PI,1.0/3);
		System.out.printf("%.3f%n", d1);
	}
  }
}

