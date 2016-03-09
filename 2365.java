import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int n=scanner.nextInt();
    double r=scanner.nextDouble();
    double[] x=new double[n];
    double[] y=new double[n];
    for (int i=0;i< n ;i++ ){
        x[i]=scanner.nextDouble();
        y[i]=scanner.nextDouble();
    }
    double l=2*r*Math.PI;
    for (int i=0;i < n ;i++ ){
          if (i!=n-1){
        l=l+Math.sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
      }
     else{
       l=l+Math.sqrt((x[i]-x[0])*(x[i]-x[0])+(y[i]-y[0])*(y[i]-y[0]));
        }
    }
    l=Math.round(l*100.0)/100.0;
    System.out.println(l);
   }
}


