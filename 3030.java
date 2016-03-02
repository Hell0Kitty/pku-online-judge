//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n=scanner.nextInt();
		int r,e,c;
		for (int i=0;i< n ;i++ ){
			r=scanner.nextInt();
			e=scanner.nextInt();
			c=scanner.nextInt();
			if (r< e-c){
				System.out.println("advertise");
			}
			else if (r==e-c){
				System.out.println("does not matter");
			}
			else{
				System.out.println("do not advertise");
			}
		}
	}
}

