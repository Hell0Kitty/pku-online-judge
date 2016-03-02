import java.io.*;
import java.util.*;
class Point{
	int x,y;
}
public class Main {

	static Point triangle[] = new Point[3];
	static int GCD(int a,int b){
		if(b==0) return a;
		return GCD(b,a%b);
	}
	static int area(Point a,Point b,Point c){
		return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
	}
	static int solve(){
		int ans=0,i=0;
		int area = area(triangle[0],triangle[1],triangle[2]);
		i += node_in_line(triangle[0],triangle[1]);
		i += node_in_line(triangle[1],triangle[2]);
		i += node_in_line(triangle[0],triangle[2]);
		if(area< 0) area = -area;
		ans = (area-i+2)/2;
		return ans;
	}
	static int node_in_line(Point a,Point b){
		int x,y;
		x = a.x-b.x;
		if(x< 0) x = -x;
		y = a.y-b.y;
		if(y< 0) y = -y;
		if(x==0) return y;
		if(y==0) return x;
		return GCD(x,y);
	}
	public static void main(String[]args) throws Exception{

		int i,j;
		//Scanner cin = new Scanner(new FileInputStream("input.txt"));
		Scanner cin = new Scanner(System.in);
		for(i=0;i< 3;++i) triangle[i] = new Point();
		while(true){
			for(i=j=0;i< 3;++i){
				triangle[i].x = cin.nextInt();
				triangle[i].y = cin.nextInt();
				if(triangle[i].x!=0) j=1;
				if(triangle[i].y!=0) j=1;
			}
			if(j==0) break;

			System.out.println(solve());
		}
	}
}

