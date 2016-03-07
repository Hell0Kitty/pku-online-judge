import java.io.*;
import java.util.*;
public class Main {
	static final int N = 1000+10;
	static int top,ans;
	static String opt = new String();
	static String str[] =new String[N];
	static int score[]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
	
	public static void main(String[]args)throws Exception{
		
		top = ans = 0;
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		
		opt = next_string(cin);
		
		while(true){
			str[top] = next_string(cin);
			if(str[top].equals(".")) break;
			if(can_save(opt,str[top])) {
				
				ans = Max(ans,get_score(str[top]));
				++top;
			}
		}
		for(int i=0;i<top;++i){
			for(int j=i+1;j<top;++j){
				str[top+1] = add(str[i],str[j]);
				if(can_save(opt,str[top+1])){
					ans = Max(ans,get_score(str[top+1]));
				}
			}
		}
		System.out.println(ans);
		
	}
	static String add(String obj1,String obj2){
		char temp[] = new char[20];
		String cnt = obj1+obj2;
		temp = cnt.toCharArray();
		Arrays.sort(temp,0,cnt.length());
		
		return String.valueOf(temp);
		
	}
	static int get_score(String op1){
		int i,cnt=0,n=op1.length();
		for(i=0;i<n;++i){
			cnt+=score[(int)(op1.charAt(i)-'a')];
		}
		return cnt;
	}
	static int Max(int a,int b){
		return a>b?a:b;
	}
	static boolean can_save(String op1,String op2){
		
		int i=0,j=0,n =op1.length(),m=op2.length();
		while(i<n && j<m){
			if(op1.charAt(i)==op2.charAt(j)){
				++i;++j;
			}else{
				++i;
			}
		}
		if(j<m) return false;
		
		return true;
	}
	static String next_string(StreamTokenizer cin) throws Exception{
		char temp[] = new char[10];
		String cnt = new String();
		cin.nextToken();
		cnt = cin.sval;
		if(cnt==null) return ".";
		temp = cnt.toCharArray();
		Arrays.sort(temp,0,cnt.length());

		return String.valueOf(temp);
		

	}
}
