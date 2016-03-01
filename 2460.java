//* @author: ccQ.SuperSupper
import java.io.*;
class point{
	int x,y;
}
public class Main {
 static int n;
 static final int N = 200000+100;
 static point position[] = new point[N];

 public static void main(String[]args) throws Exception{

  int i;
  start();

  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
  while(true){
	n = Get_Num(cin);
	if(n<=0) break;
	for(i=0;i< n;++i){
		position[i].x = Get_Num(cin);
		position[i].y = Get_Num(cin);
	}
	solve();
  }
 }

 static void start(){
  for(int i=0;i< N;++i) position[i] = new point();
  }

  static void solve(){
  int i,x,y,ansa,ansb;
  ansa = ansb = 0;
  x = position[n/2].x;
  y = position[n/2].y;
  for(i=0;i< n;++i){
	if((position[i].x>x && position[i].y>y)||(position[i].x< x && position[i].y< y))
		++ansa;
	if((position[i].x>x && position[i].y< y)||(position[i].x< x && position[i].y>y))
		++ansb;
  }
  System.out.println(ansa+" "+ansb);
 }

 static int Get_Num(StreamTokenizer cin) throws Exception{
	cin.nextToken();
	return (int)cin.nval;
 }
}

