import java.io.*;
import java.util.*;

public class Main {
	static final int N = 100000;
	static String str[] = new String[N];
	static int n;
	static void start(){
		for(int i=0;i<n;++i) str[i] = new String();
	}
	public static void main(String[]args) throws Exception{
		int i;
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		Scanner cin = new Scanner(System.in);
		while(true){
			n = cin.nextInt();
			if(n<=0) break;
			cin.nextLine();
			for(i=0;i<n;++i){
				str[i] = cin.nextLine();
				//System.out.println(str[i]);
			}
			System.out.println(solve());
		}
	}
	public static int solve(){
		int i,j,max_length=0,length=str[0].length(),ans=0,cnt;
		for(i=0;i<n;++i){
			ans = 0;
			for(j=0;j<length;++j){
				if(str[i].charAt(j)=='X')
					++ans;
			}
			max_length = ans>max_length?ans:max_length;
		}
		ans = 0;
		for(i=0;i<n;++i){
			cnt = 0;
			for(j=0;j<length;++j){
				if(str[i].charAt(j)=='X')
					++cnt;
			}
			ans+=max_length-cnt;
		}
		return ans;
	}
}
