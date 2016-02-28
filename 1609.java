import java.io.*;
import java.util.*;
public class Main {
	static final int N = 100+10;
	static int point[][] = new int[N][N],DP[][] = new int[N][N];
	static void init(){
		for(int i=0;i<N;++i) for(int j=0;j<N;++j) point[i][j] = 0;
	}
	static int solve(){
		int i,j;
		for(i=0;i<N;++i) DP[0][i] = DP[i][0] = 0;
		for(i=1;i<N;++i) for(j=1;j<N;++j){
			DP[i][j] = Max(DP[i-1][j],DP[i][j-1])+point[i][j];
		}
		return DP[N-1][N-1];
	}
	static int Max(int a,int b){
		return a>b?a:b;
	}
	public static void main(String[]args) throws Exception{
		int i,a,b,n;
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		while(true){
			cin.nextToken();
			n = (int) cin.nval;
			if(n==0){
				System.out.println("*");
				break;
			}else{
				init();
				for(i=0;i<n;++i){
					cin.nextToken();
					a = (int) cin.nval;
					cin.nextToken();
					b = (int) cin.nval;
					++point[a][b];
				}
				System.out.println(solve());
			}
		}
	}
}
