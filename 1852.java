import java.io.*;
import java.util.*;
public class Main {

	/**
	 * @param args
	 */
	static int max(int a,int b)
	{
		if(a>b) return a;
		return b;
	}
	static int min(int a,int b)
	{
		if(a>b) return b;
		return a;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int t,n,m,ans1,ans2,i,k;
		
		Scanner cin = new Scanner(System.in);
		
		t = cin.nextInt();
		while(t>0)
		{
			--t;
			
			n = cin.nextInt();
			m = cin.nextInt();
			
			ans1 = 0;ans2 = 0;
			
			for(i=0;i<m;++i)
			{
				k = cin.nextInt();
				ans1 = max(ans1,min(k,n-k));
				ans2 = max(ans2,max(k,n-k));
			}
			System.out.println(ans1+" "+ans2);
		}

	}

}
