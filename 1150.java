import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int[] b2=new int[]{6,2,4,8};
		int[] b3=new int[]{1,3,9,7};
		int[] b7=new int[]{1,7,9,3};
		int[] b9=new int[]{1,9,1,9};
		while(in.hasNext())
		{
			int n=in.nextInt();
			int m=n-in.nextInt();
			int e,a2=0,a3=0,a5=0,a7=0,a9=0;
			e=n;while((e=e/2)!=0)a2+=e;
			e=m;while((e=e/2)!=0)a2-=e;
			e=n;while((e=e/5)!=0)a5+=e;
			e=m;while((e=e/5)!=0)a5-=e;
			a3=f(n,3)-f(m,3);
			a7=f(n,7)-f(m,7);
			a9=f(n,9)-f(m,9);
			int ans=1;
			if(a5>a2)System.out.println(5);
			else{
				a2-=a5;
				if(a2!=0){
					a2=a2%4;
					ans*=b2[a2];
				}
				ans*=b3[a3%4];
				ans=ans%10;
				ans*=b7[a7%4];
				ans=ans%10;
				ans*=b9[a9%4];
				ans=ans%10;
				System.out.println(ans);
			}
		}
	}
	public static int f(int n,int a)
	{
		if(n==0)return 0;
		else return f(n/2,a)+g(n,a);
	}
	public static int g(int n,int a)
	{
		if(n==0)return 0;
		else if(n%10<a)return n/10+g(n/5,a);
		else return n/10+1+g(n/5,a);
	}
}