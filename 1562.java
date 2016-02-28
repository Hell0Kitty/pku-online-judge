import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		while(true)
		{
		int a=in.nextInt();
		int b=in.nextInt();
		if(a==0&&b==0)break;
		int count=0;
		int[][] arr=new int[a+2][b+2];
		for(int i=1;i<=a;i++){
			String s=in.next();
			for(int j=1;j<=b;j++)
				arr[i][j]=s.charAt(j-1);
		}
		for(int i=1;i<=a;i++)
			for(int j=1;j<=b;j++)
				if(arr[i][j]==64){
					find(arr,i,j);
					count++;
				}
		System.out.println(count);
		}
				
	}
	public static void find(int[][] a,int i,int j)
	{
			a[i][j]=65;
			for(int k=i-1;k<=i+1;k++)
				for(int w=j-1;w<=j+1;w++)
					if(a[k][w]==64)find(a,k,w);

	}
}