import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		while((a--)!=0)
		{
			in.nextInt();
			boolean bb=false;
			int m=in.nextInt();
			int d=in.nextInt();
			if((m+d)%2==0)bb=true;
			else if(m==9&&d==30)bb=true;
			else if(m==11&&d==30)bb=true;
			if(bb)System.out.println("YES");
			else System.out.println("NO");
		}
	}
}

