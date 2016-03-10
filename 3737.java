import java.util.*;
public class Main{
 static final double pi=Math.PI;
public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    double s;
    while (sc.hasNext()) {
      s=sc.nextDouble();
      double h=Math.sqrt(2*s/pi);
      double r=Math.sqrt(s*s/(pi*pi*h*h+2*pi*s));
      double v=(1.0/3.0)*(s*s)*h/(pi*h*h+2*s);
      System.out.printf("%.2f\n%.2f\n%.2f\n",v,h,r);
    }
  }
}

