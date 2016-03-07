import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] args)
	{
		Scanner in  = new Scanner(System.in);
		int time = 1;
		while(true)
		{
			int m = in.nextInt();
			int n = in.nextInt();
			if(m==0 && n==0)
			{
				break;
			}
			int[] cards = new int[n];
			boolean[] isUsed = new boolean[n*m+1];
			for(int i = 0; i<n; i++)
			{
				cards[i] = in.nextInt();
				isUsed[ cards[i]]=true;
			}
			Arrays.sort(cards);
			int result = n;
			for(int i = n-1; i>=0; i--)
			{
				
				int p=cards[i];
				if(p==n*m)
					continue;
				while(p < n*m)
				{
					if(isUsed[p+1] == false)
					{
						isUsed[p+1] = true;
						result--;
						break;
					}
					else
						p++;
				}
			}
			System.out.println("Case "+time+": "+result);
			time++;
		}
	}
}
