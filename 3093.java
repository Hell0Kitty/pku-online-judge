//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
public class Main {

	static final int N = 30+5;
	static final int M = 1000+10;
	static int n,m;
	static int DP[] = new int[M],value[] = new int[N];

	public static void main(String []args) throws Exception{

		int t,cs=1,i,j;
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		Scanner cin = new Scanner(System.in);

		t = cin.nextInt();
		while(t--!=0){
			n = cin.nextInt();
			m = cin.nextInt();
			for(i=0;i< n;++i) {
				value[i] = cin.nextInt();
			}
			Arrays.sort(value,0,n);

			System.out.println(cs+" "+solve());
			cs++;
		}
	}
	public static int solve(){
		int i,j,t,sum=0;

		for(t=0;t< n;++t){
			init(t);
			for(i=t+1;i< n;++i){
				for(j=m;j>=value[i];--j){
					DP[j] += DP[j-value[i]];
				}
			}
			for(i=m;i>m-value[t] && i>0;--i)
				sum+=DP[i];
		}
		return sum;
	}
	public static void init(int t){
		int i,j=0;
		for(i=0;i<=m;++i) DP[i] = 0;
		for(i=0;i< t;++i)
			j+=value[i];
		if(j<=m)
			DP[j] = 1;
	}
}

