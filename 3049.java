//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {

	static final int N = 20;
	static int n,l;
	static String ans;
	static char word[] = new char[N];
	static char ansp[] = new char[N];

	public static void main(String []args)throws Exception{

		int i;
		String str;
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		Scanner cin = new Scanner(System.in);
		l = cin.nextInt();
		n = cin.nextInt();
		for(i=0;i< n;++i){
			str = cin.next();
			word[i] = str.charAt(0);
		}
		Arrays.sort(word,0,n);
		dfs(0,0,false);
	}

public static void dfs(int start,int dept,boolean have){
	int i;
	if(dept>=l){
		if(!have) return ;
		for(i=0;i< dept;++i)
			System.out.print(ansp[i]);
		System.out.println("");
		return ;
	}
	for(i=start;i< n;++i){
	  ansp[dept] = word[i];
         if(word[i]=='a' || word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u'){
		dfs(i+1,dept+1,have|true);
	   }
		else dfs(i+1,dept+1,have);
	}
 }
}

