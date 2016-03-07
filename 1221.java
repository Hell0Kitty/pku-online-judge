import java.io.*;
import java.util.*;

public class Main {
	static final int N = 500;
	static long DP[][] = new long[N][N];
	static void init(){
		int i,j;
		for(i=0;i<N;++i) for(j=0;j<N;++j) DP[i][j] = 0;
		for(i=1;i<N;++i){
			for(j=i;j>=0;--j)
				DP[i][j]=1;
		}
		for(i=0;i<N;++i) DP[0][i]=1;
		for(i=2;i<N;++i){
			for(j=i/2;j>=1;--j)
				DP[i][j] = DP[i-2*j][j]+DP[i][j+1];
		}
	}
	public static void main(String[]args) throws Exception{
		int n;
		init();
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			n = cin.nextInt();
			if(n==0) break;
			System.out.println(n+" "+solve(n));
		}
	}
	static long solve(int n){
		return DP[n][1];
	}
}
