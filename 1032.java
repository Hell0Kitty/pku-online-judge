import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int total=0;
		int count=0;
		for(int i=2;;i++)
		{
			total+=i;
			count++;
			if(total>a){
				total-=i;
				count--;
				break;
			}
		}
		int b=a-total;
		int e=b/count;
		b=count-b%count;
		for(int i=2+e;i<count+e+2;i++)
		{
			if(b>0)
			System.out.print(i);
			else System.out.print((i+1));
			if(i!=count+e+1)System.out.print(" ");
			b--;
		}
	}
}