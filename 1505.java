import java.io.*;
import java.util.*;

public class Main {
	static final int N = 500+10;
	static int n,m;
	static boolean flag[] = new boolean[N];
	static long sum[] = new long[N],num[] = new long[N];
	public static void main(String[]args) throws Exception{
		int t,i;
		long best;
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		t = (int)Get_Num(cin);
		while(t--!=0){
			n = (int) Get_Num(cin);
			m = (int) Get_Num(cin);
			for(i=0;i<n;++i){
				num[i] = (long) Get_Num(cin);
				if(i==0) sum[i] = num[i];
				else sum[i] = num[i]+sum[i-1];
			}
			best = binary_search();
			make_ans(best);
		}
	}
	static void make_ans(long best){
		int i,j,k=0,last=n-1;
		Arrays.fill(flag, false);
		for(i=n-1;i>0;--i){
			if(sum[last]-sum[i-1]>best){
				flag[i] = true;
				last = i;
				++k;
			}
		}
		for(i=0;i<n && k<m-1;++i){
			if(flag[i]==false){
				flag[i] = true;
				++k;
			}
		}
		
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		for(i=0;i<n;++i){
			if(i!=0) out.print(" ");
			out.print(num[i]);
			if(flag[i])
				out.print(" /");
		}
		out.println();
		out.flush();
		
	}
	static long binary_search(){
		long Min = num[0],Max = sum[n-1],Mid;
		while(Min+1<Max){
			Mid = (Min+Max)/2;
			if(can(Mid)) Max = Mid;
			else Min = Mid;
		}
		if(can(Min)) return Min;
		return Max;
	}
	static boolean can(long cnt){
		int i,must=0;
		long temp=0;
		for(i=0;i<n;++i){
			if(num[i]>cnt) return false;
			if(temp+num[i]>cnt){
				++must;
				temp = num[i];
			}
			else temp+=num[i];
		}
		if(temp>0) must++;
		if(must<=m) return true;
		return false;
	}
	static double Get_Num(StreamTokenizer cin)throws Exception{
		cin.nextToken();
		return cin.nval;
	}
}
