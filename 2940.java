//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {

	static final int N = 100000+100;
	static int n;
	static long num[] = new long[N];

	public static double Get_Num(StreamTokenizer cin) throws Exception{
		cin.nextToken();
		return cin.nval;
	}

public static void main(String []args) throws Exception{

 int i;
 StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

 while(true){
	n = (int) Get_Num(cin);
	if(n==0) break;
	for(i=1;i<=n;++i)
		num[i] = (long) Get_Num(cin);
	System.out.println(solve());
  }
}

public static long solve(){
		int i;
		long cnt=0,ans=0;
		for(i=1;i<=n;++i){
			cnt +=num[i];
			ans+=abs(cnt);
		}
		return ans;
	}
	public static long abs(long cnt){
		if(cnt< 0) return -cnt;
		return cnt;
	}
}

