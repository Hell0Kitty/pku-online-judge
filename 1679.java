import java.io.*;
import java.util.*;
class Edge{
	int u,v,disten;
	void set(int u,int v,int disten){
		this.u = u;
		this.v = v;
		this.disten = disten;
	}
}
interface MST{
	int N = 100+2,BIG = 1000000000;
	int getMST(int op);
}
class UniqueMST implements MST{
	int n,m;
	Edge edge[] = new Edge[N];
	int Graph[][] = new int[N][N];
	
	UniqueMST(){
		for(int i=0;i<N;++i){
			edge[i] = new Edge();
		}
	}
	
	String Unique(){
		int ans = -1;
		ans = getMST(0);
		for(int i=0;i<n-1;++i){
			Graph[edge[i].u][edge[i].v] = Graph[edge[i].v][edge[i].u] = BIG;
			int cnt = getMST(1);
			if(ans==cnt) return "Not Unique!";
			Graph[edge[i].u][edge[i].v] = Graph[edge[i].v][edge[i].u] = edge[i].disten;
		}
		return String.valueOf(ans);
	}
	public int getMST(int op){
		int ans = 0;
		int meat[][] = new int[2][N];
		boolean s[] = new boolean[N];
		Arrays.fill(s, false);
		s[1] = true;meat[1][1] = 0;meat[0][1] = 1;
		for(int i=2;i<=n;++i){
			meat[0][i] = 1;				//meat[0][i]记录当前到i的前结点是谁。
			meat[1][i] = Graph[1][i];	//meat[1][i]记录到i的最小距离。
		}
		for(int i=0;i<n-1;++i){
			
			int k=-1,Min = 0;
			for(int j=1;j<=n;++j) if(!s[j]){
				if(k==-1 || (k!=-1 && meat[1][j]<Min)){
					k = j;
					Min = meat[1][j];
				}
			}
			if(op==0){
				edge[i].set(meat[0][k], k, Min);
			}
			ans+=Min;
			s[k] = true;
			for(int j=1;j<=n;++j) if(!s[j]){
				if(Graph[k][j]<meat[1][j]){
					meat[0][j] = k;
					meat[1][j] = Graph[k][j];
				}
			}
		}
		return ans;
	}
	void initGraph(){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j) Graph[i][j] = BIG;
		}
	}
	void addEdge(Edge e){
		Graph[e.v][e.u] = Graph[e.u][e.v] = e.disten;
	}
}
public class Main {
	
	public static void main(String[]args)throws Exception{
		UniqueMST uniqueMst = new UniqueMST();
		
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		
		int Case = GetNum(cin);
		Edge edge = new Edge();
		while(Case--!=0){
			uniqueMst.n = GetNum(cin);
			uniqueMst.m = GetNum(cin);
			uniqueMst.initGraph();
			for(int i=0;i<uniqueMst.m;++i){
				edge.set(GetNum(cin), GetNum(cin), GetNum(cin));
				uniqueMst.addEdge(edge);
			}
			System.out.println(uniqueMst.Unique());
		}
	}
	static int GetNum(StreamTokenizer cin)throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
}
