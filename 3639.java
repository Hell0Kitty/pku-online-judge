 //* @author:
import java.util.*;
public   class Main{

    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);

    int i,n;
    double rate,us,ca,tus,tca,t1,t2;
    while (sc.hasNext()) {
        n=sc.nextInt();
        if(n==0) break;
        ca=1000;us=0;
        for (i=1;i<=n;i++) {
            rate=sc.nextDouble();
            t1=ca/rate*.97;
            t1=(Math.floor(t1*100))/100;
            t2=us*rate*.97;
            t2=(Math.floor(t2*100))/100;
            tus=(us>t1?us:t1);
            tca=(ca>t2?ca:t2);
            us=tus;ca=tca;
        }
        System.out.printf("%.2f\n",ca);
    }
  }

}

