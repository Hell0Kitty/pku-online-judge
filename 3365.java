import java.util.Scanner;
import java.util.Arrays;
public class Main{
  static double pi=Math.PI;
  static double epx=1e-6;

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  double w,h,v1,v2,temp,r,d;
    while(sc.hasNext()){
     w=sc.nextDouble();
     h=sc.nextDouble();
     if(w==0&&h==0) break;
        if(h>w){temp=h;h=w;w=temp;}
        v1=h*h*(w-h/pi)/(4.0*pi);
        d=w/(pi+1);
        if(d>h+epx){/*判断d是否符合条件*/
           r=h/2.0;
          v2=pi*r*r*h;
        }
        else v2=pi*w*w*h/(4.0*(pi+1)*(pi+1));
        System.out.printf("%.3f\n",Math.max(v1,v2));
    }
   }

}

