import java.io.*;
import java.util.*;
class Point{
	int x,y;
}
public class Main {
	
	static final int N = 100+10;
	static int n;
	static Point Area[] = new Point[N];
	static void start(){
		for(int i=0;i<N;++i)
			Area[i] = new Point();
	}
	public static void main(String []args) throws Exception{
		
		int t,cs=1,i,x,y;
		
		StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		//StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(new FileInputStream("input.txt"))));
		start();
		t = Get_Num(cin);
		while(t--!=0){
			n = Get_Num(cin);
			Area[0].x = Area[0].y = 0;
			for(i=1;i<=n;++i){
				Area[i].x = Get_Num(cin)+Area[i-1].x;
				Area[i].y = Get_Num(cin)+Area[i-1].y;
			}
			solve(cs++);
		}
	}
	static int Get_Num(StreamTokenizer cin) throws Exception{
		cin.nextToken();
		return (int) cin.nval;
	}
	static int GCD(int a,int b){
		if(b==0) return a;
		return GCD(b,a%b);
	}
	static int node_in_line(Point a,Point b){
		int x,y;
		x = abs(a.x-b.x);
		y = abs(a.y-b.y);
		return GCD(x,y);
	}
	static int abs(int a){
		if(a>=0) return a;
		return -a;
	}
	static int get_area(Point a,Point b,Point c){
		return (c.x-a.x)*(b.y-a.y) - (b.x-a.x)*(c.y-a.y);
	}
	static void solve(int cs){
		int I,E=0,area=0,i;
		for(i=0;i<n;++i){
			E+=node_in_line(Area[i],Area[(i+1)%n]);
		}
		for(i=2;i<n;++i){
			area += get_area(Area[0],Area[i-1],Area[i]);
		}
		area = abs(area);
		I = (area-E+2)/2;
		
		System.out.print("Scenario #"+cs+":\n"+I+" "+E+" ");
		if(area%2==0) System.out.println(area/2+".0\n");
		else System.out.println(area/2+".5\n");
	}
}
