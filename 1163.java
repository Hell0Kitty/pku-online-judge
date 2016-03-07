//Pku 1163 the Triangle by suqiang@neuq&jlu 
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

	
	public static void main(String[] args) throws Exception{
	
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(in.readLine());
		//number表示从叶子节点到当前节点的最大值
		int [][]number = new int[num][num];
		//输入并初始化
		for(int i=0;i<num;i++){
			String str = in.readLine();
			StringTokenizer strToke = new StringTokenizer(str);
			for(int j=0;j<=i;j++){
				number[i][j] = Integer.parseInt(strToke.nextToken());
			}
		}
		//状态转移方程,该句是整个动态规划的核心
		for(int i=num-2;i>=0;i--){
			for(int j=0;j<=i;j++){
				number[i][j] = Math.max(number[i+1][j], number[i+1][j+1])+number[i][j];
			}
		}
		
		System.out.println(number[0][0]);
	}

}