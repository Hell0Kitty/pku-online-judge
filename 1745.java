import java.util.*;

public class Main {
	
	static int M = 100+10;
	static int N = 2;
	public static void main(String []args) throws Exception{
		
		int n,m,i,j,k,cnt;
		int DP[][] = new int[N][M];
		
		Scanner cin = new Scanner(System.in);
		
		n = cin.nextInt();
		m = cin.nextInt();
		
		for(i=0;i<m;++i) for(j=0;j<2;++j) DP[j][i] = 0;
		DP[0][0] = 1;
		cnt = 0;
		for(i=1;i<=n;++i){
			cnt = i%2;
			for(j=0;j<=m;++j) DP[cnt][j]=0;
			k = cin.nextInt();
			if(k<0){
				k = -k;
				k %=m;
				k = -k;
			}
			else k%=m;
			for(j=0;j<m;++j) if(DP[1-cnt][j]>0){
				DP[cnt][(j+k+m)%m] = DP[cnt][(j-k+m)%m] = 1;;
			}
		}
		
		if(DP[cnt][0]>0) System.out.println("Divisible");
		else System.out.println("Not divisible");
		
	}
}
