import java.util.Scanner;
import java.util.Arrays;
public class Main{
   private int a,b;
   private double f1,f2,f3,f4,f5,f6,t1,t2,t3,t4,t5,t6;

   public Main(int a,int b){
    this.a=a;
    this.b=b;
    f1=13-a+1;f2=13-b+1;f3=1;
    t1=13;t2=13;t3=a+b;
    f4=1;f5=1;f6=26-(a+b)+1;
    t4=a;t5=b;t6=26;
   }



 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  while(sc.hasNext()){
    int a=sc.nextInt();
    int b=sc.nextInt();
    if(a< 0) break;

    Main m=new Main(a,b);
    System.out.printf("%d-%d split: %10.8f\n",a,b,m.doIt());
  }
 }

 private int check()
  {
    if(f1<=t1||f2<=t2||f3<=t3||f4<=t4||f5<=t5||f6<=t6)return 1;
    return 0;
  }

 public double doIt(){
        double x=1;
        while(check()!=0)
        {
            if(f1<=t1){x*=f1;f1++;}
            if(f2<=t2){x*=f2;f2++;}
            if(f3<=t3){x*=f3;f3++;}
            if(f4<=t4){x/=f4;f4++;}
            if(f5<=t5){x/=f5;f5++;}
            if(f6<=t6){x/=f6;f6++;}
        }
        if(a!=b)x*=2;
       return x;
    }
}

