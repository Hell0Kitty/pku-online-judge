import java.io.*;
import java.util.*;
class Intervals{
	int left,right,ci;
}
public class Main {
	static final int N = 50000+10;
	static int DP[] = new int[N],n,left,right;
	static Intervals Inter[] = new Intervals[N];
	
	static void start(){
		for(int i=0;i<N;++i)
			Inter[i] = new Intervals();
	}
	static int Get_Num(StreamTokenizer cin) throws Exception{
		if(cin.nextToken()==StreamTokenizer.TT_EOF)
			return -1;
		return (int) cin.nval;
	}
	static int solve(){
		int i,j;
		boolean flag=true;
		for(i=left;i<=right;++i)
			DP[i] = -N;
		DP[left] = 0;
		for(i=left;i<=right && flag;++i){
			flag = false;
			for(j=0;j<n;++j)if(DP[Inter[j].left]>-N && DP[Inter[j].left]+Inter[j].ci>DP[Inter[j].right]){
				DP[Inter[j].right]= DP[Inter[j].left]+Inter[j].ci ;
				flag = true;
			}
			for(j=left;j<right;++j) if(DP[j]>-N && DP[j]>DP[j+1]){
				DP[j+1] = DP[j];
				flag = true;
			}
			for(j=right;j>left;--j) if(DP[j]>-N && DP[j]-1>DP[j-1]){
				DP[j-1] = DP[j]-1;
				flag = true;
			}
		}
		return DP[right];
	}
	public static void main(String[]args) throws Exception{
		int i,j;
		start();
		StreamTokenizer cin =new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin =new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		
		while((n = Get_Num(cin))>0){
			left = N ; right = 0;
			for(i=0;i<n;++i){
				Inter[i].left = Get_Num(cin);
				Inter[i].right = Get_Num(cin)+1;
				Inter[i].ci = Get_Num(cin);
				left = Min(left,Inter[i].left);
				right = Max(right,Inter[i].right);
			}
			System.out.println(solve());
		}
		
	}
	static int Max(int a,int b){
		return a>b?a:b;
	}
	static int Min(int a,int b){
		return a<b?a:b;
	}
}
