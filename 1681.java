import java.util.*;

public class Main {

	static Scanner in = new Scanner(System.in);
	static char[][] board;//用于保存初始状态
	static boolean[][] map;//墙壁的状态
	static int cnt;//涂块的次数
	
	static void click(int x, int y) {//涂（x,y)处的格子
		++cnt;
		map[x][y] = !map[x][y];
		if(x-1>=0) map[x-1][y] = !map[x-1][y];//上面的格子
		if(y-1>=0) map[x][y-1] = !map[x][y-1];//左边的格子
		if(x+1< map.length) map[x+1][y] = !map[x+1][y];//下面的格子
		if(y+1< map[x].length) map[x][y+1] = !map[x][y+1];//右边的格子
	}
	
	static int check(int s) {
		cnt = 0;
		for(int i=0; i!=map.length; ++i)//初始状态
			for(int j=0; j!=map[i].length; ++j)
				map[i][j] = board[i][j]=='w';

		for(int i=0; i!=map[0].length; ++i)//确定第一行的具体情况
			if((s&(1<< i))!=0)
				click(0, i);
				
		for(int i=1; i!=map.length; ++i)//涂第二行至最后一行
			for(int j=0;j!=map[i].length; ++j)
				if(map[i-1][j]) click(i, j);
				
		for(int j=0; j!=map[map.length-1].length; ++j)//检查最后一行是否全是黄色
			if(map[map.length-1][j]) return Integer.MAX_VALUE;
		return cnt;
	}
	
	
	public static void main(String[] args) {
		int t = in.nextInt();//测试次数
		while(t-->0) {
			int n = in.nextInt();//格子的规模
			board = new char[n][];
			for(int i=0; i!=n; ++i) {
				board[i] = in.next().toCharArray();
			}
			map = new boolean[n][n];
			int ans = Integer.MAX_VALUE;
			for(int i=0; i!=(1 << n); ++i) {//第一行有2^n种变化，对每一种变化尝试
				ans = Math.min(ans, check(i));
			}
			if(ans< Integer.MAX_VALUE) System.out.println(ans);
			else System.out.println("inf");
		}
	}

}
