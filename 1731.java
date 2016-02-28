import java.util.*;

public class Main {
	static Scanner in = new Scanner(System.in);
	static boolean nextPermutation(char[] s) {
		int i;
		for(i=s.length-1; i>0; --i)
			if(s[i-1]<s[i]) break;
		if(i==0) return false;
		--i;
		int k=i+1;
		for(int j=i+2; j<s.length; ++j)
			if(s[i]<s[j]) k = j;
		{
			char x=s[i];
			s[i] = s[k];
			s[k] = x;
		}
		for(int j=i+1; j<=(s.length+i)/2; ++j) {
			char x=s[j];
			k=s.length+i-j;
			s[j] = s[k];
			s[k] = x;
		}
		return true;
	}
	public static void main(String[] args) {
		char[] s = in.next().toCharArray();
		Arrays.sort(s);
		do {
			System.out.println(s);
		} while(nextPermutation(s));
	}
}
