import java.util.Scanner;
public class Main{
  static int sum,n;
  static int arr[]=new int[20];
  static int j,FLAG;
  static boolean used[]=new boolean[20];

  static void f(int now,int total)
  {
	int i;
	if(total==sum)
	{
		FLAG=1;
		for(i=0;i<n;i++)
			if(used[i])
			{
				System.out.printf("%d",arr[i]);
				break;
			}
		for(i++;i<n;i++)
		{
			if(used[i])
				System.out.printf("+%d",arr[i]);
		}
		System.out.println("");
		return;
	}
	for(i=now;i<n;i++)
	{
		if(total+arr[i]>sum) continue;
		if(i>0&&arr[i]==arr[i-1]&&!used[i-1]) continue;
		used[i]=true;
		f(i+1,total+arr[i]);
		used[i]=false;
	}
}
public static void main(String args[])
{
   Scanner sc=new Scanner(System.in);
   while(true)
   {
        sum=sc.nextInt();
        n=sc.nextInt();
        if(n==0) break;
	   FLAG=0;
	   for(j=0;j<n;j++)
		   arr[j]=sc.nextInt();
		System.out.printf("Sums of %d:\n",sum);
			f(0,0);
			if(FLAG==0) System.out.println("NONE");
   }
  }
}
