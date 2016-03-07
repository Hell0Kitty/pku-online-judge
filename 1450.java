import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	
	public static void main(String[]args) throws Exception{
		int t,n,m,cs=1;
		double ans;
		Scanner cin = new Scanner(System.in);
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		
		t = cin.nextInt();
		while(t--!=0){
			n = cin.nextInt();
			m = cin.nextInt();
			System.out.println("Scenario #"+cs+":");
			++cs;
			if(n%2==0 || m%2==0){
				System.out.printf("%.2f\n\n", (double)n*m);
			}
			else{
				System.out.printf("%.2f\n\n",(double) ((double)n*m-1+Math.sqrt(2.0)));
			}
		}
	}
}
