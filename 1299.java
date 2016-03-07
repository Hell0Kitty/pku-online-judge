import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String s1;
		int r,g,w;
		while (true){
			s1=scanner.next();
			if (s1.equals("ENDOFINPUT")){
				break;
			}
			r=scanner.nextInt();
			g=scanner.nextInt();
			w=scanner.nextInt()%360;
			if (w>180){
				w=360-w;
			}
			int m1=g*5;
			int m2=(int)Math.ceil(Math.PI*4*r*w/360);
			if (m1<m2){
				System.out.println("NO "+m1);
			}
			else{
				System.out.println("YES "+(m1-m2)/5);
			}
			scanner.next();
		}
	}
}