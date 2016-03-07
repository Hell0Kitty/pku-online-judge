import java.util.Scanner;
public class Main
{
	
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(true)
		{
			String s=in.next();
			if(s.equals("ENDOFINPUT"))break;
			int loc=in.nextInt();
			int n=in.nextInt();
			in.nextLine();
			int[] door=new int[n];
			int doors=0;
			for(int i=0;i<n;i++)
			{
				s=in.nextLine();
				if(s.equals(""))continue;
				String[] ss=s.split(" ");
				for(int j=0;j<ss.length;j++)
				{
					int u=Integer.parseInt(ss[j]);
					door[i]++;
					door[u]++;
					doors++;
				}
			}
			s=in.nextLine();
			int odd=0,even=0;
			for(int i=0;i<n;i++)
			{
				if(door[i]%2==0)even++;
				else odd++;
			}
			if(odd==0&&loc==0)System.out.println("YES "+doors);
			else if(odd==2&&loc!=0&&door[loc]%2==1&&door[0]%2==1)
				System.out.println("YES "+doors);
			else System.out.println("NO");
		}
	}
}
