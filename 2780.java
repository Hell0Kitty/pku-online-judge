//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
class Point implements Comparable {
	double x,y;
	public int compareTo(Object obj){
		Point temp = (Point) obj;
		if(temp.x!=this.x){
			if(temp.x< this.x) return 1;
			return -1;
		}
		if(temp.y< this.y) return 1;
		return -1;
	}
}
public class Main {
 static final int N = 1000+10;
 static int n;
 static double p[] = new double[N];
 static Point point[] = new Point[N];
 static void start(){
	for(int i=0;i< N;++i)
		point[i] = new Point();
}

public static void main(String[]args) throws Exception{
  int i;
  start();
  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

  while(cin.nextToken()!=StreamTokenizer.TT_EOF){
	n = (int) cin.nval;
	for(i=0;i< n;++i){
		cin.nextToken();
		point[i].x = cin.nval;
		cin.nextToken();
		point[i].y = cin.nval;
	}
	if(n<=2) System.out.println(n);
	else System.out.println(solve());
   }
}

public static int solve(){
 int i,j,k,cnt,ans=1;
 Arrays.sort(point,0,n);
 for(i=0;i< n;++i){
	for(k=0,j=i+1;j< n;++j){
		if(point[i].x==point[j].x)
			p[k++] = 10000000000.0;
		else
			p[k++] = (point[j].y-point[i].y)/(point[j].x-point[i].x);
	}
	Arrays.sort(p,0,k);
	cnt = 1;
	//for(j=0;j< k;++j) System.out.print(p[j]+" ");System.out.println();
	for(j=1;j< k;++j){
		if(p[j]==p[j-1])
			++cnt;
		else{
			ans = cnt>ans?cnt:ans;
			cnt = 1;
		}
	}
	ans = cnt>ans?cnt:ans;
  }
	return ans+1;
 }
}

