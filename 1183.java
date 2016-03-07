import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		long a=scanner.nextInt();
		long m=1;
		for (long i=a;i>=1 ;i-- ){
			if ((a*a+1)%i==0){
				m=i;
				break;
			}
		}
		System.out.println(2*a+m+(a*a+1)/m);
	}
}