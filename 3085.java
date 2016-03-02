import java.util.Scanner;


public class Main {
 public static void main(String[] args)
 {
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	for(int i = 0; i < n; i++)
	{
	int sum = in.nextInt();
	int quarter = sum/25;
	sum = sum %25;
	int dime = sum/10;
	sum = sum%10;
	int nickel = sum/5;
	sum = sum%5;
	int penny = sum;
	System.out.println((i+1)+" "+quarter+" QUARTER(S), "+dime+" DIME(S), "+nickel+
		" NICKEL(S), "+penny+" PENNY(S)");
	}
  }
}

