//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String s;
		int total;
		while (true){
			s=scanner.nextLine();
			if (s.equals("#")){
				break;
			}
			total=0;
			for (int i=0;i< s.length() ;i++ ){
				total=total+(i+1)*getValue(s.charAt(i));
			}
			System.out.println(total);
		}
	}

	public static int getValue(char c){
		if (c==' '){
			return 0;
		}
		else{
			return c-'A'+1;
		}
	}
}

