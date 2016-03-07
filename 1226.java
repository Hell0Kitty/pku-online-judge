import java.math.*;
import java.io.*;
import java.util.*;

class Main {
	public static void main(String[] args) throws Exception {
		new Main().run();
	}

	private int n;	

	private void run() throws Exception {
		Scanner cin = new Scanner(System.in);
		//Scanner cin = new Scanner(new FileInputStream("t.in"));
		int ntc = cin.nextInt(),i,j,k;
		while(ntc-- != 0) {
			n = cin.nextInt();
			StringBuffer[] s = new StringBuffer[n];
			for(i = 0; i < n; ++i) {
				s[i] = new StringBuffer(cin.next());
			}
			int max = 0;
			for(i = 0; i < s[0].length(); ++i) {
				for(j = i+1; j <= s[0].length(); ++j) {
					if(check(s,i,j)) {
						max = Math.max(max,j-i);
					}
				}
			}
			System.out.println(max);

		}
	}
	boolean check(StringBuffer s[], int x, int y) {
		int i;
		String pattern1 = s[0].toString().substring(x, y);
		String pattern2 = "";
		for(i = pattern1.length()-1; i >= 0; --i) {
			pattern2 += pattern1.charAt(i);
		}
		for(i = 0; i < n; ++i) {
			if(s[i].toString().indexOf(pattern1) == -1
				&& s[i].toString().indexOf(pattern2) == -1) {
				return false;
			}
		}
		return true;
	}
}
