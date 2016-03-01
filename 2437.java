import java.io.*;
import java.util.*;
class POOL implements Comparable{
	int left,right;
	public int compareTo(Object oo){
		POOL temp = (POOL) oo;
		if(temp.left< this.left) return 1;
		return -1;
	}
}

 public class Main {
  static final int N = 10000+100;
  static int n,L;
  static POOL pool[] = new POOL[N];
  static void start(){
	for(int i=0;i< N;++i) pool[i] = new POOL();
  }

  public static void main(String[]args) throws Exception{
   int i;
   start();
   StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

   n = Get_Num(cin);
   L = Get_Num(cin);
   for(i=0;i< n;++i){
	pool[i].left = Get_Num(cin);
	pool[i].right = Get_Num(cin);
   }
   Arrays.sort(pool,0,n);
   System.out.println(solve());

  }

  static int solve(){
   int ans=0,cnt=0,i=0,j;
   while(i< n){
	if(pool[i].right>cnt-1){
		j = (Min(pool[i].right-pool[i].left,pool[i].right-cnt)+L-1)/L;
		cnt = Max(pool[i].left,cnt)+j*L;
		ans+=j;
	}
	++i;
   }
   return ans;
  }

  static int Max(int a,int b){
    return a>b?a:b;
  }

  static int Min(int a,int b){
		return a< b?a:b;
	}
	static int Get_Num(StreamTokenizer cin) throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}

}

