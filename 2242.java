//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    double[] x,y;
    double k1,k2,b1,b2,ox,oy;
    double r;
    while (scanner.hasNext()){
        x=new double[3];
        y=new double[3];
        for (int i=0;i< 3 ;i++ ){
            x[i]=scanner.nextDouble();
            y[i]=scanner.nextDouble();
        }
        if (y[0]==y[1]){
            double t=y[0];
            y[0]=y[2];
            y[2]=t;
            t=x[0];
            x[0]=x[2];
            x[2]=t;
        }
        if (y[0]==y[2]){
            double t=y[0];
            y[0]=y[1];
            y[1]=t;
            t=x[0];
            x[0]=x[1];
            x[1]=t;
        }
    k1=0-(x[0]-x[1])/(y[0]-y[1]);
    b1=(y[0]+y[1])/2-k1*(x[0]+x[1])/2;
    k2=0-(x[0]-x[2])/(y[0]-y[2]);
    b2=(y[0]+y[2])/2-k2*(x[0]+x[2])/2;
    ox=(b2-b1)/(k1-k2);
    oy=k1*ox+b1;
    r=Math.sqrt((ox-x[0])*(ox-x[0])+(oy-y[0])*(oy-y[0]));
    System.out.println(Math.round(2*3.141592653589793*r*100.0)/100.0);
    }
}
}


