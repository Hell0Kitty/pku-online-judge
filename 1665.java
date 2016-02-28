import java.util.Scanner;


public class Main {
	public static void main(String[] args)
	{
		final double p = 3.1415927;
		int trans = 12 * 5280;
 		Scanner in = new Scanner(System.in);
 		int count = 1;
		while(true)
		{
			float diameter = in.nextFloat();
			int revolutions = in.nextInt();
			float time = in.nextFloat();
			if(revolutions == 0)
				break;
			double distance = revolutions * p * diameter / trans;
			double MPH = distance / time * 3600;
			System.out.print("Trip #"+count+": ");
			System.out.printf("%.2f %.2f", distance,MPH);
			System.out.println();
			count++;
		}
	}
}
