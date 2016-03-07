import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(in.hasNext()){
			String str1 = in.next();
			String str2 = in.next();
			int[][] DP = new int[str1.length()+1][str2.length()+1];
			int i;
			for(i=0;i<=str1.length();i++)
				DP[i][0] = 0;
			for(i=0;i<=str2.length();i++)
				DP[0][i] = 0;
			for(i=1;i<=str1.length();i++){
				for(int j=1;j<=str2.length();j++){
					if(str1.charAt(i-1) == str2.charAt(j-1))
						DP[i][j]=DP[i-1][j-1]+1;
					else
						DP[i][j]=Math.max(DP[i-1][j], DP[i][j-1]);
				}
			}
			System.out.println(DP[str1.length()][str2.length()]);
		}		
	}
}
