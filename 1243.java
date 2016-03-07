import java.util.*;

public class Main{
	static Scanner cin;
	static int Case = 0;
	static int[][] result;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		
		result = new int[100][100];
		int i,j;
		for(i = 0;i < 100;i++)
			for(j = 0;j < 100;j++)
				if(i == 1)
					result[i][j] = 1;
				else if(j == 0)
					result[i][j] = i;
				else
					result[i][j] = 0;
		
		
		while(true){
			if(!work(cin.nextInt(),cin.nextInt()))
				break;
		}
		
		return;
	}
	
	static boolean work(int m,int n){
		if((m == 0)&&(n == 0))
			return false;
		
		Case++;
		System.out.println("Case "+Case+": "+compute(m,n));
		return true;
	}
	
	static int compute(int m,int n){
		if(result[m][n] != 0)
			return result[m][n];
		
		result[m][n] = compute(m-1,n-1)+compute(m-1,n)+1;
		return result[m][n];
		
	}
}