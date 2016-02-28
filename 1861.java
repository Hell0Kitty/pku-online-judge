import java.io.*;
import java.util.*;
class Edge implements Comparable{
	int u,v,disten;
	Edge(){};
	void set(int u,int v,int disten){
		this.u = u;
		this.v = v;
		this.disten = disten;
	}
	public int compareTo(Object obj){
		Edge temp = (Edge)obj;
		if(this.disten>temp.disten) return 1;
		return -1;
	}
}
class Set{
	int father[],num[];
	void init(int n){
		num = new int[n+10];
		father = new int[n+10];
		Arrays.fill(num, 1);
		Arrays.fill(father, -1);
	}
	int Ufind(int who){
		int temp,cnt = who;
		while(father[who]!=-1){
			who = father[who];
		}
		while(cnt!=who){
			temp = father[cnt];
			father[cnt] = who;
			cnt = temp;
		}
		return who;
	}
	void Uset(int u,int v){
		if(u==v) return ;
		if(num[u]>num[v]){
			father[v] = u;
			num[u]+=num[v];
		}else{
			father[u] = v;
			num[v]+=num[u];
		}
	}
}
class Kruscal{
	final int N = 15000+100;
	int n,m,cnt,max,ans;
	Edge edge[] = new Edge[N];
	Kruscal(){
		for(int i=0;i<N;++i) edge[i] = new Edge();
	}
	void init(int n,int m){
		cnt = 0;
		this.n = n;
		this.m = m;
		max = ans = 0;
	}
	void addEdge(int u,int v,int disten){
		edge[cnt++].set(u, v, disten);
	}
	void calc(PrintWriter out){
		Set set = new Set();
		set.init(n);
		Arrays.sort(edge,0,m);
		for(int i=0;i<m;++i){
			if(set.Ufind(edge[i].u) == set.Ufind(edge[i].v)){
				edge[i].disten = -1;
			}else{
				max = Max(max,edge[i].disten);
				++ans;
				set.Uset(set.Ufind(edge[i].u), set.Ufind(edge[i].v));
			}
		}
		
		out.println(max);
		out.println(ans);
		for(int i=0;i<m;++i)if(edge[i].disten>=0){
			out.println(edge[i].u+" "+edge[i].v);
		}
	}
	int Max(int a,int b){
		return a>b?a:b;
	}
}
public class Main {
	public static void main(String[]args)throws Exception{
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		Kruscal kruscal = new Kruscal();
		int n,m,u,v,disten;
		n = GetNum(cin);
		m = GetNum(cin);
		kruscal.init(n, m);
		for(int i=0;i<m;++i){
			u = GetNum(cin);
			v = GetNum(cin);
			disten = GetNum(cin);
			if(u>v) kruscal.addEdge(v, u, disten);
			else kruscal.addEdge(u, v, disten);
		}
		kruscal.calc(out);
		out.flush();
	}
	static int GetNum(StreamTokenizer cin)throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
}
