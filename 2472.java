//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {
 static int N = 100+5;

 static int n;
 static double Graph[][] = new double[N][N];
 public static void init(){
	int i,j;
	for(i=0;i< N;++i) for(j=0;j< N;++j)
		Graph[i][j] = 0.0;
 }

  public static void main(String args[]) throws Exception{

   double temp;
   int i,j,u,v,m;
   //Scanner cin = new Scanner(new FileInputStream("input.txt"));
   Scanner cin = new Scanner(System.in);

   while(cin.hasNext()){
	n = cin.nextInt();
	if(n==0) break;

	init();

	m = cin.nextInt();
	for(i=0;i< m;++i){
		u = cin.nextInt();
		v = cin.nextInt();
		temp = cin.nextDouble();
		Graph[v][u] = Graph[u][v] = temp/100.0;
	}

	temp = dijkstra()*100;
	System.out.printf("%.6f", temp);
	System.out.println(" percent");
   }
 }

  public static double dijkstra(){
    int i,j,k;
    boolean flag[] = new boolean[N];
    double meat[] = new double[N];

    for(i=1;i<=n;++i) {
	meat[i] = Graph[1][i];
	flag[i] = false;
    }
    flag[1] = true;

    for(i=0;i< n;++i){
	k = -1;
	for(j=1;j<=n;++j) if(!flag[j]){
		if(k==-1 || meat[k]< meat[j])
			k = j;
	}
	if(k==-1) break;
	flag[k] = true;

	for(j=1;j<=n;++j)if(!flag[j]){
		if(meat[j]< meat[k]*Graph[k][j])
			meat[j] = meat[k]*Graph[k][j];
	}
    }
    return meat[n];
  }
}

