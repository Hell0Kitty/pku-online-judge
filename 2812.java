import java.io.*;
import java.util.*;
class POINT{
	double x,y;
}
public class Main {
	static final int N = 100000;
	static POINT point[] = new POINT[N];
	static int n;
	static void start(){
		for(int i=0;i< N;++i) point[i] = new POINT();
	}
	static double Get_Num(StreamTokenizer cin) throws Exception{
		cin.nextToken();
		return cin.nval;
	}

public static void main(String[]args) throws Exception{
  int i;
  double V;
  start();
  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
  while(true){
		n = (int) Get_Num(cin);
		if(n< 3) break;
		for(i=0;i< n;++i){
			point[i].x = Get_Num(cin);
			point[i].y = Get_Num(cin);
		}
		V = Get_Num(cin);
		System.out.printf("BAR LENGTH: %.2f\n",solve(V));
	}
    }

 static double corss(POINT a,POINT b,POINT c){
		return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	}
	static double solve(double V){
		double ans=0.0;
		for(int i=2;i< n;++i){
			ans+=corss(point[0],point[i-1],point[i]);
		}
		ans = ans< 0.0?ans/-2.0:ans/2.0;
		return V/ans;
	}
}

