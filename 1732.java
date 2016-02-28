import java.io.*;
import java.util.*;
class word{
	String str,num;
	public void change(){
		
	}
}
public class Main {
	static final int N = 100+10,M = 50000+10;
	static Map mymap = new HashMap();
	static int DP[] = new int[N],pre[] = new int[N],n,m;
	static String str[] = new String[M],num,temp,Ans[] = new String[N];
	
	public static void main(String[]args)throws Exception{
		int i;
		Scanner cin = new Scanner(System.in);
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		
		while(cin.hasNext()){
			num = cin.next();
			n = cin.nextInt();
			m = num.length();
			mymap.clear();
			for(i=0;i<n;++i){
				str[i] = cin.next();
				temp = change(str[i]);
				mymap.put(temp, i);
			}
			solve();
		}
	}
	static void solve(){
		int i,j,k;
		String tmp;
		for(i=0;i<=m;++i){
			DP[i] = -1;
			pre[i] = -1;
		}
		DP[0] = 0;
		for(i=1;i<=m;++i){
			for(j=0;j<i;++j){
				tmp = num.substring(j, i);
				if(mymap.containsKey(tmp)){
					k = (Integer)mymap.get(tmp);
					if(DP[j]>-1 && (DP[i]==-1 || DP[i]>DP[j]+1)){
						DP[i] = DP[j]+1;
						pre[i] = k;
					}
				}
			}
		}
		if(DP[m]==-1) System.out.println("No solution.");
		else{
			k = 0; j = m;
			while(j>0){
				Ans[k++] = str[pre[j]];
				j -=str[pre[j]].length();
			}
			for(i=k-1;i>=0;--i){
				if(i!=k-1) System.out.print(" ");
				System.out.print(Ans[i]);
			}
		}
	}
	static String change(String world){
		String ans="";
		int i,len = world.length();
		for(i=0;i<len;++i){
			ans+=change(world.charAt(i));
		}
		return ans;
	}
	static char change(char c){
		if(c=='i' || c=='j') return '1';
		if(c>='a' && c<='c') return '2';
		if(c>='d' && c<='f') return '3';
		if(c>='g' && c<='h') return '4';
		if(c=='k' || c=='l') return '5';
		if(c=='m' || c=='n') return '6';
		if(c=='p' || c=='r' || c=='s') return '7';
		if(c=='t' || c=='u' || c=='v') return '8';
		if(c=='w' || c=='x' || c=='y') return '9';
		if(c=='o' || c=='q' || c=='z') return '0';
		return '0';
	}
}
