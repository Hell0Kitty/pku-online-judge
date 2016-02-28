import java.util.Scanner;
import java.util.Arrays;
public class Main{
 static long ans[]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
 public static void  main(String args[]){
	int n;
       Scanner sc=new Scanner(System.in);
       n=sc.nextInt();
	int p[]=new int[25];
	while((n--)!=0){
		Arrays.fill(p,0);
		int  a;
              a=sc.nextInt();
		int len=0,i;
		while(a!=0)
		{
			int u=a%3;
			p[len++]=u;
			a/=3;
		}
		for(i=0;i<len;i++)
		{
			if(p[i]==2)
			{
				p[i]=-1;
				p[i+1]++;
			}
			if(p[i]==3)
			{
				p[i]=0;
				p[i+1]++;
			}
		}
		boolean bb=false;
		for(i=0;i<=len;i++)
		{
			if(p[i]==-1)
			{
				if(bb) System.out.printf(",");
				System.out.printf("%d",ans[i]);
				bb=true;
			}
		}
		if(!bb) System.out.printf("empty");
		System.out.printf(" ");
		bb=false;
		for(i=0;i<=len;i++)
		{
			if(p[i]==1)
			{
				if(bb) System.out.printf(",");
				System.out.printf("%d",ans[i]);
				bb=true;
			}
		}
		System.out.println();
	}
  }
}