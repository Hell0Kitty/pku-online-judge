import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		while((a--)!=0)
		{
			int b=in.nextInt();
			int ans=0;
			int c=b/2;
			if(b%2==0)ans=c*(c-1);
			else ans=c*c;
			System.out.println(ans);
		}
	}
}