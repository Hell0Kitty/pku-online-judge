import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
	Scanner in=new Scanner(System.in);
	int a=in.nextInt();
	for(int i=0;i< a;i++)
	{
          long x=in.nextLong();
	  x=in.nextLong()-x;
	  long b=(long)Math.sqrt(x);
	  long ans=-1;
	  if(b==0) ans=0;
	  else if(b*b==x)ans=2*b-1;
	  else if(x<=b*b+b)ans=2*b;
	  else ans=2*b+1;
	  System.out.println(ans);
	 }
  }
}

