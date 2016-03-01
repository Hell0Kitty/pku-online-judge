//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	int s,n,tn;
	while (true){
		s=scanner.nextInt();
		n=scanner.nextInt();
		if (s==0&&n==0){
			break;
		}
		tn=s+1;
		for (int i=0;i< n ;i++ ){
                   tn=tn+scanner.nextInt()-scanner.nextInt()-1;
		}
		System.out.println(tn);
	}
  }
}

