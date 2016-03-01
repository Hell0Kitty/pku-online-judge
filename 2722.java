import java.util.Scanner;
public class Main {

 public static void main(String[] args) {
 Scanner sc = new Scanner(System.in);

    double angle,p,a,b,c,t,l,xa,xb,ya,yb,k1,k2,x1,x2,y1,y2,l2;
    int n,i;
    while(sc.hasNext())
    {
        n=sc.nextInt();
        if(n==0) break;
        xa=sc.nextDouble();
        ya=sc.nextDouble();
        xb=sc.nextDouble();
        yb=sc.nextDouble();
        l=l2=0;
        for(i=0;i< n;i++)
        {
         t=sc.nextDouble();
         l+=t;
         l2+=t*t/2;
         }
        k1=ya/xa;k2=yb/xb;
        x1=l*(1+k2)/(k1-k2);x2=l*(1+k1)/(k1-k2);
        y1=k1*x1;y2=k2*x2;
        a=Math.sqrt(x1*x1+y1*y1);b=Math.sqrt(x2*x2+y2*y2);c=Math.sqrt(2)*l;
        p=0.5*(a+b+c);
        System.out.printf("%5.3f\n",Math.sqrt(p*(p-a)*(p-b)*(p-c))-l2);
    }
  }
}

