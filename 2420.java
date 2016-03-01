//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
import java.math.*;
class Point{
	double x,y;
}
public class Main {
	static int n;
	static final int N = 100+10;
	static Point point[] = new Point[N];

	static void start(){
		for(int i=0;i< N;++i)
			point[i] = new Point();
	}

public static void main(String[]args) throws Exception{
 int i;
 double min;

 StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	start();
	while(true){
         cin.nextToken();
	 n = (int)cin.nval;
	 if(n<=0) break;
	  for(i=0;i< n;++i){
		cin.nextToken();
		point[i].x = cin.nval;
		cin.nextToken();
		point[i].y = cin.nval;
	  }
	min = best(point[n/2].x,point[n/2].y,n);
	System.out.printf("%.0f\n", min);
       }
  }

 static double f(double a,double b,double n){
  int i;
  double t = 0;
  for(i=0;i< n;++i){
     t+=Math.sqrt((point[i].x-a)*(point[i].x-a)+(point[i].y-b)*(point[i].y-b));
  }
  return t;
 }

  static double best(double a,double b,int n){
	int i,j=0,w=0;
	double T[] = new double[4],min;
	T[0] = f(a,b+1,n);
	T[1] = f(a+1,b,n);
	T[2] = f(a-1,b,n);
	T[3] = f(a,b-1,n);
	min = f(a,b,n);
	for(i=0;i< 4;++i){
		if(T[i]< min){
			w = 1;
			j = i;
			min = T[i];
		}
	}
	if(w!=0){
		if(j==0) min = best(a,b+1,n);
		else if(j==1) min = best(a+1,b,n);
		else if(j==2) min = best(a-1,b,n);
		else if(j==3) min = best(a,b-1,n);
	}
	return min;
  }

}

