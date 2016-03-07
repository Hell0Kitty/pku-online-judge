import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		while(run()==true)
			;
	}

	static boolean run(){
		int n = cin.nextInt();
		if(n==0)
			return false;

		Tree tree = new Tree(n, cin.next(), cin.next());
		System.out.println(tree.compute());
		return true;
	}
}


class Tree{
	static String preMap, postMap;
	static int M;

	static int[][] C;

	int preStart, postStart, length;

	public Tree(int M, String preMap, String postMap){
		this.M = M;
		this.preMap = preMap;
		this.postMap = postMap;

		C = new int[100][100];
		initialC();
		
		preStart = 0;
		postStart  = 0;
		length   = preMap.length();
	}
	public Tree(int preStart, int postStart, int length){
		this.preStart = preStart;
		this.postStart  = postStart;
		this.length = length;
	}

	ArrayList<Tree> subTree(){
		ArrayList<Tree> nodes = new ArrayList<Tree>();

		int start = preStart+1;
		int pEnd = postStart-1;
		int pstart, subLength;

		while(start<(preStart+length)){
			pstart = pEnd+1;
			pEnd  = postMap.indexOf(preMap.charAt(start));
			subLength = pEnd-pstart+1;

			nodes.add(new Tree(start, pstart, subLength));

			start = start+subLength;
		}


		return nodes;
	}

	int compute(){
		ArrayList<Tree> nodes = subTree();
		int count = C(M, nodes.size());
		for(Tree t:nodes)
			count *= t.compute();
		return count;
	}

	void initialC(){
		int i,j;
		for(i=0;i<100;i++)
			for(j=0;j<100;j++)
				C[i][j] = -1;

		for(i=0;i<100;i++){
			C[1][i] = (i>1? 0:1);
			C[i][0] = 1;
		}
	}

	int C(int n, int m){
		if(C[n][m] == -1)
			return C(n-1, m)+C(n-1, m-1);
		else
			return C[n][m];
	}


}
