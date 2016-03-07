import java.io.*;
import java.util.*;
class Coin{
	int price,weight;
}
public class Main {
	static final int N = 500+10,M = 10000+10;
	static int DP[] = new int[M],n,m;
	static Coin coin[] =new Coin[N];
	static void start(){
		for(int i=0;i<N;++i){
			coin[i] =new Coin();
		}
	}
	public static void main(String[]args) throws Exception{
		int t,i,j;
		start();
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		t = Get_Num(cin);
		while(t--!=0){
			i = Get_Num(cin);
			j = Get_Num(cin);
			m = j-i;
			n = Get_Num(cin);
			for(i=0;i<n;++i){
				coin[i].price = Get_Num(cin);
				coin[i].weight = Get_Num(cin);
			}
			solve();
			if(DP[m]==-1) System.out.println("This is impossible.");
			else System.out.println("The minimum amount of money in the piggy-bank is "+DP[m]+".");
		}
	}
	static int Get_Num(StreamTokenizer cin)throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
	static void solve(){
		int i,j;
		for(i=0;i<=m;++i) DP[i] = -1;
		DP[0] = 0;
		for(i=0;i<n;++i){
			for(j=0;j<=m;++j) if(DP[j]>-1 && j+coin[i].weight<=m){
				DP[j+coin[i].weight] = Min(DP[j+coin[i].weight],DP[j]+coin[i].price);
			}
		}
	}
	static int Min(int a,int b){
		if(a==-1) return b;
		return a<b?a:b;
	}
}
