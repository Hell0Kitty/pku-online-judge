//* @author:
import java.util.*;
public class Main
{

 public static void main(String[] args){
   Scanner sc = new Scanner(System.in);
   int m=sc.nextInt();
   int n=sc.nextInt();
   int k=sc.nextInt();
   node a[]=new node[k+1];
   for(int i=0;i<=k;i++)
     a[i]=new node();
    for (int i=1;i<=k;i++) {
        a[i].p=sc.nextDouble();
        a[i].pm=a[i-1].pm+a[i].p;
        a[i].pn=a[i-1].pn+a[i].p;
        if (i>m) a[i].pm-=a[i-m].p;
        if (i>n) a[i].pn-=a[i-n].p;
    }
    for (int i=n;i<=k;i++) {
        if (a[i].pm/m>a[i].pn/n&&(a[i-1].pm/m< a[i-1].pn/n||i==n))
          System.out.printf("BUY ON DAY %d\n",i);
        else if (a[i].pm/m< a[i].pn/n&&(a[i-1].pm/m>a[i-1].pn/n||i==n))
          System.out.printf("SELL ON DAY %d\n",i);
    }
  }
}

class node{
   double p;
   double pm;
   double pn;

   public node(){
   }
}

