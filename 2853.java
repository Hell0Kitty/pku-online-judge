//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
	Scanner in=new Scanner(System.in);
	int u=in.nextInt();
	while((u--)!=0)
	{
        int y=in.nextInt();
	 int a=in.nextInt();
	 int count=0;
	 int t=1;
	 for(int i=2;i< (Math.sqrt(2*a)+1);i++)
	 {
	   t+=i;
	   if((a-t)%i==0&&a>=t) count++;
	  }
	 System.out.println(y+" "+count);
       }
  }
}

