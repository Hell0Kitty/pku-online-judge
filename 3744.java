import java.util.*;
public class Main{

public static void main(String args[]){
    Scanner sc=new Scanner(System.in);

   double p,p1,p2,p3;
   while (sc.hasNext()) {
       int n=sc.nextInt();
       int a[]=new int[n+1];
       p=sc.nextDouble();
    for (int i=1;i<=n;i++)
           a[i]=sc.nextInt();
    if (a[1]==1) {System.out.println("0.0000000");continue;}
       int now=1;
    p1=0;p2=1;
    for (int i=2;;i++) {
      p3=p2*p+(1-p)*p1;
      if (i==a[now]) {
        now++;
        if (now>n) break;
        p3=0;
      }
      if (Math.abs(p2-p3)< 1e-8&&Math.abs(p2-p1)<1e-8) i=a[now]-1;
      p1=p2;p2=p3;
    }
    System.out.printf("%.7f\n",p2*(1-p));
   }
  }
}

