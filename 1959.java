import java.text.DecimalFormat;
import java.util.Scanner;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a[]=new int[100];
    int n,T;
    long sum;
    a[0]=0;
    for(int i=1;i<=20;i++)
    {
        a[i]=i;
        a[20+i]=2*(i);
        a[40+i]=3*(i);
    }
    a[61]=25;
    a[62]=50;

    T=sc.nextInt();
    for(int t=0;t< T;t++)
    {
        sum=0;
        n=sc.nextInt();
        for(int i=0;i<=62;i++)
          for(int j=i;j<=62;j++)
           for(int k=j;k<=62;k++)
       	if(a[i]+a[j]+a[k]==n)
  		  sum++;
  	  System.out.printf("Scenario #%d:\n%d\n\n",t+1,sum);


    }
  }
}

