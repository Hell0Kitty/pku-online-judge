import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	private static int[] sell;
	private static Node node;
 	public static boolean isSell(int d){

         if (sell[d] == 0) {
        	 sell[d] = d;
             return true;
         }  else{
        	 for(int i = d-1 ; i >= 1 ; i--){
        		 if(sell[i] == 0){
        			 sell[i] = d;
              		 return true;
        		 }
        	 }
         }
         return false;
	}
	
	public static int getProfix(List<Node> l , int n) {
	    int sum = 0;
	    sell = new int[n+1];
        for(int i = l.size()-1 ; i >=0 ; i--){
        	int d = l.get(i).getD();
        	if(isSell(d)){	
               sum = sum + l.get(i).getP();
        	}
        }
		return sum;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (sc.hasNextInt()) {

			int n = sc.nextInt();
			List<Node> l = new ArrayList<Node>();
			int max = 0;
			for(int i = 0 ;i < n ;i++){
				Main m = new Main();
				Main.node = m.new Node();
				int p = sc.nextInt();
				int d = sc.nextInt();
				node.setP(p);
				node.setD(d);
				if(d > max) max = d;
				l.add(node);
			}
           Collections.sort(l);
           System.out.println(Main.getProfix(l , max));
		}
	}
	class Node implements Comparable{

		private int p;
		private int d;
		public int getP() {
			return p;
		}
		public void setP(int p) {
			this.p = p;
		}
		public int getD() {
			return d;
		}
		public void setD(int d) {
			this.d = d;
		}
		public int compareTo(Object o) {
			Node node = (Node)o;
			if (this.p > node.p){
				return 1;
			}else if(this.p < node.p){
				return -1;
			}else{
				return 1;
			}
		}
		
	}
}

