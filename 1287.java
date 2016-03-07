import java.io.*;
import java.util.*;
class Edge implements Comparable{
	int start,end;
	int cost;
	public int compareTo(Object temp){
		Edge cnt = (Edge) temp;
		if(cnt.cost<this.cost) return 1;
		return -1;
	}
}
class Set{
	final int N = 100;
	int father[] = new int[N],num[] = new int[N];
	void init(){
		for(int i=0;i<N;++i){
			father[i] = -1;
			num[i] = 0;
		}
	}
	int find(int who){
		int u,v = who;
		while(this.father[who]!=-1){
			who = this.father[who];
		}
		while(v!=who){
			u = this.father[v];
			this.father[v] = who;
			v = u;
		}
		return who;
	}
	void set(int a,int b){
		a = this.find(a);
		b = this.find(b);
		if(a==b)
			return ;
		if(this.num[a]>this.num[b]){
			this.father[b] = a;
			this.num[a]+=this.num[b];
		}else{
			this.father[a] = b;
			this.num[b]+=this.num[a];
		}
	}
}
public class Main {
	static final int N = 100000;
	static int n,m;
	static Set set = new Set();
	static Edge edge[] = new Edge[N];
	static void start(){
		for(int i=0;i<N;++i)
			edge[i] = new Edge();
	}
	static int solve(){
		int ans=0;
		int i;
		Arrays.sort(edge,0,m);
		for(i=0;i<m;++i){
			if(set.find(edge[i].start)!=set.find(edge[i].end))
				ans+=edge[i].cost;
			set.set(edge[i].start, edge[i].end);
		}
		return ans;
	}
	public static void main(String[]args) throws Exception{
		int i,j;
		start();
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		while(true){
			n = Get_Num(cin);
			if(n==0) break;
			m = Get_Num(cin);
			set.init();
			for(i=0;i<m;++i){
				edge[i].start = Get_Num(cin);
				edge[i].end = Get_Num(cin);
				edge[i].cost = Get_Num(cin);
			}
			System.out.println(solve());
		}
	}
	static int Get_Num(StreamTokenizer cin)throws Exception{
		cin.nextToken();
		return (int)cin.nval;
	}
}
