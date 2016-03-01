/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  double x[]=new double[21],sum;
  int n,flag;
  int i,j;
  while(sc.hasNext())
    {
      n=sc.nextInt();
      if(n==0) break;
        for(i=0;i< n;i++)
         x[i]=sc.nextDouble();
        Arrays.sort(x,0,n);
        sum=0;flag=0;
        for(i=0;i< n-1;i++)
        {
            sum+=x[i];
            for(j=i+1;j< n;j++)
            if(x[j]<=sum)
            {
                flag=1;
               break ;
            }
        }

    	if(flag!=0) System.out.printf("YES\n");
    	else System.out.printf("NO\n");
    }
   }
}

