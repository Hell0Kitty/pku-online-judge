import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int c=0;
		while(true)
		{
			int a=in.nextInt();
			if(a==0)break;
			c++;
			int[] arr=new int[a];
			int total=0;
			for(int i=0;i<a;i++)
			{
				arr[i]=in.nextInt();
				total+=arr[i];
			}
			total/=a;
			int ans=0;
			for(int i=0;i<a;i++)
			{
				if(arr[i]>total)
					ans+=arr[i]-total;
			}
			System.out.println("Set #"+c);
			System.out.println("The minimum number of moves is "+ans+".");
			System.out.println();
		}
	}
}