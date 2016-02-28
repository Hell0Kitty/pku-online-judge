import java.util.Scanner;


public class Main {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i = 0; i < n; i++)
		{
			int one = in.nextInt();
			int two = in.nextInt();
			int three = in.nextInt();
			int four = in.nextInt();
			int d1 = two - one;
			int d2 = three - two;
			int d3 = four - three;
			if((d1 == d2)&&(d3 == d2))
			{
				int five = four + d1;
				System.out.println(one+" "+two+" "+three+" "+four+" "+five);
			}
			else
			{
				int five = four * (two/one);
				System.out.println(one+" "+two+" "+three+" "+four+" "+five);
			}
		}
	}
}

