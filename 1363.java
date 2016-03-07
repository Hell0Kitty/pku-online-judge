import java.io.*;
import java.util.*;

public class Main {
	static final int N = 1000+10;
	static int n ;
	static int in[] = new int[N],out[] = new int[N],stack[] = new int[N];
	static boolean can(){
		int i=0,cnt=0,top=0;
		while(true){
			if(top>0 && stack[top-1]==out[cnt]){
				++cnt;
				--top;
				if(cnt>=n) break;
			}
			else{
				if(i>=n) return false;
				stack[top++] = in[i++];
			}
		}
		return true;
	}
	public static void main(String[]args) throws Exception{
		int i=0,j=0;
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		while(true){
			n = Get_Num(cin);
			if(n==0) break;
			while(true){
				out[0] = Get_Num(cin);
				if(out[0]==0) break;
				for(i=1;i<n;++i) out[i] = Get_Num(cin);
				for(i=0;i<n;++i) in[i] = i+1;
				if(can()) System.out.println("Yes");
				else System.out.println("No");
			}
			System.out.println();
		}
	}
	static int Get_Num(StreamTokenizer cin) throws Exception{
		cin.nextToken();
		return (int)cin.nval;
	}
}
