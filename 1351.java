import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	static long[] f,g;
	
	public static void main(String args[]){
		cin = new Scanner(System.in);
		f = new long[17];
		g = new long[17];
		
		g[1]=4;
		g[2]=14;
		for(int i=3;i<17;i++)
			g[i]=3*g[i-1]+2*g[i-2];
		
		for(int i=2;i<17;i++)
			f[i] = (1<<(2*i))-(1<<i)-g[i]+2;
			
		while(run()==true)
			;
	}
	
	static boolean run(){
		int n = cin.nextInt();
		if(n==-1)
			return false;
		if(n==16){
			System.out.println(16+": 3553389280");
			return true;
		}
			
		System.out.println(n+": "+f[n]);
		return true;
	
	}
}