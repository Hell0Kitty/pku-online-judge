import java.util.Scanner;


public class Main {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		int[][] grids = new int[101][101];
		for(int i = 0; i<num; i++)
		{
			String color = in.next();
			int x = in.nextInt();
			int y = in.nextInt();
			int l = in.nextInt();
			if(color.equals("BLACK"))
			{
				for(int j = x; j<x+l; j++)
				{
					for(int k = y; k<y+l; k++)
					{
						grids[j][k] = 1;
					}
				}
			}
			if(color.equals("WHITE"))
			{
				for(int j = x; j<x+l; j++)
				{
					for(int k = y; k<y+l; k++)
					{
						grids[j][k] = 0;
					}
				}
			}
			if(color.equals("TEST"))
			{
				int count = 0;
				for(int j = x; j<x+l; j++)
				{
					for(int k = y; k<y+l; k++)
					{
						if(grids[j][k] == 1)
							count++;
					}
				}
				System.out.println(count);
			}
		}
	}
}	
