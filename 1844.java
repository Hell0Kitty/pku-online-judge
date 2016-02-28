import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
			int sun=in.nextInt();
			int sum=0;
			int i;
			for(i=1;i<9999;i++)
			{
				sum+=i;
				if (sum>=sun)break;
			}
			if((sum-sun)%2==0)System.out.println(i);
			else if((sum-sun)%2==1&&i%2==1)System.out.println(i+2);
			else if((sum-sun)%2==1&&i%2==0)System.out.println(i+1);
	}
}