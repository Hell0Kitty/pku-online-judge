import java.text.DecimalFormat;
import java.util.Scanner;

public class Main{

public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   DecimalFormat df1 = new DecimalFormat("0.0000"); 
   int n = cin.nextInt();
   while(n-- > 0) {
    int x1 = cin.nextInt();
    int y1 = cin.nextInt();
    double t1 = cin.nextInt();
    int x2 = cin.nextInt();
    int y2 = cin.nextInt();
    double t2 = cin.nextInt();
    double x, y;
    t1=t1 / 360 * 2 * Math.PI;
    t2=t2 / 360 * 2 * Math.PI;
      y = (Math.cos(t2)*(Math.sin(t1)*y1-Math.cos(t1)*x1)-Math.cos(t1)*(Math.sin(t2)*y2-Math.cos(t2)*x2))/(Math.sin(t1-t2));
    x = (Math.sin(t2)*(Math.sin(t1)*y1-Math.cos(t1)*x1)-Math.sin(t1)*(Math.sin(t2)*y2-Math.cos(t2)*x2))/(Math.sin(t1-t2));
    System.out.println(df1.format(x)+" "+ df1.format(y));
   }
  
}

}
