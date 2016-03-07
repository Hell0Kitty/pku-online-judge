import java.io.*;
import java.util.*;
public class Main {
	
	static int get_base(char c){
		if(c>='0'&&c<='9')
			return c-'0'+0;
		if(c>='A' && c<='Z')
			return c-'A'+ 10;
		if(c>='a' && c<='z')
			return c-'a' + 36;
		return -1;
	}
	
	public static void main(String[]args) throws Exception{
		
		int ans,i;
		String str;
		Scanner cin = new Scanner(System.in);
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		while(cin.hasNext()){
			str = cin.next();
			for(ans=2;ans<=62;++ans){
				if(can(str,ans))
					break;
			}
			if(ans>62) System.out.println("such number is impossible!");
			else System.out.println(ans);
		}
	}
	static boolean can(String str,int cnt){
		int i,sum=0;
		for(i=0;i<str.length();++i){
			if(get_base(str.charAt(i))>=cnt) return false;
			sum*=cnt;
			sum+=get_base(str.charAt(i));
			sum%=(cnt-1);
		}
		if(sum==0) return true;
		return false;
	}
	static int Max(int a,int b){
		return a>b?a:b;
	}
}
