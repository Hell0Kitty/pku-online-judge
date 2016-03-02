//* @author:
import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int i,j,n,k;
    while (sc.hasNext()) {
        n=sc.nextInt();
        k=sc.nextInt();
       if(n==0) break;
        int num[]=new int[n];
        int den[]=new int[n];
        double scores[]=new double[n];
        for (i=0;i< n;i++)
            num[i]=sc.nextInt();
        for (i=0;i< n;i++)
            den[i]=sc.nextInt();
        double lb = 0, ub = 1;
        for (i = 0; i < 100; i++) {
            double x = (lb+ub)/2;
            for (j = 0; j < n; j++)
	        scores[j] = num[j] - x*den[j];
            Arrays.sort(scores);
            double total = 0;
            for (j = k; j < n; j++)
	        total += scores[j];
            if (total >= 0) lb = x;
            else ub = x;
         }
        System.out.printf("%d\n",(int)(100*lb + 0.5));
    }
  }
}

