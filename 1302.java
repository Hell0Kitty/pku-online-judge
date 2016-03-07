import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		while(run()==true)
			;
	}

	static boolean run(){
		String marker = cin.next();
		if(marker.compareTo("ENDOFINPUT")==0)
			return false;

		int n = cin.nextInt();
		Sequence seq = new Sequence(cin.next());
		System.out.println(seq.mutatedSequence());
		cin.next();
		return true;
	}

	

}

class Sequence{
	char[] content;

	public Sequence(String s){
		content = s.toCharArray();
	}
	public Sequence(char[] content){
		this.content = content;
	}

	private int mutate(int start){
		int count;

		if(start>=content.length)
			return 0;

		char c = content[start];
		if(isLetter(c)){
			count = mutate(start+1);
			content[start] = (char)(count%10+'0');
			count++;
			return count;
		}
		else if(c == '0')
			return 0;
		else if(isNumber(c)){
			content[start] = (char)(c-1);
			if((start+c-'0')<content.length)
				count = mutate(start+c-'0');
			else
				count = mutate(start+1);
			count++;
			return count;
		}
			
		return -1;
	}

	private boolean isLetter(char c){
		if((c<='Z')&&(c>='A'))
			return true;
		return false;
	}
	private boolean isNumber(char c){
		if((c<='9')&&(c>='0'))
			return true;
		return false;
	}


	String mutatedSequence(){
		mutate(0);
		return new String(content);
	}
}
