import java.util.*;
public class Main {
  
 public static void main(String[] args){

      Scanner in = new Scanner(System.in);
	long N,i,j,t,ans;
	int flag=0;

       N=in.nextLong();
	while(N>0)
	{
		flag=0;
		for(j=N-1;j>1;j--)
		{
			
			i=0;
			t=N;
			while(t%j==1)
			{
				t-=(t/j+1);
				i++;
			}
			if(t%j==0&&i==j)
			{
				flag=1;
				ans=j;
				System.out.printf("%d coconuts, %d people and 1 monkey\n",N,ans);

				break;
			}
		}
		if(flag==0)
			System.out.printf("%d coconuts, no solution\n",N);
	
		N=in.nextLong();
	}
   }
}
