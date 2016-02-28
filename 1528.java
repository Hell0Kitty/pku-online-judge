import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		System.out.println("PERFECTION OUTPUT");
		while(true)
		{
			int a=in.nextInt();
			if(a==0)break;
			double w=Math.sqrt(a);
			int total=1;
			for(int i=2;i<w;i++)
			{
				if(a%i==0)total+=(a/i+i);
			}
			if(a%w==0)total+=w;
			System.out.printf("%5d  ",a);
			if(a==1)System.out.println("DEFICIENT");
			else if(total>a)System.out.println("ABUNDANT");
			else if(total<a)System.out.println("DEFICIENT");
			else System.out.println("PERFECT");
		}
		System.out.println("END OF OUTPUT");
	}
}