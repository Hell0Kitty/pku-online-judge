import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=scanner.nextInt();
		double[] x,y;
		double px,py;
		double k1,k2,b1,b2;
		System.out.println("INTERSECTING LINES OUTPUT");
		for (int i=0;i<n ;i++ ){
			x=new double[4];
			y=new double[4];
			for (int j=0;j<4 ;j++ ){
				x[j]=scanner.nextDouble();
				y[j]=scanner.nextDouble();
			}
			if ((x[1]-x[0])*(y[3]-y[2])==(x[3]-x[2])*(y[1]-y[0])){
				if ((x[3]-x[0])*(y[2]-y[1])==(x[2]-x[1])*(y[3]-y[0])){
					System.out.println("LINE");
				}
				else{
					System.out.println("NONE");
				}
			}
			else{
				if (x[0]==x[1]){
					px=x[0];
					k2=(y[3]-y[2])/(x[3]-x[2]);
					b2=y[3]-k2*x[3];
					py=k2*px+b2;
				}
				else if (x[2]==x[3]){
					px=x[2];
					k1=(y[1]-y[0])/(x[1]-x[0]);
					b1=y[1]-k1*x[1];
					py=k1*px+b1;
				}
				else{
					k1=(y[1]-y[0])/(x[1]-x[0]);
					b1=y[1]-k1*x[1];
					k2=(y[3]-y[2])/(x[3]-x[2]);
					b2=y[3]-k2*x[3];
					px=(b2-b1)/(k1-k2);
					py=k1*px+b1;
				}
				px=(Math.round(px*100.0))/100.0;
				py=(Math.round(py*100.0))/100.0;
				System.out.println("POINT "+getO(px)+" "+getO(py));
			}
		}
		System.out.println("END OF OUTPUT");
	}

	public static String getO(double d){
		String ds=""+d;
		while (true){
			int index=0;
			boolean flag=false;
			for (int j=0;j<ds.length() ;j++ ){
				if (flag){
					index++;
				}
				if (ds.charAt(j)=='.'){
					flag=true;
				}
			}
			if (index==2){
				break;
			}
			else if (index==1){
				ds=ds+"0";
			}
		}
		return ds;
	}
}