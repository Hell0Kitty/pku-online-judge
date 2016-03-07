import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		while((a--)!=0)
		{
			String s1=in.next();
			String s2=in.next();
			String s3=in.next();
			int max=0;
			for(int i=0;i<s1.length();i++)
			{
				char c=s1.charAt(i);
				int u=c-48;
				if(max<u)max=u;
			}
			for(int i=0;i<s2.length();i++)
			{
				char c=s2.charAt(i);
				int u=c-48;
				if(max<u)max=u;
			}
			for(int i=0;i<s3.length();i++)
			{
				char c=s3.charAt(i);
				int u=c-48;
				if(max<u)max=u;
			}
			boolean b=true;
			for(int o=max+1;o<17;o++)
			{
				int w1=Integer.parseInt(s1, o);
				int w2=Integer.parseInt(s2, o);
				int w3=Integer.parseInt(s3, o);
				if(w1*w2==w3)
					{
						System.out.println(o);
						b=false;
						break;
					}
			}
			if(b)System.out.println(0);
		}
	}
}