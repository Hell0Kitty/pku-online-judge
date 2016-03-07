import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=scanner.nextInt();
		double dx1,dx2,dy1,dy2;
		double x1,x2,y1,y2;
		double k,b;
		double d1,d2,d3,d4;
		for (int i=0;i<n ;i++ ){
			x1=scanner.nextDouble();
			y1=scanner.nextDouble();
			x2=scanner.nextDouble();
			y2=scanner.nextDouble();
			dx1=scanner.nextDouble();
			dy1=scanner.nextDouble();
			dx2=scanner.nextDouble();
			dy2=scanner.nextDouble();
			if (dx1>dx2){
				double tx=dx1;
				dx1=dx2;
				dx2=tx;
			}
			if (dy1>dy2){
				double ty=dy1;
				dy1=dy2;
				dy2=ty;
			}
			if ((x1<dx1&&x2<dx1)||(x1>dx2&&x2>dx2)){
				System.out.println("F");
			}
			else if ((y1<dy1&&y2<dy1)||(y1>dy2&&y2>dy2)){
				System.out.println("F");
			}
			else{
				if (x1==x2){
					System.out.println("T");
				}
				else{
					k=(y2-y1)/(x2-x1);
					b=y1-k*x1;
					d1=dy1-k*dx1-b;
					d2=dy2-k*dx2-b;
					d3=dy1-k*dx2-b;
					d4=dy2-k*dx1-b;
					if ((d1>0&&d2>0&&d3>0&&d4>0)||(d1<0&&d2<0&&d3<0&&d4<0)){
						System.out.println("F");
					}
					else{
						System.out.println("T");
					}
				}
			}
		}
	}
}