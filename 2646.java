import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
  {
   int a=in.nextInt();
   if(a==0) break;
   double[] d=new double[a];
   double total=0;
   for(int i=0;i< a;i++)
   {
	d[i]=in.nextDouble();
	total+=d[i];
   }
   double avg=total/a;
   long t=Math.round(avg*100);
   avg=(double)t/100;
   double d1=0,d2=0;
   for(int i=0;i< a;i++)
   {
	if(d[i]>avg)d1+=d[i]-avg;
	else d2+=avg-d[i];
   }
   System.out.printf("$%.2f\n",Math.min(d1, d2));
  }
 }
}

