import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		System.out.printf("Cards  Overhang\n");
		int n;
		double d;
		while (scanner.hasNext()){
			n=scanner.nextInt();
			d=0;
			for (int i=1;i<=n ;i++ ){
				d=d+1.0/(2*i);
			}
			System.out.printf("%5d  %8.3f\n",n,d);
		}
	}
}