import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		for(int i=6;i<=a;i++)
		{
			for(int j=2;j<a;j++)
				for(int m=j;m<a;m++)
					for(int n=m;n<a;n++)
					{
						if((n*n*n+m*m*m+j*j*j)==i*i*i)
							System.out.println("Cube = "+i+", Triple = ("+j+","+m+","+n+")");
					}
		}
	}
}