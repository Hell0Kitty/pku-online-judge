import java.util.*;
import java.io.*;
import java.text.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=scanner.nextInt();
		double r,t;
		for (int i=0;i<n ;i++ ){
			r=scanner.nextDouble();
			t=scanner.nextDouble();
			System.out.println("Scenario #"+(i+1)+":");
			DecimalFormat df=new DecimalFormat("0.000");
			System.out.println(df.format(r*(1.0-1.0/(1.0+Math.sin(Math.PI/t)))));
			System.out.println();
		}
	}
}