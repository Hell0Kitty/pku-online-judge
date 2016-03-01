import java.util.Scanner;


public class Main {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		int[] initial= new int[k];
		int[] finish = new int[k];
		for(int i = 0; i< k; i++)
		{
			initial[i] = in.nextInt();
		}
		for(int i = 0; i< k; i++)
		{
			finish[i] = in.nextInt();
		}
		int sum = 0;
		for(int i = 0; i< k; i++)
		{
			int l = finish[i] - initial[i];
			if(l>0)
				sum += l;
		}
		System.out.println(sum);
	}
}

