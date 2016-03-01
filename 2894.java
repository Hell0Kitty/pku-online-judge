import java.util.Scanner;

public class Main{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i = 0; i< t; i++)
		{
			int n = in.nextInt();
			int[] result = new int[1012];
			int min = 1000;
			int max = 0;
			for(int j = 0; j< n; j++)
			{
				String x = in.next();
				int begin = in.nextInt();
				int end = in.nextInt();
				for(int k = begin; k< end; k++)
					result[k]++;
				if(max< end)
					max = end;
				if(min>begin)
					min = begin;
			}
			for(int j = min; j< max; j++)
			{
				if(result[j]!=0)
				{
					char res = (char)(result[j]+'A'-1);
					System.out.print(res);
				}
			}
			System.out.println();
		}
	}
}

