import java.io.*;
import java.util.*;
interface Pass{
	int N = 100+10;
	void SetInit(int n,int k);
	void AddData(int left,int right);
	void InitData();
	int GetAns();
}
class Interval implements Comparable{
	int left,right;
	void set(int left,int right){
		this.left = left;
		this.right = right;
	}
	public int compareTo(Object obj){
		Interval temp = (Interval)obj;
		if(this.right>temp.right) return 1;
		return -1;
	}
}
class Muraille implements Pass{
	
	int n,k,cnt;
	int Graph[] = new int[N];
	int select[] = new int[N];
	Interval wall[] = new Interval[N];
	Muraille(){
		for(int i=0;i<N;++i) wall[i] = new Interval();
	}
	public void SetInit(int n,int k){
		cnt = 0;
		this.n = n;
		this.k = k;
		Arrays.fill(Graph, 0);
	}
	public void AddData(int left,int right){
		wall[cnt].set(left, right);
		for(int i=left;i<=right;++i){
			++Graph[i];
		}
		++cnt;
	}
	public void InitData(){
		Arrays.sort(wall,0,n);
	}
	void delete(int who){
		for(int i=wall[who].left;i<=wall[who].right;++i){
			--Graph[i];
		}
		wall[who].right = -1;
	}
	void delete(int left,int num){
		for(int i=n-1;i>=0 && num>0;--i) if(wall[i].left<=left && wall[i].right!=-1){
			--num;
			delete(i);
		}
	}
	public int GetAns(){
		int ans=0;
		for(int i=0;i<N;++i){
			if(Graph[i]>k){
				ans+=Graph[i]-k;
				delete(i,Graph[i]-k);
			}
		}
		return ans;
	}
	
}
public class Main {
	public static void main(String[]args)throws Exception{
		int Test,n,k;
		Muraille muraille = new Muraille();
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		Test = GetNum(cin);
		while(Test--!=0){
			n = GetNum(cin);
			k = GetNum(cin);
			muraille.SetInit(n,k);
			for(int i=0;i<n;++i){
				int left = GetNum(cin);
				GetNum(cin);
				int right = GetNum(cin);
				GetNum(cin);
				if(left>right) muraille.AddData(right, left);
				else muraille.AddData(left, right);
			}
			
			muraille.InitData();
			System.out.println(muraille.GetAns());
		}
	}
	static int GetNum(StreamTokenizer cin)throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
}
