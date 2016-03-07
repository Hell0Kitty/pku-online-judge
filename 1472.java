import java.io.BufferedInputStream;
import java.util.Scanner;
import java.util.Arrays;

class Main
{
	public static Scanner cin=new Scanner(new BufferedInputStream(System.in));
	public static int [] coef=new int[11];
	public static String temp;
	public static void work(int con,int expo)
	{
		while (true)
		{
			temp=cin.next();
			switch (temp.charAt(0))
			{
				case 'O':
					coef[expo]+=con*Integer.parseInt(cin.next());
					break;
				case 'L':
					temp=cin.next();
					if (temp.charAt(0)=='n')
						work(con,expo+1);
					else
						work(con*Integer.parseInt(temp),expo);
					break;
				case 'E':
					return;
			}
		}
	}
	public static void output()
	{
		int i,j=0,now=0;
		for (i=0;i<=10;i++)
			if (coef[i]!=0)
				j++;
		if (j==0)
		{
			System.out.print(0);
			return;
		}
		else
			for (i=10;i>=0;i--)
				if (coef[i]!=0)
					if (i==0)
						System.out.print(coef[i]);
					else
					{
						if (coef[i]==1)
							System.out.print("n");
						else
							System.out.print(coef[i]+"*n");
						if (i>1)
							System.out.print("^"+i);
						if (now<j-1)
							System.out.print("+");
						now++;
					}
	}
	public static void main(String [] args)
	{
		int n=Integer.parseInt(cin.nextLine()),i;
		for (i=1;i<=n;i++)
		{
			Arrays.fill(coef,0);
			temp=cin.next();
			work(1,0);
			System.out.println("Program #"+i);
			System.out.print("Runtime = ");
			output();
			System.out.println();
			System.out.println();
		}
	}
}