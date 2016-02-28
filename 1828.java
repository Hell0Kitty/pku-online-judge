import java.util.*;	//Monkeys' Pride

class node implements Comparable {
	int x,y;
	public int compareTo(Object o) {
        node oo=(node)o;
		if(this.x!=((node)o).x)
			return this.x>((node)o).x?1:0;
		return this.y>((node)o).y?1:0;
	}
}
public class Main{

	static int N = 500000+100;

	public static void main(String []args) throws Exception{
		int i,y,n,ans;
		node mokey[] = new node[N];
		for(i=0;i<N;++i)
			mokey[i] = new node();

		Scanner cin = new Scanner(System.in);

		while(cin.hasNext()){
			n = cin.nextInt();
			if(n==0) break;
			for(i=0;i<n;++i){
				mokey[i].x = cin.nextInt();
				mokey[i].y = cin.nextInt();
			}
			Arrays.sort(mokey,0,n);

			ans = 1; y = mokey[n-1].y;

			for(i=n-2;i>=0;--i){
				if(y<mokey[i].y){
					++ans;
					y = mokey[i].y;
				}
			}
			System.out.println(ans);
		}
	}
}
