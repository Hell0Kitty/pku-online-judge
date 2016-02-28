import java.util.*;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(true)
		{
			String s1=in.next();
			if(s1.equals("-1"))break;
			String s2=in.next();
			int max=0;
			for(int i=0;i<s1.length();i++)
			{
				int count =0;
				for(int j=0;j<s2.length();j++)
				{
					boolean bb=true;
					if(i+j>=s1.length())
					{
						bb=false;
						break;
					}
					if(!bb)break;
					if(s1.charAt(i+j)==s2.charAt(j))count++;
				}
				if(count>max)max=count;
			}
			for(int i=0;i<s2.length();i++)
			{
				int count =0;
				for(int j=0;j<s1.length();j++)
				{
					boolean bb=true;
					if(i+j>=s2.length())
					{
						bb=false;
						break;
					}
					if(!bb)break;
					if(s2.charAt(i+j)==s1.charAt(j))count++;
				}
				if(count>max)max=count;
			}
			int total=s1.length()+s2.length();
			int sum=max*2;
			System.out.print("appx("+s1+","+s2+") = ");
			if(sum==0)System.out.println(0);
			else if(sum==total)System.out.println(1);
			else 
			{
				while(true)
				{
					boolean bb=false;
					for(int i=2;i<=sum;i++)
					{
						if(sum%i==0&&total%i==0)
						{
							sum/=i;
							total/=i;
							bb=true;
						}
					}
					if(!bb)break;
				}
				System.out.println(sum+"/"+total);
			}
			
		}
	}
}