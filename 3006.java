//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	while (true){
		int a=scanner.nextInt();
		int d=scanner.nextInt();
		int n=scanner.nextInt();
		if (a+d+n==0){
			break;
		}
		int index=0;
		int i=0;
		while (index< n){
			if (isZh(a+d*i)){
				index++;
			}
			i++;
		}
		System.out.println(a+d*(i-1));
	}
  }

	public static boolean isZh(int p){
		if (p==1){
			return false;
		}
		if (p==2){
			return true;
		}
		if (p%2==0){
			return false;
		}
		for (int i=3;i*i<=p ;i=i+2 ){
			if (p%i==0){
				return false;
			}
		}
		return true;
	}
}


