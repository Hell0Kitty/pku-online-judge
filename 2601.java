import java.util.Scanner;
class Main
{
 public static void main(String[] args)
 {
   Scanner in=new Scanner(System.in);
   int n=in.nextInt();
   double a0=in.nextDouble();
   double an=in.nextDouble();
   double total=n*a0+an;
   double sum=0;
   int u=n;
   for(int i=0;i< n;i++,u--)
	sum+=in.nextDouble()*u;
   double ans=(total-sum*2)/(n+1);
   System.out.printf("%.2f",ans);
 }
}

