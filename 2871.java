import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
  Scanner in = new Scanner(System.in);
  double first = in.nextDouble();
  while(true)
   {
	double second = in.nextDouble();
	if(second == 999)
	{
		System.out.println("End of Output");
		break;
	}
	System.out.printf("%2.2f",second - first);
	System.out.println();
	first = second;
    }
  }
}

