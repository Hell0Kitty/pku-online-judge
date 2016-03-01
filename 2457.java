//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
public class Main {
	static final int N = 10000+10;
	static int meat[] = new int[N],pre[] = new int[N],n,K;
	static Vector Graph[] = new Vector[N];
	static Queue que = new LinkedList();
	static void start(){
		for(int i=0;i< N;++i)
			Graph[i] = new Vector();
	}
	static void init(){
		que.clear();
		for(int i=0;i< N;++i){
			Graph[i].clear();
			meat[i] = N+N;
			pre[i] = -1;
		}
		meat[1] = 1;
		que.offer(1);
	}

 public static void main(String[]args) throws Exception{
  int i,u,v;
  start();
  init();
  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

  n = Get_Num(cin);
  K = Get_Num(cin);
  for(i=0;i< n;++i){
	v = Get_Num(cin);
	u = Get_Num(cin);
	Graph[v].add(u);
  }

  solve();
  if(meat[K]>=N) System.out.println(-1);
  else{
	System.out.println(meat[K]);
	make_ans();
  }
 }

  static void solve(){
   int i,j,k,temp;
   while(!que.isEmpty()){
	temp = (Integer) que.element();
	que.remove();
	k = Graph[temp].size();
	for(i=0;i< k;++i){
		j = (Integer) Graph[temp].elementAt(i);
		if(meat[j]>meat[temp]+1){
			meat[j] = meat[temp]+1;
			pre[j] = temp;
			que.add(j);
		}
	}
   }
 }

  static void make_ans(){
   int ans[] = new int[N],i,k=K,top=0;
   while(true){
	ans[top++] = k;
	k = pre[k];
	if(k< 0) break;
   }
   PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
   for(i=top-1;i>=0;--i)
	out.println(ans[i]);
   out.flush();
 }

  static int Get_Num(StreamTokenizer cin) throws Exception{
   cin.nextToken();
   return (int) cin.nval;
 }
}

