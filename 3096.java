//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	boolean flag;
	int index;
	String s;
	String[] pair;
	while (true){
		s=scanner.next();
		if (s.equals("*")){
			break;
		}
		if (s.length()==1){
			System.out.println(s+" is surprising.");
			continue;
		}
		index=0;
		flag=true;
		while (index< s.length()-1){
			pair=new String[s.length()-index-1];
			for (int i=0;i< pair.length ;i++ ){
				pair[i]=""+s.charAt(i)+s.charAt(i+index+1);
			}
			if (!check(pair)){
				flag=false;
				break;
			}
			index++;
		}
		if (flag){
			System.out.println(s+" is surprising.");
		}
		else{
			System.out.println(s+" is NOT surprising.");
		}
	}
  }

  public static boolean check(String[] s){
	for (int i=0;i< s.length-1 ;i++ ){
		for (int j=i+1;j< s.length ;j++ ){
			if (s[i].equals(s[j])){
				return false;
			}
		}
	}
	return true;
 }
}

