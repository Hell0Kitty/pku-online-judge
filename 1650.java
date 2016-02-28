import java.util.Scanner;
public class Main{
 public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
       double a;
	int d;
       a=sc.nextDouble();
       d=sc.nextInt();
	
	double ans;
	double min=a;
	int v1=0,v2=0,m=1,n=1;
	while(m<=d&&n<=d)
	{
		ans=m*1.0/n*1.0;
		if(ans>=a)
		{
			if(min>ans-a)
			{
				min=ans-a;
				v1=m;
				v2=n;
			}
			n++;
		}
		else if(ans<a)
		{
			if(min>a-ans)
			{
				min=a-ans;
				v1=m;
				v2=n;
			}
			m++;
		}
	}
	System.out.printf("%d %d",v1,v2);
  }
}