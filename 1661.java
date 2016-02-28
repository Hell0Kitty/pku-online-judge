import java.util.Arrays;
import java.util.Scanner;

/**
 * POJ1661
 * @author Bruce
 *
 */

class Board implements Comparable<Board>{
	int lx;
	int rx;
	int h;
	public Board(int x,int y,int h){
		this.lx = x;
		this.rx = y;
		this.h = h;
	}
	public int compareTo(Board b) {		
		return b.h - this.h;//按照高度排序
	}	
}

public class Main{
	static final int MAX_VALUE = 100000000;
	static int[] leftMin;
	static int[] rightMin;	
	static Board[] boards;
	static int max;
	static int N;
	public static int min(int i,boolean isLeft){
		int x;
		int y = boards[i].h;
		if(isLeft)
			x = boards[i].lx;
		else
			x = boards[i].rx;
		int j;
		for(j=i+1;j<=N;j++){
			if(boards[j].lx <= x && boards[j].rx >= x)//下方有板子
				break;
		}
		if(j > N){//下方没有板子
			if(y > max)
				return MAX_VALUE;
			else 
				return y;
		}else{//因下方有板子而break了
			if(y - boards[j].h > max)
				return MAX_VALUE;
			else{
				if(leftMin[j] == -1)
					leftMin[j] = min(j,true);
				if(rightMin[j] == -1)
					rightMin[j] = min(j,false);
				return (y - boards[j].h) + Math.min(leftMin[j]+x-boards[j].lx, rightMin[j]+boards[j].rx-x);
			}
		}
			
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=0;i<T;i++){
			N = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			max = in.nextInt();
			leftMin = new int[N+1];
			rightMin = new int[N+1];	
			Arrays.fill(leftMin, -1);
			Arrays.fill(rightMin, -1);
			
			boards = new Board[N+1];
			boards[0] = new Board(x,x,y);
			for(int j=1;j<=N;j++){
				boards[j] = new Board(in.nextInt(),in.nextInt(),in.nextInt());
			}
			Arrays.sort(boards);
			System.out.println(min(0,true));			
		}
	}
}
